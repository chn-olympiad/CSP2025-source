#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][4], dp[N][N / 2];

int main() {
//    freopen("club.in", "r", stdin);
//    freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = n / 2; j >= 1; j--) {
				dp[i][j] = dp[i - 1][j];
				if (j - 1 >= 1)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i][1]);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = n / 2; j >= 1; j--) {
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}
	}

//    fclose(stdin);
//    fclose(stdout);
	return 0;
}
