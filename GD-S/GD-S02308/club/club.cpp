#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N][5];
int dp[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		set<int> s[5];
		int ans = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] + max(a[i][1], max(a[i][2], a[i][3]));
		} cout << dp[n] << endl;
	} return 0;
} 
