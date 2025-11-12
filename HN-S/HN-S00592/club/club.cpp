#include<bits/stdc++.h>
using namespace std;
int T,n;
long long a[3][100005],dp[205][205][205];
void solve()
{
	cin>>n;
	bool fa=1,fb=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		{
			cin>>a[j][i];
		}
		fa&=(a[1][i]==0);
		fb&=(a[2][i]==0);
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=min(n/2,i);j>=0;j--)
		{
			for(int k=min(n/2,i);k>=0;k--)
			{
				int t=i-j-k;
				if(t>n/2||t<0)continue;
				if(j>0)dp[j][k][t]=max(dp[j-1][k][t]+a[0][i],dp[j][k][t]);
				if(k>0)dp[j][k][t]=max(dp[j][k-1][t]+a[1][i],dp[j][k][t]);
				if(t>0)dp[j][k][t]=max(dp[j][k][t-1]+a[2][i],dp[j][k][t]);
			}
		}
	}
	long long ans=0;
	for(int c1=0;c1<=n/2;c1++)
	{
		for(int c2=0;c2<=n/2;c2++)
		{
			int c3=n-c1-c2;
			if(c3>n/2)continue;
			ans=max(ans,dp[c1][c2][c3]);
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
