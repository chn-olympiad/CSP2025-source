#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 5005;
ll w[maxn];
ll pre[maxn];
ll n,ans;
ll dp[maxn][maxn];
ll m;
const ll mod = 998244353;
void readin() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i<=n; ++i)cin>>w[i];
	sort(w+1,w+n+1);
	m = w[n];
	for(int i = 1; i<=n; ++i)pre[i] = pre[i-1] + w[i];
	return;
}
ll qp(ll x) {
	ll ans(1);
	ll bse(2);
	while(x) {
		if(x&1) ans = (ans * bse) %mod;
		bse = (bse * bse) % mod;
		x >>= 1;
	}
	return ans;
}
void solve() {
	for(int i = 1; i<=m; ++i)for(int j = 1; j<n; ++j) {
			if(w[j] < i) {
				if(dp[j-1][i])dp[j][i] = dp[j-1][i] + dp[j-1][i-w[j]];
				else if(pre[j] > i) dp[j][i]=max<ll>(dp[j-1][i-w[j]],1);
			} else {
				dp[j][i] = (dp[j-1][i] + qp(j-1));
				if(w[j]==i)dp[j][i] += (mod-1);
			}
				while(dp[j][i]>=mod)dp[j][i] -= mod;
		}
	for(int i = 3; i<=n; ++i)ans += dp[i-1][w[i]];
	while(ans >= mod) ans -= mod;
	cout<<ans;
}
int main() {
	readin();
	solve();
}
//5 1 2 3 4 5
