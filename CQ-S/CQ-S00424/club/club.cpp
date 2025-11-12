#include <bits/stdc++.h>
using namespace std;
const int MAXN=40;
int dp[MAXN][MAXN][MAXN][MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n/2 && j<=i;j++)
			{
				for(int k=0;k+j<=i && k<=n/2;k++)
				{
					for(int x=0;k+j+x<=i && x<=n/2;x++)
					{
						if(j>=1) dp[i][j][k][x]=max(dp[i][j][k][x],dp[i-1][j-1][k][x]+a[i]);
						if(k>=1) dp[i][j][k][x]=max(dp[i][j][k][x],dp[i-1][j][k-1][x]+b[i]);
						if(x>=1) dp[i][j][k][x]=max(dp[i][j][k][x],dp[i-1][j][k][x-1]+c[i]);
//						cout<<j<<" "<<k<<" "<<x<<" "<<dp[i][j][k][x]<<endl;
					}
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k+j<=n;k++)
			{
				int x=n-j-k;
				ans=max(ans,dp[n][j][k][x]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

