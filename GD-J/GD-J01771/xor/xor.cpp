#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
ll dp[MAXN],vis[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		t^=a;
		dp[i]=dp[i-1];
		if(vis[t^m]||!(t^m))
		{
			dp[i]=max(dp[i],dp[vis[t^m]]+1);
		}
		vis[t]=i;
	}
	cout<<dp[n];
	return 0;
}
