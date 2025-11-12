#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll n;
ll pw[5005], a[5005], dp[5005][5005], ans;

ll read(){
	ll ret = 0LL;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) ret = ret * 10 + (c ^ 48), c = getchar();
	return ret;
}

ll md(ll x){
	while (x < 0) x += mod;
	while (x >= mod) x -= mod;
	return x;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	pw[0] = 1LL; for (ll i = 1; i < n; i++) pw[i] = md(pw[i-1] * 2LL);
	for (ll i = 1; i <= n; i++) a[i] = read();
	sort(a+1, a+n+1); for (ll i = 0; i <= 5000; i++) dp[0][i] = 1LL;
	for (ll i = 1; i <= n; i++){
		for (ll j = 0; j <= 5000; j++){
			dp[i][j] = dp[i-1][j];
			if (j >= a[i]) dp[i][j] = md(dp[i][j] + dp[i-1][j-a[i]]);
		}ans = md(ans + pw[i-1] - dp[i-1][a[i]]);
	}printf("%lld\n", ans);
	return 0;
}
