#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353, N = 5e3+5;
int n, dp[N][N], a[N], sum[N][N];
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; j++) {
			if(j==i){
				sum[j][a[i]]++;
				continue;
			}
			dp[i][j] = dp[i - 1][j] * 2 % mod;
			int ans = 0;
			for (int k = 2*a[j]; k >=0; k--) {
				if (k + a[i] > 2 * a[j]) {
					ans += sum[j][k];
				}
				if(k-a[i]>=0){
					sum[j][k] += sum[j][k - a[i]];
				}
			}
			dp[i][j] += ans;
			dp[i][j] = dp[i][j] % mod;
			sum[j][a[i]]++;
		}
	}
	int as = 0;
	for (int i = 1; i <= n; i++) {
		as = (as + dp[n][i]) % mod;
	}
	cout << as;
	return 0;
}
//5
//2 2 3 8 10
