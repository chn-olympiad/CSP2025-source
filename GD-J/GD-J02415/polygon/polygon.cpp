#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 0;
ll ans = 0;
ll mem = 0;
ll a[1000100] = {0};

void dfs (ll x, ll i, ll num, ll ma) {
	if (num < mem and i > n) {
		return;
	}
	if (num == mem) {
		if (x > (ma * 2)) {
			ans = (ans + 1) % 998244353;
		}
		return;
	}
	dfs(x + a[i], i + 1, num + 1, max(ma, a[i]));
	dfs(x, i + 1, num, ma);
}

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 3; i <= n; i++) {
		mem = i;
		dfs(0, 1, 0, 0);
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
