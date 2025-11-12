#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n+5);
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<int> dp(n+5, 0);
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		int xorsum = a[i];
		int cidx = i-1;
		while(xorsum != k && cidx > 0) {
			xorsum ^= a[cidx];
			cidx--;
		}
		if(xorsum == k) {
			dp[i] = max(dp[i], dp[cidx] + 1);
		} 
	}
	
	cout << dp[n] << "\n";
	return 0;
}
