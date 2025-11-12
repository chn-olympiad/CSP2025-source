#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 5e3 + 5, mod = 998244353;
int n, a[N], ans;
void dfs (int at, int tot, int big) {
	if (at == n + 1) {
		if (tot > (big << 1)) {
			++ans;
			ans %= mod;
		}
		return;
	}
	dfs(at + 1, tot, big);
	dfs(at + 1, tot + a[at], max(big, a[at]));
	return;
}
signed main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
