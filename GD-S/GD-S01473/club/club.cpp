#include<iostream>
#include<cstdio>
#include<cstring>
#define N 205
using namespace std;
int T,n;
int ans;
int a[N][3];
int dp[N][N][N];
void work()
{
	ans=0;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	for(int i=1;i<=n;i++)
		for(int j=min(n/2,i);j>=0;j--)
			for(int k=min(n/2,i-j);k>=0&&i-k-j<=n/2;k--)
			{
				if(i-j-k!=0)dp[i-j-k][j][k]=max(dp[i-j-k][j][k],dp[i-j-k-1][j][k]+a[i][0]);
				if(j!=0)dp[i-j-k][j][k]=max(dp[i-j-k][j][k],dp[i-j-k][j-1][k]+a[i][1]);
				if(k!=0)dp[i-j-k][j][k]=max(dp[i-j-k][j][k],dp[i-j-k][j][k-1]+a[i][2]);
				//printf("dp[%d][%d][%d]=%d\n",i-j-k,j,k,dp[i-j-k][j][k]);
			}
	for(int i=0;i<=n/2;i++)
		for(int j=n/2-i;j<=n/2;j++)
			ans=max(ans,dp[i][j][n-i-j]);
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)work();
}
