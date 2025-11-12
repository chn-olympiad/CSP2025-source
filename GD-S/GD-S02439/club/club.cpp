// expectation: 60pts
#include <bits/stdc++.h>
// #define int long long
#define pb push_back

using namespace std;
const int maxn = 1e5 + 10, maxm = 2e2 + 10;

int n, m, d[maxn][3], f[maxm][maxm][maxm], ans, e[maxn];

bool ck() {
	for (int i = 1; i <= n; ++i) if (d[i][1] || d[i][2]) return 0;
	return 1;
}

void solve() {
	cin >> n, m = (n >> 1);
	for (int i = 0; i <= m; ++i) for (int j = 0; j <= m; ++j) for (int k = 0; k <= m; ++k) f[i][j][k] = 0;
	ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> d[i][j];
	if (ck()) {
		for (int i = 1; i <= n; ++i) e[i] = d[i][0];
		sort(e + 1, e + n + 1);
		int tot = 0;
		for (int i = n; i >= m; --i) {
			ans += e[i];
			tot++;
			if (tot == m) break;
		}
		cout << ans << '\n';
		return;
	}
	for (int a = 0, u; a <= m; ++a)
		for (int b = 0; b <= m; ++b)
			for (int c = 0; c <= m; ++c) {
				u = a + b + c + 1;
				if (u > n) {
					ans = max(ans, f[a][b][c]);
					c = m + 1;
				} else {
					if (a < m)
						f[a + 1][b][c] = max(f[a + 1][b][c], f[a][b][c] + d[u][0]);
					if (b < m)
						f[a][b + 1][c] = max(f[a][b + 1][c], f[a][b][c] + d[u][1]);
					if (c < m)
						f[a][b][c + 1] = max(f[a][b][c + 1], f[a][b][c] + d[u][2]);
				}
			}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
