#include <bits/stdc++.h>

#define fir first
#define sec second

#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)

#define mkp make_pair
#define epb emplace_back
#define pb pop_back
#define sz(a) (int)(a.size())
#define All(a) begin(a), end(a)
#define mem(a, x) memset(a, x, sizeof(a))

using namespace std;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using vi = vector<int>;

template<typename T>
void chkmax(T &x, T y) {
	if (x < y) x = y;
}
template<typename T>
void chkmin(T &x, T y) {
	if (x > y) x = y;
}

const int kMod = 998244353;

int safeMod(ll x) {
	x %= kMod;
	if (x < 0) x += kMod;
	return x;
}
int mod(int x) {
	return (x >= kMod) ? x - kMod : x;
}
void add(int &x, int y) {
	x += y;
	if (x >= kMod) x -= kMod;
}
int neg(int x) {
	return (!x) ? 0 : -x + kMod;
}
int getPow(int x, int y) {
	int mul = 1;
	while (y) {
		if (y & 1) {
			mul = (ll)mul * x % kMod;
		}
		x = (ll)x * x % kMod;
		y >>= 1;
	}
	return mul;
}

const int kN = 505;

int n, m;

string s;

int pre1[kN];

int c[kN], cnt[kN];
int pre_cnt[kN];

int fac[kN], ifac[kN];

int choose(int x, int y) {
	if (x < y || y < 0) return 0;
	return (ll)fac[x] * ifac[y] % kMod * ifac[x - y] % kMod;
}

int f[2][kN][kN];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	cin >> s; s = " " + s;
	L(i, 1, n) {
		pre1[i] = pre1[i - 1];
		if (s[i] == '1') ++pre1[i];
	}
	L(i, 1, n) {
		cin >> c[i];
		++cnt[c[i]];
	}
	L(i, 0, n) {
		pre_cnt[i] = cnt[i];
		if (i) pre_cnt[i] += pre_cnt[i - 1];
	}
	fac[0] = ifac[0] = 1;
	L(i, 1, n) {
		fac[i] = (ll)i * fac[i - 1] % kMod;
		ifac[i] = getPow(fac[i], kMod - 2);
	}
	f[0][0][0] = 1;
	L(i, 1, n) {
		mem(f[i & 1], 0);
		L(j, 0, n) {
			L(k, 0, n) {
				if (f[i - 1 & 1][j][k]) {
					if (s[i] == '0') {
						L(l, 0, min(k, cnt[j + 1])) {
							f[i & 1][j + 1][k - l] = (f[i & 1][j + 1][k - l] 
							+ (ll)f[i - 1 & 1][j][k] * choose(k, l) % kMod * choose(cnt[j + 1], l) % kMod * fac[l]) % kMod;
						}
					} else {
						// to 1
						add(f[i & 1][j][k + 1], f[i - 1 & 1][j][k]);
						// to 0
						//cerr << "! " << i << ' ' << j << ' ' << k << ' ' << (ll)pre_cnt[j] - pre1[i - 1] + k << '\n';
						L(l, 0, min(k, cnt[j + 1])) {
							f[i & 1][j + 1][k - l] = (f[i & 1][j + 1][k - l] 
							+ f[i - 1 & 1][j][k] * ((ll)pre_cnt[j] - pre1[i - 1] + k) % kMod * choose(k, l) % kMod * choose(cnt[j + 1], l) % kMod * fac[l]) % kMod;
						}
					}
				}
			}
		}
		/*
		L(j, 0, n) {
			L(k, 0, n) {
				if (f[i][j][k]) {
					cerr << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << '\n';
				}
			}
		}
		*/
	}
	int ans = 0;
	L(now, 0, n - m) {
		L(k, 0, n) {
			ans = (ans + (ll)f[n & 1][now][k] * choose(n - pre_cnt[now], k) % kMod * fac[k]) % kMod;
		}
	}
	ans = (ll)ans * fac[n - pre1[n]] % kMod;
	cout << ans << '\n';
	return 0;
}
