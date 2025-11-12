#include<bits/stdc++.h>
#define ll long long
#define pii pair<int , int>
using namespace std;
const int MAXN = 5e2 + 5 , MOD = 998244353;
int n , m , cnt , c[MAXN] , pre[MAXN] , v[MAXN];
ll dp[MAXN][MAXN] , fac[MAXN] , C[MAXN][MAXN] , f[1 << 18][20];
char s[MAXN];
int main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	fac[0] = 1;
	for (int i = 1 ; i <= 500 ; i ++) fac[i] = fac[i - 1] * i % MOD;
	for (int i = 0 ; i <= 500 ; i ++) {
		C[i][0] = 1;
		for (int j = 1 ; j <= i ; j ++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> s[i];
		cnt += (s[i] == '1');
		pre[i] = pre[i - 1] + (s[i] == '0');
	}
	for (int i = 1 ; i <= n ; i ++) {
		cin >> c[i];
		v[c[i]] ++;
	}
	if (n <= 18) {
		f[0][0] = 1;
		for (int i = 0 ; i < (1 << n) ; i ++) {
			for (int j = 0 ; j < n ; j ++) {
				for (int k = 1 ; k <= n ; k ++) {
					if ((1 << (k - 1)) & i) continue;
					int now = __builtin_popcount(i) + 1 , to = j;
					if (s[now] == '0' || j >= c[k]) to ++;
					f[i | (1 << (k - 1))][to] = (f[i | (1 << (k - 1))][to] + f[i][j]) % MOD;
				}
			}
		}
		ll ans = 0;
		for (int i = 0 ; i <= n - m ; i ++) ans = (ans + f[(1 << n) - 1][i]) % MOD;
		cout << ans;
		return 0;
	}
	if (m == n) {
		if (v[0] || pre[n]) cout << 0;
		else cout << fac[n];
		return 0;
	}
	for (int i = 1 ; i <= n ; i ++) v[i] += v[i - 1];
	dp[0][0] = 1;
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 0 ; j <= i && j <= cnt ; j ++) dp[i][j] = dp[i - 1][j];
		if (s[i] == '1') {
			for (int j = 1 ; j <= cnt && j <= i ; j ++) {
				int up = (j - 1) + pre[i];
				if (v[up] - j + 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (v[up] - j + 1)) % MOD;
			}
		}
	}
	ll ans = 0;
	for (int i = 0 ; i <= cnt ; i ++) {
		ll now = 0;
		for (int j = i ; j <= cnt ; j ++) {
			ll w = dp[n][j] * fac[n - j] % MOD * C[j][i] % MOD;
			if ((j - i) & 1) now = (now - w + MOD) % MOD;
			else now = (now + w) % MOD;
		}
		if (n - i - (n - cnt) >= m) ans = (ans + now) % MOD;
	}
	cout << ans;
	return 0;
}
