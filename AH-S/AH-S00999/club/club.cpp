#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, a[N][5], dp[205][205][205], ans, specialA;
int specialA_a[N], specialA_cnt;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while (t--) {
		specialA = 1;
		
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][2] || a[i][3])	specialA = 0;
		}
		if (specialA) {
			specialA_cnt = 0;
			for (int i = 1; i <= n; i++)	specialA_a[++specialA_cnt] = a[i][1];
			sort(specialA_a + 1, specialA_a + specialA_cnt + 1);
			ans = 0;
			for (int i = n, j = 1; j <= n / 2; i--, j++)	ans += specialA_a[i];
			cout << ans << "\n";
			continue ;
		}
		
		memset(dp, 0, sizeof(dp));
		ans = -1e9;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n / 2 && j <= i; j++) {
				for (int k = 0; k <= n / 2 && k <= i; k++) {
					if (i - j - k > n / 2 || i - j - k < 0)	continue ;
					if (j > 0)	dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
					if (k > 0)	dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
					if (i - j - k > 0)	dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
					ans = max(ans, dp[i][j][k]);
				}
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
