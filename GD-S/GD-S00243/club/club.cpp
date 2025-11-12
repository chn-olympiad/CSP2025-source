#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int dp[35][35][35][35],d[205][105][105];
struct clubb{
	int ab;
	int bb;
	int cb;
	int sizee;
}c[100005];
bool cmp1(clubb x,clubb y)
{
	return x.ab<y.ab;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		int ts1=0,ts2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i].ab>>c[i].bb>>c[i].cb;
			c[i].sizee=i;
			if(c[i].bb==c[i].cb&&c[i].bb==0)
			{
				ts1++;
			}
			if(c[i].cb==0)
			{
				ts2++;
			}
		}
		if(ts1==n)
		{
			sort(c+1,c+n+1,cmp1);
			for(int i=n;i>=n/2+1;i--)
			{
				ans+=c[i].ab;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(ts2==n)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						d[i][j][k]=d[i-1][j][k];
						if(j-1>=0) d[i][j][k]=max(d[i][j][k],d[i-1][j-1][k]+c[i].ab);
						if(k-1>=0) d[i][j][k]=max(d[i][j][k],d[i-1][j][k-1]+c[i].bb);
					}
				}
			}
			cout<<d[n][n/2][n/2]<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					for(int e=0;e<=n/2;e++)
					{
						dp[i][j][k][e]=dp[i-1][j][k][e];
						if(j-1>=0) dp[i][j][k][e]=max(dp[i][j][k][e],dp[i-1][j-1][k][e]+c[i].ab);
						if(k-1>=0) dp[i][j][k][e]=max(dp[i][j][k][e],dp[i-1][j][k-1][e]+c[i].bb);
						if(e-1>=0) dp[i][j][k][e]=max(dp[i][j][k][e],dp[i-1][j][k][e-1]+c[i].cb);
					}
				}
			}
		}
		cout<<dp[n][n/2][n/2][n/2]<<'\n';
	}
	return 0;
}
