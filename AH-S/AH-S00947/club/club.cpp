#include <bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[1000005],c[100005],num = 0,A[100005],B[100005],C[100005];
char o[100005],tt[100005],ttt[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1;i<=t;i++)
	{
		cin >> n;
		num = n / 2;
		long long one = 0,two = 0,three = 0;
		for (int j = 1;j<=n;j++)
		{
			cin >> a[j] >> b[j] >> c[j];
			if(a[j] >= b[j] && b[j] >= c[j])
			{
				o[j] = 'a';
				tt[j] = 'b';
				ttt[j] = 'c'; 
			}
			else if (a[j] >= c[j] && c[j] >= b[j])
			{
				o[j] = 'a';
				tt[j] = 'c';
				ttt[j] = 'b';
			}
			else if (b[j] >= a[j] && a[j] >= c[j])
			{
				o[j] = 'b';
				tt[j] = 'a';
				ttt[j] = 'c';
			}
			else if (b[j] >= c[j] && c[j] >= a[j])
			{
				o[j] = 'b';
				tt[j] = 'c';
				ttt[j] = 'a';
			}
			else if (c[j] >= a[j] && a[j] >= b[j])
			{
				o[j] = 'c';
				tt[j] = 'a';
				ttt[j] = 'b';
			}
			else if (c[j] >= b[i] && b[j] >= a[j])
			{
				o[j] = 'c';
				tt[j] = 'b';
				ttt[j] = 'a';
			}
		}
		long long q = 1,w = 1,e = 1;
		if (o[1] == 'a')
		{
			A[q] = 1;
			one += a[1];
		}
		else if (o[1] == 'b')
		{
			B[w] = 1;
			two += b[1];
		}
		else
		{
			C[e] = 1;
			three += c[1];
		}
		for (int j = 2;j<=n;j++)
		{
			if (o[j] == 'a')
			{
				if (q < num)
				{
					q += 1;
					A[q] = j;
					one += a[j];
					for (int s = 1;s < q;s++)
					{
						for (int d = 1;d < s;d++)
						{
							if (a[A[d]] <= a[A[d + 1]])
							{
								int f = a[A[d]];
								a[A[d]] = a[A[d + 1]];
								a[A[d + 1]] = f;
							}
						}
					}
				}
				else if (q == num)
				{
					if (a[j] > a[A[q]])
					{
						one = one - a[A[q]] + a[j];
						A[q] = j;
						for (int s = 1;s < q;s++)
						{
							for (int d = 1;d < s;d++)
							{
								if (a[A[d]] <= a[A[d + 1]])
								{
									int f = a[A[d]];
									a[A[d]] = a[A[d + 1]];
									a[A[d + 1]] = f;
								}
							}
						}
						
					}
				}
			}
			else if (o[j] == 'b')
			{
				if (w < num)
				{
					w += 1;
					B[w] = j;
					two += b[j];
					for (int s = 1;s < w;s++)
					{
						for (int d = 1;d < s;d++)
						{
							if (b[B[d]] <= b[B[d + 1]])
							{
								int f = b[B[d]];
								b[B[d]] = b[B[d + 1]];
								b[B[d + 1]] = f;
							}
						}
					}
				}
				else if (w == num)
				{
					if (b[j] > b[B[w]])
					{
						two = two - b[B[w]] + b[j];
						A[w] = j;
						for (int s = 1;s < w;s++)
						{
							for (int d = 1;d < s;d++)
							{
								if (b[B[d]] <= b[B[d + 1]])
								{
									int f = b[B[d]];
									b[B[d]] = b[B[d + 1]];
										b[B[d + 1]] = f;
								}
							}
						}
						
					}
				}
			}
			else if (o[j] == 'c')
			{
				if (e < num)
				{
					e += 1;
					C[e] = j;
					three += c[j];
					for (int s = 1;s < e;s++)
					{
						for (int d = 1;d < s;d++)
						{
							if (c[C[d]] <= c[C[d + 1]])
							{
								int f = c[C[d]];
								c[C[d]] = c[C[d + 1]];
								c[C[d + 1]] = f;
							}
						}
					}
				}
				else if (e == num)
				{
					if (c[j] > c[C[e]])
					{
						three = three - c[C[e]] + c[j];
						C[e] = j;
						for (int s = 1;s < e;s++)
						{
							for (int d = 1;d < s;d++)
							{
								if (c[C[d]] <= c[C[d + 1]])
								{
									int f = c[C[d]];
									c[C[d]] = c[C[d + 1]];
									c[C[d + 1]] = f;
								}
							}
						}
						
					}
				}
			}
		}
		cout << one + two + three << endl;
	}	
	return 0;
}
