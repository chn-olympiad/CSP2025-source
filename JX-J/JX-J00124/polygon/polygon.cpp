#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5005;
constexpr int MOD = 998244353;

long long n, arr[N], dp[N << 1], pre[N << 1];
long long answer = 0, max_var;

long long QuickPow(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		max_var = max(max_var, arr[i]);
	}
	
	sort(arr + 1, arr + n + 1);
	
	dp[0] = 1;
	pre[0] = dp[0];
	
	for (int i = 1; i <= max_var; i++) {
		pre[i] = (pre[i] + pre[i - 1]) % MOD;
	}
	
	for (int i = 1; i <= n; i++) {
		// for (int j = 0; j <= max_var; j++) {
		//  	cout << dp[j] << " \n"[j == max_var];
		// }
		// for (int j = 0; j <= max_var; j++) {
		//  	cout << pre[j] << " \n"[j == max_var];
		// }
		// cout << arr[i] << "\n";
		
		int sum = (pre[arr[i]]) % MOD;
		int tot = ((QuickPow(2, i - 1)) % MOD + MOD) % MOD;
		
		answer = (answer + ((tot - sum) % MOD + MOD) % MOD) % MOD;
		
		// cout << sum << " " << tot << " " << answer << "\n\n";
		
		for (int j = max_var; j >= arr[i]; j--) {
			dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
		}
		
		pre[0] = dp[0];
		for (int j = 1; j <= max_var; j++) {
			pre[j] = (dp[j] + pre[j - 1]) % MOD;
		}
		
	}
	
	cout << answer << "\n";
	
	return 0;
}
