#include <bits/stdc++.h>
using namespace std;

const int N = 5005, mod = 998244353;
long long n, a[N], dp[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	long long qwq = 0, res = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i] + 1; j <= N; j++) res = (res + dp[j]) % mod;
		res = (res + qwq) % mod;
		qwq = qwq * 2 % mod;
		for (int j = N - a[i] + 1; j <= N; j++) qwq = (qwq + dp[j]) % mod;
		for (int j = N; j >= a[i]; j--) dp[j] = (dp[j] + dp[j - a[i]]) % mod;
	}
	cout << res << "\n";
	return 0; 
}

// bai'xie'zhong'guo'ji'suan'ji'xie'hui
// rang'wo'tong'guo'zhe'dao'ti'ba

// gu'fen: 336
