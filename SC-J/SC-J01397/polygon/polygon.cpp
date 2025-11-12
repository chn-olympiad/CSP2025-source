#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

ll n, a[5005];

const ll MOD = 998244353;

ll ans;

map<pair<ll, ll>, pair<ll, bool> > f;

ll dfs(ll x, ll sum) {
	pair<ll, bool> p = f[make_pair(x, sum)];
	if (p.second) return p.first;
	ll ans = 0;
	for (int i = x + 1; i <= n; i ++) {
		ll k = dfs(i, sum + a[i]);
		if (sum + a[i] > 2 * a[i]) k ++;
		ans += k;
		ans %= MOD;
	}
	f[make_pair(x, sum)] = make_pair(ans, true);
	return ans;
}

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	sort(a+1, a+1+n);
	
	ll ans = dfs(0, 0);
	cout << ans;
	
	return 0;
}
