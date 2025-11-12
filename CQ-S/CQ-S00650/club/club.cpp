#include <bits/stdc++.h>

using PI = std::pair<int, int>;
const int N = 1e5 + 10;
int a[N][4];
int dp[210][210][210];

void ckmx(int &a, int b) {
	if (b > a)
		a = b;
	return;
}

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i][1] >> a[i][2] >> a[i][3];
	memset(dp, -0x3f, sizeof dp);
	dp[1][1][0] = a[1][1]; dp[1][0][1] = a[1][2]; dp[1][0][0] = a[1][3];

	for (int i = 1; i + 1 <= n; i++) {
		for (int j = 0; j <= std::min(n / 2, i); j++) {
			for (int k = 0; k <= std::min(n / 2, i); k++) {
				int x = i - j - k;
				if (x < 0 || x > n / 2) continue;

				ckmx(dp[i + 1][j + 1][k], dp[i][j][k] + a[i + 1][1]);
				ckmx(dp[i + 1][j][k + 1], dp[i][j][k] + a[i + 1][2]);
				ckmx(dp[i + 1][j][k], dp[i][j][k] + a[i + 1][3]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 0; j <= n / 2; j++) {
			int x = n - i - j;
			if (x < 0 || x > n / 2) continue;
			ans = std::max(ans, dp[n][i][j]);
		}
	}
	std::cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	std::cin >> T;
	while (T--) solve();
	return 0;
}
/*
mei jiu le
T1 zhi hui de 55pts
55 + 48 + 25 + 0 = 128pts
*/
