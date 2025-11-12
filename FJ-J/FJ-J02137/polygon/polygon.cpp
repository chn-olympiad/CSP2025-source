#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

constexpr size_t N = 5000 + 5;
constexpr int mod = 998244353;

int value[N];
int dp[N];

int main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin.tie(nullptr); cout.tie(nullptr); std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; ++i) {
		
		cin >> value[i];
	}
	
	std::sort(value + 1, value + n + 1);
	
	int ans = 0;
	
	for(int i = 1; i <= n; ++i) {
		
		if(i >= 3) {
			
			ans = (ans + dp[value[i]]) % mod;
		}
		
		for(int j = 5000; j >= 0; --j) {
			
			dp[j] = (dp[j] + dp[std::max(0, j - value[i])] + (value[i] > j ? 1 : 0)) % mod;
		}
	}
	
	cout << ans;
	
	return 0;
}
