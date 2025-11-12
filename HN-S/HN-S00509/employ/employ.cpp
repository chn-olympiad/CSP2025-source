// 20pts expected
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 18 , mod = 998244353;
// 正解是DP吧 
// 当然不会，但是可以打一个状压dp试试
int n , m , dp[1 << N][N] , c[N];
bool a[N];
signed main() {
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	char ch; bool flag = 1;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		a[i] = ch - '0';
		flag &= a[i];
	}
	for (int i = 0; i < n; i++) cin >> c[i];
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) for (int j = n - 1; j >= 0; j--) {
		int now = __builtin_popcount(i) - j;
		if (now < 0) continue;
		for (int k = 0; k < n; k++) if (!(i >> k & 1)) {
			dp[i | (1 << k)][j + (a[now + j] == 1 && now < c[k])] += dp[i][j];
			if (dp[i | (1 << k)][j + (a[now + j] == 1 && now < c[k])] > mod) dp[i | (1 << k)][j + (a[now + j] == 1 && now < c[k])] -= mod;
		}
	}
//	for (int i = 0; i < (1 << n); i++) {
//		for (int j = 0; j < n; j++) {
//			cerr << "-- " << i << ' ' << j << ' ' << dp[i][j] << '\n';
//		}
//	}
	int ans = 0;
	for (int j = m; j < n; j++) {
		ans += dp[(1ll << n) - 1][j]; ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}

