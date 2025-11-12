#include <bits/stdc++.h>
#define int long long
const long long p = 998244353;
using namespace std;
int n, m, c[505], dp[1 << 18][18], ans;
char s[505];

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for( int i = 1; i <= n; i++ ) cin >> s[i];
	for( int i = 1; i <= n; i++ ) cin >> c[i];
	if(n <= 18){
		dp[0][0] = 1;
		for( int i = 1; i < (1 << n); i++ ){
			int cnt = 0;
			for( int j = 0; j < n; j++ ){
				if((i >> j) & 1) cnt++;
			}
			if(s[cnt] == '1'){
				for( int j = 0; j < cnt; j++ ){
					for( int k = 0; k < n; k++ ){
						if(!((i >> k) & 1)) continue;
						if(c[k + 1] <= j) dp[i][j + 1] = (dp[i][j + 1] + dp[i ^ (1 << k)][j]) % p;
						else dp[i][j] = (dp[i][j] + dp[i ^ (1 << k)][j]) % p;
					}
				}
			}
			else{
				for( int j = 1; j <= cnt; j++ ){
					for( int k = 0; k < n; k++ ){
						if((i >> k) & 1){
							dp[i][j] = (dp[i][j] + dp[i ^ (1 << k)][j - 1]) % p;
						}
					}
				}
			}
		}
		for( int i = 0; i <= n - m; i++ ) ans = (ans + dp[(1 << n) - 1][i]) % p;
		cout << ans << '\n';
	}
	return 0;
}
