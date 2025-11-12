#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

constexpr size_t N = 5e5 + 5, W = (1 << 20) + 5;

int value[N];

int dp[N];
int pre[N], last[W];

int main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin.tie(nullptr); cout.tie(nullptr); std::ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; ++i) {
		
		cin >> value[i];
		pre[i] = pre[i - 1] ^ value[i];
	}
	
	memset(last, -1, sizeof(last));
	last[0] = 0;
	
	for(int i = 1; i <= n; ++i) {
		
		int v = value[i] ^ k;
		int j = last[pre[i - 1] ^ v];
		
		if(j == -1) {
			
			dp[i] = dp[i - 1];
		}
		
		else {
			
			dp[i] = std::max(dp[i - 1], dp[j] + 1);
		}
		
		last[pre[i]] = i;
	}
	
	cout << dp[n];
	
	return 0;
}
