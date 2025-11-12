#include <bits/stdc++.h>
using namespace std;
int s[500001];
long long z[1001][1001];
int p[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m=0;
	long long x=1,y=1,f=0;
	scanf("%d%d",&n,&k);
	while (k!=0)
	{
		f+=k%2*x;
		k/=2;
		x*=10;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	if  (n<=1000)
	{
		for (int i=n;i>=1;i--)
		{
			x=1;
			while (s[i]!=0)
			{
				z[i][i]+=s[i]%2*x;
				s[i]/=2;
				x*=10;
			}
			for (int j=i+1;j<=n;j++)
			{
				z[i][j]=z[i][j-1]+z[i+1][j];
				y=1;
				while (z[i][j]>y)
				{
					if (z[i][j]/y%10==2)
					z[i][j]-=2*y;
					y*=10;
				}
			}
		}
		for (int j=1;j<=n;j++)
		{
			for (int i=j;i>=1;i--)
			{
				if (z[i][j]==f)
				{
					if (m==0 || p[m]<i)
					{
						m++;
						p[m]=j;
					}
				}
			}
		}
	}
	printf("%d",m);
	return 0;
}
