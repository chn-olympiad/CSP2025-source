#include <bits/stdc++.h>
using namespace std;
long long n, a[5010], ans, mod = 998244353, myfact[5010];
void initfac() { // 预处理阶乘 
	myfact[0] = 1;
	for (long long i = 1; i <= n; i++) myfact[i] = myfact[i - 1] * i % mod;
}
long long quickPow(long long n, long long m) {
	long long res = 1;
	while (m) {
		if (m & 1) res = res * n % mod;
		m >>= 1;
		n = n * n % mod;
	}
	return res;
} 
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	initfac();
	if (a[n] == 1) { // 特殊数据 - max(a[i]) = 1 
		// 只有一根的时候不行, 其他情况皆可 
		cout << (quickPow(2, n) - n - 1 + mod) % mod; // 2 ^ n是全部方式, n是len = 1, 1是len = 0 
	}
	else { // 常规数据
		vector <vector <unsigned int> > dp(n + 10, vector <unsigned int> (a[n] + 10)), dpSum(n + 10, vector <unsigned int> (a[n] + 10)); // 拿前i个, 凑出j |||  
		dp[0][0] = 1; // 啥也不拿
		for (unsigned int i = 1; i <= n; i++) {
			for (unsigned int j = 0; j <= a[n]; j++) {
				if (j >= a[i]) dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				
				if (j == 0) dpSum[i][j] = dp[i][j];
				else dpSum[i][j] = (dpSum[i][j - 1] + dp[i][j]) % mod;
			} 
		}
		for (unsigned int i = n; i >= 2; i--) {
			unsigned int tmp = quickPow(2, i - 1);
			ans = (ans + tmp - dpSum[i - 1][a[i]] + mod) % mod;
		}
		cout << ans;
	}
	return 0;
}
