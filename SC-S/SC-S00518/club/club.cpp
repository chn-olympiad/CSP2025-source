#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::cerr;
using std::min;
using std::max;
using std::swap;
const int MAXN = 1e5 + 5;
int n, lim, a[MAXN][5];
int dp[300][300];
void Init() {
	memset(a, 0, sizeof a);
	memset(dp, 0, sizeof dp);
}
int val[MAXN];
void Solve1() {
	for (int i = 1; i <= n; ++i) val[i] = a[i][1];
	std::sort(val + 1, val + n + 1);
	int ans = 0;
	for (int i = 1; i <= lim; ++i) ans += val[n - i + 1];
	cout << ans << '\n';
}
void Solve2() {
	int f[MAXN];
	memset(f, 0, sizeof f);
	f[1] = a[1][1];
	f[0] = a[1][2];
	for (int i = 2; i <= n; ++i) {
		for (int j = min(i, lim); j >= 0; --j) {
			if (i - j > lim) continue;
			int res1 = (j - 1 >= 0 ? f[j - 1] : 0) + a[i][1];
			int res3 = f[j] + a[i][2];
			f[j] = max(res1, res3);
		}
	}
	cout << f[lim] << '\n';
}
void Solve() {
	bool f1 = 1, f2 = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j)
			cin >> a[i][j];
		if(a[i][3] != 0) f1 = f2 = 0;
		if(a[i][2] != 0) f1 = 0;
	}
	if(f1) {
		Solve1();
		return;
	}
	if(f2) {
		Solve2();
		return;
	}
	dp[1][0] = a[1][1];
	dp[0][1] = a[1][2];
	dp[0][0] = a[1][3];
	for (int i = 2; i <= n; ++i) {
		for (int j = min(i, lim); j >= 0; --j) {
			for (int k = min(i - j, lim); k >= 0; --k) {
				if (i - j - k > lim) continue;
				if (i - j - k < 0) continue;
				int res1 = (j - 1 >= 0 ? dp[j - 1][k] : 0) + a[i][1];
				int res2 = (k - 1 >= 0 ? dp[j][k - 1] : 0) + a[i][2];
				int res3 = dp[j][k] + a[i][3];
				dp[j][k] = max({res1, res2, res3});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= lim; ++i) {
		for (int j = 0; j <= lim; ++j) {
			int k = n - i - j;
			if (k > lim) continue;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; cin >> t;
	while (t--) {
		Init();
		cin >> n; lim = n / 2;
		Solve();
	}
	return 0;
}