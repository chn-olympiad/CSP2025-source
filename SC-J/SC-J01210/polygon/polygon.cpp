#include<bits/stdc++.h>
using namespace std;
int n, k;
int x;
int dp[5010];
int a[5010];
const int MOD = 998244353;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - 1; j++) {
			int maxn = 0;
			for (int k = i; k <= j; k++) {
				if (a[k] >= maxn) {
					maxn = a[k];
				}
			}
			if ((dp[i] % MOD) + (a[j] % MOD) >= 2 * (maxn % MOD)) {
				dp[i] = ((dp[i - 1] % MOD) + (a[j] % MOD)) % MOD;
			}
		}
	}
	cout << dp[n];
	return 0;
}