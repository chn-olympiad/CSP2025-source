#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#define mod 998244353
using namespace std;
typedef long long ll;
const int N = 505;string b;
int n, m, a[N], s[N], C[N][N], fac[N], f[2][N][N], ans;
inline void add(int& x, int y){x += y;if (x >= mod) x -= mod;}
inline void mul(int& x, int y){x = 1ll * x * y % mod;}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> b, m = n - m, b = ' ' + b, fac[0] = 1, f[0][0][0] = 1;
	for (int i = 1;i <= n;i ++) mul(fac[i] = i, fac[i - 1]);
	for (int i = 0;i <= n;i ++){C[i][0] = 1;
	for (int j = 1;j <= i;j ++) add(C[i][j] = C[i - 1][j], C[i - 1][j - 1]);}
	for (int x, i = n;i --;) cin >> x, a[x] ++;
	for (int i = 0;i <= m;i ++) s[i] = a[i];
	for (int i = 1;i <= m;i ++) s[i] += s[i - 1];
	for (int i = 1, now;i <= n;i ++){
		int u = i & 1, v = i & 1 ^ 1;
		memset(f[u], 0, sizeof(f[u]));
		if (b[i] == '1'){
			for (int j = 0;j <= m;j ++)
			for (int k = 0;k < i;k ++) if (now = f[v][j][k]){
				add(f[u][j][k + 1], now), mul(now, s[j] - i + k + 1);
				if (now > 0 && j < m){
					for (int x = 0;x <= a[j + 1] && x <= k;x ++)
					add(f[u][j + 1][k - x], 1ll * now * fac[x] % mod * C[a[j + 1]][x] % mod * C[k][x] % mod);
				}
			}
		}
		else {
			for (int j = 0;j <= m;j ++)
			for (int k = 0;k < i;k ++) if (now = f[v][j][k]){k ++;
				if (j < m){
					for (int x = 0;x <= a[j + 1] && x <= k;x ++)
					add(f[u][j + 1][k - x], 1ll * now * fac[x] % mod * C[a[j + 1]][x] % mod * C[k][x] % mod);
				}mul(now, s[j] - i + k), k --;
				if (now > 0 && j < m){
					for (int x = 0;x <= a[j + 1] && x <= k;x ++)
					add(f[u][j + 1][k - x], 1ll * now * fac[x] % mod * C[a[j + 1]][x] % mod * C[k][x] % mod);
				}
			}
		}
	}
	for (int j = 0;j <= m;j ++)
	add(ans, 1ll * f[n & 1][j][n - s[j]] * fac[n - s[j]] % mod);cout << ans;
}