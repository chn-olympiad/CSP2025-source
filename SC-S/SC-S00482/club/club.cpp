#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10, N1 = 210;
int t, n, a[3][N], f[N1][N1][N1];

namespace SpecialA {
	int p[N];
	void solve() {
		for (int i = 1; i <= n; ++i)
			p[i] = a[0][i];
		sort(p + 1, p + n + 1, greater <int> ());
		int sum = 0;
		for (int i = 1; i <= n / 2; ++i)
			sum += p[i];
		printf("%lld\n", sum);
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		bool f1 = 1, f2 = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			f1 &= a[1][i] == 0, f2 &= a[2][i] == 0;
		}
		if (f1 && f2) {
			SpecialA::solve();
			continue;
		}
		memset(f, 0xcf, sizeof f);
		f[0][0][0] = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= min(i, n / 2); ++j)
				for (int k = 0; k <= min(i - j, n / 2); ++k) {
					int p = i - j - k;
					if (p > n / 2) continue;
					if (j > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[0][i]);
					if (k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[1][i]);
					if (p > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[2][i]);
				}
		int ans = 0;
		for (int j = 0; j <= n / 2; ++j)
			for (int k = 0; k <= n / 2; ++k)
				ans = max(ans, f[n][j][k]);
		printf("%lld\n", ans);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
