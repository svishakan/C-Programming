/*
5. Modify the program shown in Example 10.30 (compound interest calculations) (Page 11.44) of
text book (Byron Gottfried) so that it generates a table of F-values for various time periods,
using different compounding frequencies. Assume that A and n are input values. Display the
output in the following manner.
A = . . .
i = . . .
Interest rate = 5% 6% 7% 8% 9% 10% 11% 12% 13% 14% 15%
Frequency of
Compounding
Annual --- --- --- --- --- --- --- --- --- --- ---
Semiannual --- --- --- --- --- --- --- --- --- --- ---
Quarterly --- --- --- --- --- --- --- --- --- --- ---
Monthly --- --- --- --- --- --- --- --- --- --- ---
Daily --- --- --- --- --- --- --- --- --- --- ---
Continuously --- --- --- --- --- --- --- --- --- --- ---
Notice that the first four rows are generated by one function with different arguments, and each of
the last two rows is generated by a different function.
a. Repeat the previous problem, but transpose the table so that each row represents a different
value for n and each column represents a different compounding frequency. Consider
integer values of n ranging from 1 to 50. Note that this table will consist of 50 rows and 6
columns. (Hint: Generate the table by columns, storing each column in a two-dimensional
array. Display the entire array after all the values have been generated.)
b. Compare the programming effort required for this problem with the programming effort
required for the preceding problem.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void table(double (*pf)(double i, int m, double n),double a, int m, double n,double r);
double md1(double i, int m, double n);
double md2(double i, int m, double n);
double md3(double i, int m, double n);
void main(){
	int m,count,cpd;
	double n,a,r;
	char freq;
	printf("\nFuture Value of a series of Monthly Deposits.\n");
	printf("Enter the amount of each monthly payment: ");
	scanf("%lf",&a);
	printf("\nEnter the rate of interest: ");
	scanf("%lf",&r);
	for (count = 0; count <= 50; ++count) {
		if(count==0)
			printf("\nNo. of Years\tAnnual       Semi-Annual       Quarterly       Monthly       Daily       Continuous\n");
		else{
			printf("%d\t",count);
			for(cpd=1;cpd<=6;cpd++){
				switch(cpd){
					case 1:
						m=1;
						table(md1,a,m,count,r);
						break;
					case 2:
						m=2;
						table(md1,a,m,count,r);
						break;
					case 3:
						m=4;
						table(md1,a,m,count,r);
						break;
					case 4:
						m=12;
						table(md1,a,m,count,r);
						break;
					case 5:
						m=360;
						table(md2,a,m,count,r);
						break;
					case 6:
						m=0;
						table(md3,a,m,count,r);
						break;
			}	
			}
			printf("\n");
		}
	
	}
}
	
void table(double (*pf)(double i, int m, double n), double a, int m, double n,double r)
// table generator (this function accepts a pointer to another function as an argument)
{
	double i; //annual interest rate
	double f; //future value
			i= 0.01 *r;
			f = a * (*pf)(i, m, n);/* ACCESS THE FUNCTION PASSED AS A POINTER */
			printf("\t      %.2f",f);
	
}

double md1(double i, int m, double n)
/* monthly deposits, periodic compounding */
	{
	double factor, ratio;
	factor = 1 + i/m;
	ratio = 12 * (pow(factor, m*n) - 1) / i;
	return(ratio);
	}

double md2(double i,int m, double n)
/* monthly deposits, daily compounding */
	{
	double factor, ratio;
	factor = 1 + i/m;
	ratio = (pow(factor, m*n) - 1) / (pow(factor, m/12) - 1);
	return(ratio);
	} 

double md3(double i,int dummy, double n)
/* monthly deposits, continuous compounding */
	{
	double ratio;
	ratio = (exp(i*n) - 1) / (exp(i/12) - 1);
	return(ratio); 
	}
	
/*
[root@sel-25 196 CSE C]# ./c

Future Value of a series of Monthly Deposits.
Enter the amount of each monthly payment: 1

Enter the rate of interest: 1

No. of Years	Annual       Semi-Annual       Quarterly       Monthly       Daily       Continuous
1		      12.00		      12.03			     12.05		  12.06		      12.06		      12.06
2		      24.12		      24.18			     24.21		  24.23		      24.23		      24.23
3		      36.36		      36.45			     36.50		  36.53		      36.53		      36.53
4		      48.72		      48.85			     48.91		  48.95		      48.95		      48.95
5		      61.21		      61.37			     61.45		  61.50		      61.50		      61.50
6		      73.82		      74.01			     74.11		  74.17		      74.17		      74.17
7		      86.56		      86.79			     86.90		  86.97		      86.97		      86.97
8		      99.43		      99.69			     99.81		  99.90		      99.90		      99.90
9		      112.42	      112.71		     112.86	      112.96	      112.96	      112.96
10		      125.55	      125.87		     126.04	      126.15	      126.15	      126.15
11		      138.80	      139.17		     139.35	      139.47	      139.48	      139.48
12		      152.19	      152.59	    	 152.79	      152.93	      152.93	      152.93
13		      165.71	      166.15	     	 166.37	      166.52	      166.52	      166.52
14		      179.37	      179.85	     	 180.09	      180.25	      180.25	      180.25
15		      193.16	      193.68	     	 193.94	      194.11	      194.12	      194.12
16		      207.09	      207.65	     	 207.93	      208.12	      208.13	      208.13
17		      221.17	      221.76	     	 222.06	      222.27	      222.27	      222.27
18		      235.38	      236.02	     	 236.34	      236.55	      236.56	      236.56
19		      249.73	      250.41	     	 250.76	      250.98	      250.99	      250.99
20		      264.23	      264.95	     	 265.32	      265.56	      265.57	      265.57
21		      278.87	      279.64	     	 280.03	      280.28	      280.30	      280.30
22		      293.66	      294.47	     	 294.88	      295.16	      295.17	      295.17
23		      308.60	      309.45	     	 309.89	      310.18	      310.19	      310.19
24		      323.68	      324.59	     	 325.04	      325.35	      325.36	      325.36
25		      338.92	      339.87	     	 340.35	      340.67	      340.69	      340.69
26		      354.31	      355.31	     	 355.81	      356.15	      356.17	      356.17
27		      369.85	      370.90	     	 371.43	      371.78	      371.80	      371.80
28		      385.55	      386.65	     	 387.20	      387.57	      387.59	      387.59
29		      401.40	      402.55	     	 403.13	      403.52	      403.54	      403.54
30		      417.42	      418.62	     	 419.22	      419.63	      419.65	      419.66
31		      433.59	      434.85	     	 435.48	      435.90	      435.93	      435.93
32		      449.93	      451.24	     	 451.89	      452.33	      452.36	      452.36
33		      466.43	      467.79	     	 468.47	      468.93	      468.97	      468.97
34		      483.09	      484.51	     	 485.22	      485.70	      485.73	      485.73
35		      499.92	      501.40	     	 502.14	      502.63	      502.67	      502.67
36		      516.92	      518.45	     	 519.22	      519.74	      519.78	      519.78
37		      534.09	      535.68	     	 536.48	      537.01	      537.06	      537.06
38		      551.43	      553.08	     	 553.91	      554.46	      554.51	      554.51
39		      568.95	      570.66	     	 571.51	      572.09	      572.14	      572.14
40		      586.64	      588.41	     	 589.30	      589.89	      589.94	      589.94
41		      604.50	      606.34	     	 607.26	      607.87	      607.93	      607.93
42		      622.55	      624.44	     	 625.40	      626.03	      626.09	      626.09
43		      640.77	      642.73	     	 643.72	      644.38	      644.44	      644.44
44		      659.18	      661.21	     	 662.23	      662.91	      662.97	      662.97
45		      677.77	      679.87	     	 680.92	      681.62	      681.69	      681.69
46		      696.55	      698.71	     	 699.80	      700.52	      700.59	      700.60
47		      715.52	      717.75	     	 718.87	      719.62	      719.69	      719.69
48		      734.67	      736.97	     	 738.13	      738.90	      738.98	      738.98
49		      754.02	      756.39	   	 	 757.58	      758.38	      758.46	      758.46
50		      773.56	      776.00	     	 777.23	      778.05	      778.14	      778.14
*/