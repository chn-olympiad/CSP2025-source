#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=5e3+10;
const ll mod=998244353;

int n,p[N]; ll ans,dp[N<<2];

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n; dp[0]=1;
	for(int i=1;i<=n;++i) cin>>p[i];
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=p[i]+1;j<=5001;++j) ans=(ans+dp[j])%mod;
		for(int j=5001;j>=0;--j)
			dp[min(j+p[i],5001)]=(dp[min(j+p[i],5001)]+dp[j])%mod;
	}
	cout<<ans;
	return 0;
}