#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 20, X = 1e6, MOD = 998244353;
int n, m, a[N], dp[N][X], ans;
char c[N];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if(n > 18) {cout << 0; return 0;}
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	for(int i = 0; i < (1 << n) - 1; i++){
		int cnt = 0;
		for(int j = 0; j < n; j++) cnt += i >> j & 1;
		for(int j = 0; j <= cnt; j++){
			for(int k = 0; k < n; k++){
				if(!(i >> k & 1)){
 					if(c[cnt + 1] == '0' || j >= a[k + 1]){
						(dp[j + 1][i + (1 << k)] += dp[j][i]) %= MOD;
					}else{
						(dp[j][i + (1 << k)] += dp[j][i]) %= MOD;
					}
				}
			}
		}
	}
	for(int i = 0; i <= n - m; i++){
		ans = (ans + dp[i][(1 << n) - 1]) % MOD;
	}
	cout << ans;
	return 0;
}
