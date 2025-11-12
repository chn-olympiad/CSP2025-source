#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
#define mod 998244353
using namespace std;

inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

ll n, m, ans, a[502], c[502], p[502], vis[502];

void dfs(ll x, ll cnt, ll now) {
	if(x > n) {
		if(cnt >= m) ans++;
		return;
	}
	for(ll i = 1; i <= n; i++) if(!vis[i]) {
		vis[i] = 1;
		ll tnow = now, tcnt = cnt;
		if(now >= c[i]) tnow++;
		else tcnt += a[x], tnow += !a[x];
		dfs(x + 1, tcnt, tnow);
		vis[i] = 0;
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = rd(), m = rd();
	string s; cin >> s;
	for(ll i = 1; i <= n; i++) a[i] = s[i - 1] - 48;
	for(ll i = 1; i <= n; i++) c[i] = rd();
	sort(c + 1, c + n + 1);
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
/*

*/

