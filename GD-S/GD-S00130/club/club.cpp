#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n;
int a[N][5];
int read() {
	int f = 0;
	char t = getchar();
	while(t < '0' || t > '9') {
		t = getchar();
	}
	while(t >= '0' && t <= '9') {
		f = f * 10 + t - '0';
		t = getchar();
	}
	return f;
}
int dp[N][N][N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				a[i][j] = read();
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= min(i, n / 2); j++) {
				for(int p = 0; p <= min(i, n / 2); p++) {
					if(p + j > i) {
						break;
					}
					int t = i - j - p;
					if(t > n / 2) {
						continue;
					}
					if(i - j - p != 0) {
						dp[j][p][t] = max(dp[j][p][t], dp[j][p][t-1] + a[i][3]);
					}
					if(p != 0) {
						dp[j][p][t] = max(dp[j][p-1][t] + a[i][2], dp[j][p][t]);
					}
					if(j != 0) {
						dp[j][p][t] = max(dp[j-1][p][t] + a[i][1], dp[j][p][t]);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i <= n / 2; i++) {
			for(int j = 0; j <= n / 2; j++) {
				int r = n - i - j;
				if(r > n / 2) {
					continue;
				}
				ans = max(ans, dp[i][j][r]);
			}
		}
		memset(a, 0, sizeof a);
		memset(dp, 0, sizeof dp);
		cout << ans << endl;
	}
	return 0;
}
