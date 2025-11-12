#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int dp[5005][5005],a[5005];
int dpp[505][50005];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=50000;j++) dpp[i][j]=dpp[i-1][j]; 
			dpp[i][a[i]]++;
			for(int j=50000;j>=a[i];j--)
				(dpp[i][j]+=dpp[i-1][j-a[i]])%=mod;
		}
		for(int i=1;i<=n;i++)
			for(int j=a[i]+1;j<=50000;j++)
				(ans+=dpp[i-1][j])%=mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			dp[i][a[i]]=1;
			continue;
		}
		for(int j=0;j<=5000;j++) dp[i][j]=dp[i-1][j];
		(dp[i][a[i]]+=1)%=mod;
		for(int j=a[i];j<=5000;j++)
			(dp[i][j]=dp[i][j]+dp[i-1][j-a[i]])%mod;
		for(int j=5000;j>=5001-a[i];j--)
			(dp[i][5001]+=dp[i-1][j])%=mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=5001;j++)
			(ans+=dp[i-1][j])%=mod;
		for(int j=1;j<i-1;j++)
			(ans+=dp[j][5001])%=mod;
	}
	cout<<ans;
	return 0;
}
