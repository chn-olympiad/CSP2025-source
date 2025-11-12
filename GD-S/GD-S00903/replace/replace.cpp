#include <bits/stdc++.h>
#define fst first
#define scd second
#define pb emplace_back
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') {
		f |= (c == '-');
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return f ? -x : x;
}

const int maxn = 200100;
const int maxm = 5000100;

int n, m, ch[maxm][26], fail[maxm], nt, f[maxm], de[maxm], fa[maxm], dep[maxm], q[maxm];
char s[maxm], t[maxm], a[maxm];
bool b[maxm << 1];

inline void build() {
	int hd = 1, tl = 0;
	for (int i = 0; i < 26; ++i) {
		if (ch[0][i]) {
			q[++tl] = ch[0][i];
		}
	}
	while (hd <= tl) {
		int u = q[hd++];
		f[u] += f[fail[u]];
		dep[u] = dep[fail[u]] + 1;
		if (b[dep[u]]) {
			fa[u] = fail[u];
		} else {
			fa[u] = fa[fa[fail[u]]];
		}
		for (int i = 0; i < 26; ++i) {
			if (ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				q[++tl] = ch[u][i];
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
}

void solve() {
	n = read();
	m = read();
	b[1] = 1;
	int x = 1;
	while (x <= 5000000) {
		for (int i = 1; i <= x; ++i) {
			b[i + x] = b[i];
		}
		x = x * 2 + 1;
	}
	for (int _ = 0; _ < n; ++_) {
		scanf("%s%s", s + 1, t + 1);
		int len = strlen(s + 1), tot = 0;
		for (int i = 1; i <= len; ++i) {
			a[++tot] = s[i];
			a[++tot] = t[i];
		}
		int p = 0;
		for (int i = 1; i <= tot; ++i) {
			if (!ch[p][a[i] - 'a']) {
				ch[p][a[i] - 'a'] = ++nt;
				de[nt] = de[p] + 1;
			}
			p = ch[p][a[i] - 'a'];
		}
		++f[p];
	}
	build();
	while (m--) {
		scanf("%s%s", s + 1, t + 1);
		int len = strlen(s + 1), le = strlen(t + 1);
		if (len != le) {
			puts("0");
			continue;
		}
		int x = 0, y = 0, p = 0;
		ll ans = 0;
		while (x < len && s[x + 1] == t[x + 1]) {
			++x;
		}
		while (y < len && s[len - y] == t[len - y]) {
			++y;
		}
		for (int i = 1; i <= len; ++i) {
			p = ch[p][s[i] - 'a'];
			p = ch[p][t[i] - 'a'];
			if (len - i <= y) {
				int u = p;
				while (1) {
					if (fa[u] && i - de[fa[u]] / 2 <= x) {
						u = fa[u];
					} else if (fail[u] && i - de[fail[u]] / 2 <= x) {
						u = fail[u];
					} else {
						break;
					}
				}
				if (u && i - de[u] / 2 <= x) {
					u = fail[u];
				}
				ans += f[p] - f[u];
			}
		}
		printf("%lld\n", ans);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
