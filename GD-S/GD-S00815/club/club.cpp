#include <bits/stdc++.h>
using namespace std;
long long t,n,a[1005][4],dp[1000005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int z=0;z<t;z++)
	{
		long long an1=0,an2=0,an3=0,an4=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=3;j++)
			{
				a[i][j]=0;
			}
		}
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		for(int i=0;i<n;i++)
		{
			int l=0;
			dp[i]=a[i][0];
			for(int j=1;j<3;j++)
			{
				if(a[i][j]>dp[i])
				{
					dp[i]=a[i][j];
					l=j;
				}
			}
			if(l==0)
			{
				an1++;
			}else if(l==1)
			{
				an2++;
			}else 
			{
				an3++;
			}
		}
		for(int i=0;i<n;i++)
		{
			an4+=dp[i];
		}
		/*if(an1>n/2)
		{
			for(int i=0;i<n;i++)
			{
				for(int i=0;)
			}
		}else if(an2>n/2)
		{
			
		}else if(an3>n/2)
		{
			
		}*/
		printf("%lld\n",an4);
	}
	return 0;
}
