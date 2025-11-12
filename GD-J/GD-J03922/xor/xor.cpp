#include <iostream>
#include <ios>

using namespace std;

long long n, k;
long long a[500005], s[500005], dp[500005];

int get_range_xor_sum(int l, int r) {
	return (s[l - 1] ^ s[r]);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		long long ans = dp[i];

		for (int j = i; j >= 1; j--) {
			if (get_range_xor_sum(j, i) == k) { // 贪心：尽量选择短的区间 
				ans = max(dp[j - 1] + 1, ans);
				break;
			}
		}		
		dp[i] = max(dp[i], ans);
	}

	
	cout << dp[n] << endl;
	
	return 0;
}

