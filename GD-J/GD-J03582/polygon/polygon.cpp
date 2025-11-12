#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
const int mod = 998244353;

int n, sum, ans;
int a[N], dp[N * 100];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for (int k = 1; k <= n; ++k) {
		for (int i = 0; i <= sum; ++i) dp[i] = 0;
		dp[0] = 1;
		
		for (int i = 1; i < k; ++i) {
			for (int j = sum; j >= a[i]; --j) {
				dp[j] = (dp[j] + dp[j - a[i]]) % mod;
			}
		}
		
		for (int i = a[k] + 1; i <= sum; ++i) ans = (ans + dp[i]) % mod;
	}
	
	cout << ans << '\n';
	
	return 0;
}
