#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end(), cmp);
	int maxai = a[n];
	vector<vector<int> > dp(n+5, vector<int>(maxai+2, 0)); 
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		dp[i][0] = (1LL * dp[i-1][0] * 2) % mod;
		for(int j = 1; j <= maxai+1; j++) {
			for(int k = i; k >= 1; k--) {
				dp[i][j] = (dp[i][j] + dp[k-1][max(j-a[k], 0)]) % mod;
			}
		}
	}
	
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + dp[i-1][a[i]+1]) % mod;
	}
	cout << ans << "\n";
	return 0;
}
