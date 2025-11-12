#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int qpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, mx = 0;
	cin >> n;
	vector <int> a(n + 10);
	for(int i = 1;i <= n;i++) cin >> a[i], mx = max(mx, a[i]);
	sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
	a[0] = 0;
	vector <int> mp;
	vector <vector <int>> dp(n + 10, vector <int> (mx + 10));
	for(int i = 1;i <= n;i++) if(a[i] != a[i - 1]) mp.emplace_back(n - i + 1);
//	reverse(a.begin() + 1, a.begin() + n + 1);
	sort(a.begin() + 1, a.begin() + n + 1);
//	for(int i = 0;i <= n;i++) dp[i][0] = 1;
	dp[0][0] = 1;
	for(int i = 1;i < n;i++) {
		for(int j = mx; j >= 0; j--) {
			dp[i][j] = dp[i - 1][j];
			if(j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]];
//			cout << i << " " << j << " " << dp[i][j] << "\n";
		}
	} 
//	cout << "+____________________\n";
	int ans = 0;
	for(int i = 0;i < mp.size();i++) {
//		cout << mp[i] << "\n";
		if(mp[i] - 1 == 0) continue; 
		int sum = 1, t = mp[i];
		for(int i = 1;i <= a[t];i++) sum += dp[t - 1][i];
//		cout << mp[i] << "\n";
		ans += qpow(2, t - 1) - sum;
		ans = (ans + mod) % mod;
	}
	cout << ans << "\n";
//	cout << (qpow(2, n) - ans + mod) % mod;
	return 0;
}
/*
5
2 2 3 8 10
*/
