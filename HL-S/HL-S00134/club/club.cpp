#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct person {
	int a1;
	int a2;
	int a3;
} persons[100005];
long long dp[50][50][50];
long long f[500][500];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a1, a2, a3; scanf("%d%d%d", &a1, &a2, &a3);
			persons[i].a1 = a1, persons[i].a2 = a2, persons[i].a3 = a3;
		}
		if (n <= 30) {
			for (int i = 1; i < n; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						dp[i][j][k] = -1;
					}
				}
			}
			dp[0][1][0] = persons[0].a1;
			dp[0][0][1] = persons[0].a2;
			dp[0][0][0] = persons[0].a3;
			long long ans = 0;
			for (int i = 1; i < n; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						dp[i][j][k] = -1;
						if (j-1 >= 0 && dp[i-1][j-1][k] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + persons[i].a1);
						if (k-1 >= 0 && dp[i-1][j][k-1] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + persons[i].a2);
						if (dp[i-1][j][k] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + persons[i].a3);
					}
				}
			}
			for (int j = 0; j <= n / 2; j++) {
				for (int k = 0; k <= n / 2; k++) {
					if (n - j - k <= n / 2)
					ans = max(ans, dp[n - 1][j][k]);
				}
			}
			printf("%lld\n", ans);
			continue;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n / 2; j++) {
				f[i][j] = -1;
			}
		}
		f[0][1] = persons[0].a1;
		f[0][0] = persons[0].a2;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= n / 2; j++) {
				if (j-1 >= 0 && f[i-1][j-1] != -1) f[i][j] = max(f[i][j], f[i-1][j-1] + persons[i].a1);
				if (f[i-1][j] != -1) f[i][j] = max(f[i][j], f[i-1][j] + persons[i].a2);
			}
		}
		printf("%lld\n", f[n - 1][n / 2]);
	}
}
