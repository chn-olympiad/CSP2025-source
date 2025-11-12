// lichenxi108.rp = inf;
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, N0 = 205;
int n, dp[N0][N0][N0];
struct node { int x, y, z; } a[N];
bool cmp1(node x, node y) { return x.x > y.x; }
bool cmp2(node x, node y) { return x.y > y.y; }
bool cmp3(node x, node y) { return x.z > y.z; }

void solve1() {
	sort(a + 1, a + n + 1, cmp1);
	int ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		ans += a[i].x;
	}
	cout << ans << '\n';
}

void solve2() {
	sort(a + 1, a + n + 1, cmp2);
	int ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		ans += a[i].y;
	}
	cout << ans << '\n';
}

void solve3() {
	sort(a + 1, a + n + 1, cmp3);
	int ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		ans += a[i].z;
	}
	cout << ans << '\n';
}

void solve() {
	bool f1 = 1, f2 = 1, f3 = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		if (a[i].x) f1 = 0;
		if (a[i].y) f2 = 0;
		if (a[i].z) f3 = 0;
	}
	if (f1 && !f2 && !f3) {
		solve1(); return;
	}
	if (!f1 && f2 && !f3) {
		solve2(); return;
	}
	if (!f1 && !f2 && f3) {
		solve3(); return;
	}
	int ans = 0;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 0; j <= n / 2; j++) {
			for (int k = 0; k <= n / 2 && i + j + k <= n; k++) {
				if (i && !j && !k) dp[i][j][k] = dp[i - 1][j][k] + a[i + j + k].x;
				if (!i && j && !k) dp[i][j][k] = dp[i][j - 1][k] + a[i + j + k].y;
				if (!i && !j && k) dp[i][j][k] = dp[i][j][k - 1] + a[i + j + k].z;
				if (i && j && !k) dp[i][j][k] = max(dp[i - 1][j][k] + a[i + j + k].x, dp[i][j - 1][k] + a[i + j + k].y);
				if (!i && j && k) dp[i][j][k] = max(dp[i][j - 1][k] + a[i + j + k].y, dp[i][j][k - 1] + a[i + j + k].z);
				if (i && !j && k) dp[i][j][k] = max(dp[i - 1][j][k] + a[i + j + k].x, dp[i][j][k - 1] + a[i + j + k].z);
				if (i && j && k) dp[i][j][k] = max(dp[i - 1][j][k] + a[i + j + k].x, max(dp[i][j - 1][k] + a[i + j + k].y, dp[i][j][k - 1] + a[i + j + k].z)); 
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int _; cin >> _;
	while (_--) solve();
	return 0;
} 
