#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[500010],sum[500010];
ll dp[500010];
ll ans;
unordered_map<ll,ll> vis;
unordered_map<ll,ll> maxn;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	vis[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		sum[i]=a[i]^sum[i-1];
		ll need=sum[i]^k;
		if(vis[need]==1)
			dp[i]=1+maxn[need];
		vis[sum[i]]=1;
		dp[i]=max(dp[i],dp[i-1]);
		maxn[sum[i]]=max(maxn[sum[i]],dp[i]);
	}
	cout<<dp[n];
	return 0;
}
