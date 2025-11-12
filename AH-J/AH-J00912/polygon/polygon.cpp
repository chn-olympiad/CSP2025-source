#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5005, M = 10005, Mod = 998244353;
int a[N], sum;
long long dp[N][M];

long long cal(int n, int m) {
	dp[1][a[1]] = dp[1][0] = 1;
	
	for (int i = 2; i <= n; i ++) {
		for (int j = 0; j <= sum; j ++) {
			dp[i][j] = dp[i-1][j];
			if ((j - a[i]) >= 0)
				dp[i][j] = (dp[i][j] + dp[i-1][j - a[i]]) % Mod;
		}
	}
	
	long long ans = 0;
	for (int j = m + 1; j <= sum; j ++)
		ans = (ans + dp[n][j]) % Mod;
	return ans;
}

int main() {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);

	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &a[i]), sum += a[i];
	
	sort (a + 1, a + n + 1);
	sum -= a[n];
	
	long long ans = 0;
	for (int i = 3; i <= n; i ++)
		ans = (ans + cal(i - 1, a[i])) % Mod;
	cout << ans;
	return 0;
}
/*
5
2 2 3 8 10
*/
