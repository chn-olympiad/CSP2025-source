#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5, mod = 998244353;
long long n, dp[N*100][N], a[N], sum[N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dp[a[1]][1] = dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = a[i]; j <= sum[i]; j++) {
			for (int g = i - 1; g >= 0; g--) {
				dp[j][i] = (dp[j][i] + dp[j - a[i]][g]) % mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2 * a[i] + 1; j <= sum[i]; j++) {
			ans = (ans + dp[j][i]) % mod;
		}
	}
	cout << ans;
	return 0;
}