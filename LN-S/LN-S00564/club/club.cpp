#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long a,b,c;
}f[100010];
long long dp[100010][3];
long long vis[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	for(long long i=1;i<=t;i++)
	{
		long long n;
		scanf("%lld",&n);
		long long mx=n/2;
		for(long long j=1;j<=n;j++)
		{
			scanf("%lld%lld%lld",&f[j].a,&f[j].b,&f[j].c);
		}
		for(long long j=1;j<=n;j++)
		{
			for(long long k=1;k<=3;k++)
			{
				if(vis[k]+1>mx)
				{
					if(k==1)
					{
						dp[j][1]=max(dp[j-1][1],max(dp[j-1][2],dp[j-1][3])+f[j].a);
					}
					else if(k==2)
					{
						dp[j][2]=max(dp[j-1][2],max(dp[j-1][1],dp[j-1][3])+f[j].b);
					}
					else
					{
						dp[j][3]=max(dp[j-1][3],max(dp[j-1][2],dp[j-1][1])+f[j].c);
					}
				}
				else
				{
					vis[k]++;
					dp[j][k]=max(dp[j-1][1],max(dp[j-1][2],dp[j-1][3]));
					if(k==1)
					{
						dp[j][k]+=f[j].a;
					}
					else if(k==2)
					{
						dp[j][k]+=f[j].b;
					}
					else
					{
						dp[j][k]+=f[j].c;
					}
				}
			}
		}
		long long ret=0;
		for(long long j=1;j<=3;j++)
		{
			ret=max(ret,dp[n][j]);
		}
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		printf("%lld\n",ret);
	}
	return 0;
}
