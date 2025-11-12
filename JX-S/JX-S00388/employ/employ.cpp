#include <bits/stdc++.h>
using namespace std;
// char *p1, *p2, buf[1 << 20];
// #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1 ++)
// template <typename T> inline void read(T &u) {
// 	u = 0; bool fl = 0; char c = gc();
// 	while (!isdigit(c)) fl |= c == '-', c = gc();
// 	while (isdigit(c)) u = (u << 3) + (u << 1) + (c ^ 48), c = gc();
// 	if (fl) u = ~(u - 1);
// }
// template <typename T> inline void write(T u) {
// 	static int stk[40], top = 0; if (u < 0) putchar('-'), u = ~(u - 1);
// 	while (u) stk[++ top] = u % 10, u /= 10;
// 	if (!top) putchar('0');
// 	while (top) putchar(stk[top --] ^ 48);
// 	return putchar('\n'), void();
// }
#define eb emplace_back
#define mkpr make_pair
#define lowbit(i) (i & (-i))
#define mod 998244353
const int N = 505;
inline void add(int &u, int v) { if ((u += v) >= mod) u -= mod;}
const int M = 18;
int n, m, f[M][1 << M], c[N];
vector <int > S[M]; // guan jian ci.
char s[N];
inline void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++ i) cin >> s[i];
	for (int i = 0; i < n; ++ i) cin >> c[i];
	if (n <= 18) {
		for (int j = 0; j < (1 << n); ++ j) S[__builtin_popcount(j)].emplace_back(j);
		f[0][0] = 1;
		for (int j = 0; j < n; ++ j) {
			for (auto zt : S[j]) {
				for (int fail = 0; fail <= j; ++ fail) {
					if (!f[fail][zt]) continue;
					for (int i = 0; i < n; ++ i) {
						if ((zt >> i) & 1) continue;
						int nxt = zt ^ (1 << i), nxtfail = fail;
						if (s[j] == '0' || fail >= c[i]) nxtfail ++;
						add(f[nxtfail][nxt], f[fail][zt]);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n - m; ++ i) add(ans, f[i][(1 << n) - 1]);
		cout << ans << '\n';
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = 1;
	while (T --) solve();
}