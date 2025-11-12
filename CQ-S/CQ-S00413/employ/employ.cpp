#include<bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = (x); i <= (y); ++i)
#define drep(i, x, y) for(int i = (x); i >= (y); --i)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
inline void Fin(string s) { freopen((s + ".in").c_str(), "r", stdin); }
inline void Fout(string s) { freopen((s + ".out").c_str(), "w", stdout); }
const int N = 505, mod = 998244353;
int n, m, cnt[N], c[N], a[N], p[N];
inline ll qp(ll a, ll b = mod - 2) {
	ll s = 1;
	for(; b; b >>= 1, a = a * a % mod)
		if(b & 1) s = s * a % mod;
	return s;
}
inline void inc(int &x, int y) { x += y, x = (x >= mod ? x - mod : x); }
ll fac[N], ifac[N];
inline ll C(int n, int m) {
	if(n < m) return 0ll;
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
inline void solve1() {
	rep(i, 1, n) p[i] = i;
	int ans = 0;
	do {
		int o = 0;
		rep(i, 1, n) {
			int x = p[i];
			if(o >= c[x] || !a[i]) ++o;
		}
		ans += (n - o >= m);
	} while(next_permutation(p + 1, p + 1 + n));
	cout << ans << '\n', exit(0);
}
inline void solve2() {
	ll ans = 0;
	vector<int> pos; int k = 0;
	rep(i, 1, n) if(a[i]) pos.pb(i), ++k;
	rep(i, 0, (1 << k) - 1) {
		
	}
	cout << (ans % mod + mod) % mod << '\n', exit(0);
}
inline void solve_m1() {
	int m = 0;
	vector<int> ps;
	rep(i, 1, n) if(a[i]) ps.pb(i);
	m = SZ(ps);
	vector<vector<int> > f(n + 2, vector<int>(n + 1));
	f[n + 1][0] = 1;
	drep(i, n, 1) {
		int val = 0;
		for(int x : ps) val += i <= x;
//		cout << "i : " << i << ' ' << val << '\n';
		rep(j, 0, m) {
			int w = 1;
			if(!f[i + 1][j]) continue;
			inc(f[i][j], f[i + 1][j]);
			rep(k, 1, min(m - j, cnt[i])) {
				if(val - j - k + 1 <= 0) break;
				w = (ll)w * (val - j - k + 1) % mod;
//				cout << "ad : " << "F : " << j + k << ' ' << f[i + 1][j] * C(cnt[i]) % mod << '\n';
				inc(f[i][j + k], f[i + 1][j] * fac[cnt[i]] % mod * ifac[cnt[i] - k] % mod * w % mod);
			}
		}
//	rep(j, 0, m) if(f[i][j]) cout << "val : " << i << " " << j << " = " << f[i][j] << '\n'; 
	}
//	cout << "F 1 : " << f[1][m] << '\n';
	ll ans = fac[n]; ans -= f[1][m] * fac[n - m] % mod;
	cout << (ans % mod + mod) % mod << '\n', exit(0);
}
inline void solve_all() {
	rep(i, 1, n) if(!c[i] || !a[i]) cout << 0 << '\n', exit(0);
	cout << fac[n] << '\n';
	exit(0);
}
inline void solve3() {
//	int c0 = cnt[0];
//	vector<vector<int> > f(n + 1, vector<int>(n + 1)), pw(n + 2, vector<int>(n + 1));
//	rep(i, 0, n + 1) {
//		pw[i][0] = 1;
//		rep(j, 1, n) pw[i][j] = (ll)pw[i][j - 1] * i % mod;
//	}
//	f[0][0] = 1; int o = n - cnt[0];
//	rep(i, 1, n) {
//		int v1 = min(c0 + 1, i), v2 = c0 + 1 - v1;
//		rep(j, 0, o - cnt[i]) {
//			rep(k, 0, cnt[i]) {
//				inc(f[i][j], (ll)f[i - 1][j] * fac[k] % mod * pw[v1][k] % mod * pw[v2][cnt[i] - k] % mod);
//			}
//		}
//	}
}
int main() {
	Fin("employ");
	Fout("employ");
	fastio; cin >> n >> m;
	fac[0] = ifac[0] = 1;
	rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % mod, ifac[i] = qp(fac[i]);
	if(1) {
		string s; cin >> s;
		rep(i, 0, n - 1) a[i + 1] = s[i] - '0';
	}
	rep(i, 1, n) cin >> c[i], ++cnt[c[i]];
	sort(c + 1, c + 1 + n);
	if(m == n) solve_all();
	if(n <= 10) solve1();
	if(m == 1) solve_m1();
	int cnt1 = 0;
	rep(i, 1, n) cnt1 += a[i];
	if(cnt1 == n) solve3();
	if(n - cnt1 < m) cout << 0 << '\n', exit(0);
	if(cnt1 <= 18) solve2();
	return 0;
}

