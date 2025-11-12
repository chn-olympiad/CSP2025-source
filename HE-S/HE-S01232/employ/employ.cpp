#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = (a), ed##i = (b); i <= ed##i; ++i)
#define rep(i, a, b) for (int i = (a), ed##i = (b); i >= ed##i; --i)
#define pb push_back
#define fi first
#define se second

const int LN = 100 + 7;
const int mod = 998244353;
typedef long long ll;

bool FISPOS;

int n, m, p[LN], c[LN], a[LN];
int ans, sum, tot[LN], C[LN][LN];
std::string s;

bool ENDPOS;

int add(int u, int v) { return u + v >= mod ? u + v - mod : u + v; }
void upa(int&u, int v) { u = add(u, v); }
int mul(ll u, ll v) { return u * v >= mod ? u * v % mod : u * v; }
void upm(int&u, int v) { u = mul(u, v); }
int MyPow(int a, int b) { int ans = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) ans = mul(ans, a); return ans; }
int nxt(int i, int j, int k) {
	rep(c, n, 1) if (j + i - c > k) return i;
	return 1;
}

int main() {
#ifndef DEBUG
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
#endif
	std::ios::sync_with_stdio(false),
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int c1 = clock(), cnt, tot, k;
	
	lep(i, 0, LN - 1) { C[i][0] = 1;
		lep(j, 1, i) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	std::cin >> n >> m >> s;
	lep(i, 1, n) a[i] = (s[i - 1] == '1'), sum += a[i];
	lep(i, 1, n) std::cin >> c[i], p[i] = i;
	
	if (sum < m) {
		std::cout << "0\n";
		return 0;
	}
	
	if (n <= 10) {
		do {
			cnt = tot = 0;
			lep(i, 1, n) {
				k = (cnt < c[p[i]]) and (a[i] > 0);
				if (k) ++tot; else ++cnt;
			}
			ans += (tot >= m);
		}while(std::next_permutation(p + 1, p + 1 + n));
		
		std::cout << ans << '\n';
	} else {
		int ans = 1;
		lep(i, 1, n) ans = mul(ans, i);
		std::cout << ans << '\n';
		return 0;
	}
//	 else {
//		int op = 0, nc;
//		f[op][0][m][nxt(n, 0, m)] = 0;
//		rep(i, n, 1) { op ^= 1, std::memset(f[op], 0, sizeof(f[op]));
//			lep(j, 0, n) lep(k, m, n) lep(c, 1, n + 1) if (f[op ^ 1][j][k][c]) {
//				if (tot[c] > n - i) {
//					upa(f[op][j][k][c], f[op ^ 1][j][k][c]), upa(f[op ^ 1][j + 1][k][c], f[op][j][k][c]);
//					upa(f[op][j][k][nxt(i, j, k)], f[op ^ 1][j][k][c]);
//				}
//			}
//		}
//	}
	
	std::cerr << clock() - c1 << " ms " << std::fabs(&FISPOS - &ENDPOS) / 1024 / 1024 << " MB\n";
	return 0;
}
