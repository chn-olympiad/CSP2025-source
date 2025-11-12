#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353, N = 505;
ll n, m, s[N], ct[N], dp[2][N][N], c[N][N], g[N][N], fac[N], f[N][N];
void chm(ll &x){ if(x >= mod) x -= mod;}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m; char C;
	for(int i = 1; i <= n; i++) cin >> C, s[i] = C - '0';
	for(int i = 0; i <= n; c[i++][0] = 1)
		for(int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	for(int i = fac[0] = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	for(int i = 1, x; i <= n; i++) cin >> x, ct[x]++;
	f[0][0] = ct[0];
	for(int i = 0; i < n; i++) for(int j = i; ~j; j--)
		f[i + 1][j + 1] = f[i][j] + ct[j + 1] - 1, f[i + 1][j] = f[i][j] - 1;
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++){
		memset(dp[i + 1 & 1], 0, sizeof dp[0]);
		for(int j = 0; j <= i; j++) for(int k = 0; k <= i; k++) if(dp[i & 1][j][k]){
			int l = f[i][j] + k;
			if(s[i + 1] == 1){
				for(int p = 0; p <= min((ll)k, ct[j + 1]); p++) (dp[i + 1 & 1][j + 1][k - p] += dp[i & 1][j][k] * c[k][p] % mod * fac[p] % mod * c[ct[j + 1]][p] % mod * l) %= mod;
				chm(dp[i + 1 & 1][j][k + 1] += dp[i & 1][j][k]);
			} else{
				for(int p = 0; p <= min((ll)k + 1, ct[j + 1]); p++)
					(dp[i + 1 & 1][j + 1][k + 1 - p] += dp[i & 1][j][k] * c[k + 1][p] % mod * fac[p] % mod * c[ct[j + 1]][p]) %= mod;
				for(int p = 0; p <= min((ll)k, ct[j + 1]); p++)
					(dp[i + 1 & 1][j + 1][k - p] += dp[i & 1][j][k] * c[k][p] % mod * fac[p] % mod * c[ct[j + 1]][p] % mod * l) %= mod;
			}
		}
	}
	ll ans = 0;
	g[n + 1][0] = 1;
	for(int i = n; i; i--) for(int j = 0; j <= ct[i]; j++) for(int k = 0; k + j <= n; k++)
		(g[i][k + j] += g[i + 1][k] * c[k + j][j] % mod * fac[j] % mod * c[ct[i]][j]) %= mod;
	for(int j = 0; j <= n - m; j++) for(int k = 0; k <= n; k++)
		(ans += dp[n & 1][j][k] * g[j + 1][k]) %= mod;
	cout << ans % mod;
	return 0;
}
