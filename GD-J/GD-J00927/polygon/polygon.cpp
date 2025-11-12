#include<bits/stdc++.h>
using namespace std;
const int maxn=5010,mod=998244353;
int n,ans;
int a[maxn],dp[maxn][maxn],sum[maxn];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0][0]=1ll;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+sum[a[i]+1])%mod;
		for(int j=0;j<=5001;j++) dp[i][j]=dp[i-1][j];
		for(int j=5001;j>=0;j--) dp[i][min(j+a[i],5001)]=(dp[i][min(j+a[i],5001)]+dp[i-1][j])%mod;
		for(int j=5001;j>=0;j--) sum[j]=(sum[j+1]+dp[i][j])%mod;
	}
	cout<<ans;
	return 0;
}
