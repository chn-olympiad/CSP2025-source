#include <bits/stdc++.h>
#define ll int
#define LL long long
#define pir pair <ll, ll> 
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
const ll maxn = 510, M = 5e6 + 10, mod = 998244353;
template <class T1, class T2>
void chkmin(T1 &x, const T2 y) { x = x < y? x : y; }
template <class T1, class T2>
void chkmax(T1 &x, const T2 y) { x = x < y? y : x; }
template <class T1, class T2>
void add(T1 &x, const T2 y) { x = x + y >= mod? x + y - mod : x + y; }
template <class T1, class T2>
void sub(T1 &x, const T2 y) { x = x < y? x - y + mod : x - y; }
template <class T1, class T2>
ll pls(const T1 x, const T2 y) { return x + y >= mod? x + y - mod : x + y; }
template <class T1, class T2>
ll mus(const T1 x, const T2 y) { return x < y? x - y + mod : x - y; }
template <class T>
void rd(T &x) {
	char ch; ll f = 0;
	while(!isdigit(ch = getchar()))
		if(ch == '-') f = 1;
	x = ch - '0';
	while(isdigit(ch = getchar()))
		x = (x << 1) + (x << 3) + ch - '0';
	if(f) x = -x;
}
using namespace std;

ll n, m, b[maxn], cnt[maxn], sum[maxn], f[maxn][maxn], g[maxn][maxn];
ll P[maxn][maxn], C[maxn][maxn], ans;
char a[maxn];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	rd(n), rd(m), scanf("%s", a + 1); m = n - m;
	P[0][0] = C[0][0] = 1;
	for(ll i = 1; i <= n; i++) {
		P[i][0] = C[i][0] = 1;
		for(ll j = 1; j <= i; j++)
			P[i][j] = 1ll * P[i][j - 1] * (i - j + 1) %mod,
			C[i][j] = pls(C[i - 1][j], C[i - 1][j - 1]);
	}
	for(ll i = 1; i <= n; i++) rd(b[i]), ++cnt[b[i]];
	for(ll i = n; i; i--) sum[i] = sum[i + 1] + cnt[i];
	f[0][sum[1]] = 1;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 0; j <= i && j <= m; j++)
			for(ll k = 0; k <= n - i + 1 && k <= sum[j + 1]; k++) {
				if(!f[j][k]) continue;
				ll u = sum[j + 1] - k, t = cnt[j + 1];
				for(ll x = max(0, t - k); x <= u && x <= t; x++)
					add(g[j + 1][k - (t - x)], 1ll * f[j][k] * P[u][x] %mod
					 * C[t][x] %mod * (n - i + 1 - k) %mod);
				if(a[i] == '0') {
					if(k) {
						++u;
						for(ll x = max(0, t - k + 1); x <= u && x <= t; x++)
							add(g[j + 1][k - 1 - (t - x)], 1ll * f[j][k] * P[u][x] %mod * C[t][x] %mod);
					}
				} else {
					if(k) add(g[j][k - 1], f[j][k]);
				}
			}
		memcpy(f, g, sizeof f), memset(g, 0, sizeof g);
	}
	for(ll i = 0; i <= m; i++) add(ans, 1ll * f[i][0] * P[sum[i + 1]][sum[i + 1]] %mod);
	printf("%d\n", ans);
	return 0;
}
