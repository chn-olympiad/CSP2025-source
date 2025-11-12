#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], c[100010], dp[100010][5];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
		for (int i = 1; i <= n; i++) {
			int x = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3]));
			dp[i][1] = x + a[i], dp[i][2] = x + b[i], dp[i][3] = x + c[i];
		}
		cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << endl;
	}
}
