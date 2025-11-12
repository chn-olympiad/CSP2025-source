#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e2 + 10, MOD = 998244353;

int n, m, c[N], sum, dp[1 << 18][19];
string s;

void solve(){
	dp[0][0] = 1;
	for(int i = 0; i < (1 << n); i++){
		int op = __builtin_popcount(i);
		for(int j = 0; j <= op; j++){
			for(int k = 1; k <= n; k++){
				if(i >> (k - 1) & 1) continue;
				int f = (j >= c[k] || s[op + 1] == '0');
				(dp[i | (1 << k - 1)][j + f] += dp[i][j]) %= MOD;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n - m; i++){
		(ans += dp[(1 << n) - 1][i]) %= MOD;
	}
	cout << ans;
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s; s = ' ' + s;
	int fl = 0; 
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		fl |= s[i] != '1';
	}
	if(!fl){
		int res = 1;
		for(int i = 1; i <= n; i++){
			(res *= i) %= MOD;
		}
		cout << res;
		return 0;
	}
	if(n <= 18){
		solve();
		return 0;
	}
	return 0;
}

