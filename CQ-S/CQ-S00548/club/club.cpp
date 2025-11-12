#include <bits/stdc++.h>
using namespace std;
namespace WorldMachine {
const int N = 1e5 + 5;
int T, n, a[N][3], b[N], c[3], d[N];
void solve() {
	cin >> n, memset(c, 0, sizeof(c)); int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) cin >> a[i][j];
		b[i] = 0; for (int j : {1, 2}) if (a[i][j] > a[i][b[i]]) b[i] = j;
		c[b[i]]++, ans += a[i][b[i]];
	}
	if (max({c[0], c[1], c[2]}) <= n >> 1) return cout << ans << '\n', void();
	int mx = 0; for (int i : {1, 2}) if (c[i] > c[mx]) mx = i; int t = 0;
	for (int i = 1; i <= n; i++) if (b[i] == mx) {
		int tm = 0; for (int j : {0, 1, 2}) if (j != mx) tm = max(tm, a[i][j]); d[++t] = a[i][mx] - tm;
	} sort(d + 1, d + 1 + t);
	for (int i = 1; i <= t; i++) { ans -= d[i], c[mx]--; if (c[mx] <= n >> 1) break; }
	cout << ans << '\n';
}
void main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T; while (T--) solve();
}
}
int main() { return WorldMachine::main(), 0; }
