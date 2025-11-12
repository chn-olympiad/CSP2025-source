#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int dp[50][50][50][50],a[100][3];
void solov()
{
	memset(dp,-0x3f,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	dp[0][0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int f1=0;f1<=min(i,n/2);f1++)
		{
			for(int f2=0;f2<=min(i,n/2);f2++)
			{
				for(int f3=0;f3<=min(i,n/2);f3++)
				{
					if(!f1&&!f2&&!f3)continue;
					if(f1)dp[i][f1][f2][f3]=max(dp[i][f1][f2][f3],dp[i-1][f1-1][f2][f3]+a[i][1]);
					if(f2)dp[i][f1][f2][f3]=max(dp[i][f1][f2][f3],dp[i-1][f1][f2-1][f3]+a[i][2]);
					if(f3)dp[i][f1][f2][f3]=max(dp[i][f1][f2][f3],dp[i-1][f1][f2][f3-1]+a[i][3]);
				}
			}
		}
	}
	int maxn=-2e9;
	for(int i=0;i<=n/2;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			int k=n-i-j;
			maxn=max(maxn,dp[n][i][j][k]);
		}
	}
	printf("%d\n",maxn);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)solov();
	return 0;
}
