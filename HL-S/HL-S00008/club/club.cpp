#include <bits/stdc++.h>
using namespace std;
int t,n;
int b,c,d,sum,sum1,sum2,sum3;
//bool ff;
int maxx,max1,M;
//int maxxx[10005];
struct A
{
	int a1,a2,a3;
	bool f1,f2,f3;
}a[10005];
bool cmp1(A a,A b)
{
	return a.a1 > b.a1;
}
bool cmp2(A a,A b)
{
	return a.a2 > b.a2;
}
bool cmp3(A a,A b)
{
	return a.a3 > b.a3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int z = 1;z <= t;z++)
	{
		cin >> n;
		M = n / 2;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			maxx = max(max(a[i].a1,a[i].a2),a[i].a3);
			if(a[i].a1 == maxx)
			{
				b++;
				a[i].f1 = 1;
				sum1 += a[i].a1;
			}
			if(a[i].a2 == maxx)
			{
				c++;
				a[i].f2 = 1;
				sum2 += a[i].a2;
			}
			if(a[i].a3 == maxx)
			{
				d++;
				a[i].f3 = 1;
				sum3 == a[i].a3;
			}
			
		}
		/*if(n <= 3)
		{
			for(int i = 1;i <= n;i++)
			{
				if((a[i].a1 == 0 && a[i].a2 == 0) || (a[i].a1 == 0 && a[i].a3 == 0) || (a[i].a3 == 0 && a[i].a2 == 0))
				{
					ff = 1;
					int kk = i;
				}
				
			}
			for(int i = 1;i <= n;i++)
			{
				int maxxx[i] = maxx[i] - min(min(a[i].a1,a[i].a2),a[i].a3);
			}
		}*/
		if(b <= M && c <= M && d <= M)
		{
			for(int i = 1;i <= n;i++)
			{
				if(a[i].f1)
				{
					sum += a[i].a1;
				}
				else if(a[i].f2)
				{
					sum += a[i].a2;
				}
				else if(a[i].f3)
				{
					sum += a[i].a3;
				}
			}
			cout << sum << endl;
		}
		else
		{
			max1 = max(max(sum1,sum2),sum3);
			if(sum1 == max1)
			{
				sort(a+1,a+n+1,cmp1);
				for(int i = 1;i <= M;i++)
				{
					sum += a[i].a1;
					if(a[i].f2)
					{
						c--;
					}
					if(a[i].f3)
					{
						d--;
					}
					
					sum2 -= a[i].a2;
					sum3 -= a[i].a3;
				}
				if(sum2 > sum3)
				{
					sort(a+M+1,a+n+1,cmp2);
					for(int i = M+1;i <= M+c;i++)
					{
						sum += a[i].a2;
					}
					for(int i = M+c+1;i <= n;i++)
					{
						sum += a[i].a3;
					}
				}
				else
				{
					sort(a+M+1,a+n+1,cmp3);
					for(int i = M+1;i <= M+d;i++)
					{
						sum += a[i].a3;
					}
					for(int i = M+d+1;i <= n;i++)
					{
						sum += a[i].a2;
					}
				}
			}
			if(sum2 == max1)
			{
				sort(a+1,a+n+1,cmp2);
				for(int i = 1;i <= M;i++)
				{
					sum += a[i].a2;
					if(a[i].f1)
					{
						b--;
					}
					if(a[i].f3)
					{
						d--;
					}
					
					sum1 -= a[i].a1;
					sum3 -= a[i].a3;
				}
				if(sum1 > sum3)
				{
					sort(a+M+1,a+n+1,cmp1);
					for(int i = M+1;i <= M+b;i++)
					{
						sum += a[i].a1;
					}
					for(int i = M+b+1;i <= n;i++)
					{
						sum += a[i].a3;
					}
				}
				else
				{
					sort(a+M+1,a+n+1,cmp3);
					for(int i = M+1;i <= M+d;i++)
					{
						sum += a[i].a3;
					}
					for(int i = M+d+1;i <= n;i++)
					{
						sum += a[i].a1;
					}
				}
			}
			if(sum3 == max1)
			{
				sort(a+1,a+n+1,cmp3);
				for(int i = 1;i <= M;i++)
				{
					sum += a[i].a3;
					if(a[i].f2)
					{
						c--;
					}
					if(a[i].f1)
					{
						b--;
					}
					
					sum2 -= a[i].a2;
					sum1 -= a[i].a1;
				}
				if(sum2 > sum1)
				{
					sort(a+M+1,a+n+1,cmp2);
					for(int i = M+1;i <= M+c;i++)
					{
						sum += a[i].a2;
					}
					for(int i = M+c+1;i <= n;i++)
					{
						sum += a[i].a1;
					}
				}
				else
				{
					sort(a+M+1,a+n+1,cmp1);
					for(int i = M+1;i <= M+b;i++)
					{
						sum += a[i].a1;
					}
					for(int i = M+b+1;i <= n;i++)
					{
						sum += a[i].a2;
					}
				}
			}
			cout << sum << endl;
		}
		b=0;
		c=0;
		d=0;
		max1=0;
		maxx = 0;
		sum = 0;
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
	}
	return 0;
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
