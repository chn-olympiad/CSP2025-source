#include <bits/stdc++.h>
using namespace std;
long a[1010],n,m,c,r,dp[15][15],pl;
void f()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j==1)
			{
				dp[i][j]=i;
			}
			else if(i==1)
			{
				if(j%2==0)
				{
					dp[i][j]=dp[i][j-1]+2*(n-1)+1;
				}
				else
				{
					dp[i][j]=dp[i][j-1]+1;
				}
			}
			else if(i==m)
			{
				if(j%2==0)
				{
					dp[i][j]=dp[i][j-1]+1;
				}
				else
				{
					dp[i][j]=dp[i][j-1]+2*(n-1)+1;
				}
			}
			else if(j%2==0)
			{
				dp[i][j]=dp[i+1][j]+1;
			}
			else
			{
				dp[i][j]=dp[i-1][j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(pl==dp[i][j])
			{
				c=j,r=i;
			}
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for(long i=1;i<=n*m;i++)
	{
		scanf("%ld",&a[i]);
	}
	long x=a[1];
	sort(a+1,a+n*m+1);
	printf("\n");
	for(long i=1;i<=n*m;i++)
	{
		if(x==a[i])
		{
			pl=n*m-i+1;
		}
	}
	f();
	printf("%ld %ld",c,r);
	
	return 0;
}