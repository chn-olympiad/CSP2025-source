#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	int a[n + 1], dp[n + 1][n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 3; j <= i; j++) {
			if (dp[i - 1][j] == 0) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = dp[i - 1][j] * (j + 1);
			}
			sum += dp[i][j];
		}
	}
	cout << sum;
	return 0;
}

