#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[1 << 20];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1 ++)
template <typename T> inline void read(T &u) {
	u = 0; bool fl = 0; char c = gc();
	while (!isdigit(c)) fl |= c == '-', c = gc();
	while (isdigit(c)) u = (u << 3) + (u << 1) + (c ^ 48), c = gc();
	if (fl) u = ~(u - 1);
}
template <typename T> inline void write(T u) {
	static int stk[40], top = 0; if (u < 0) putchar('-'), u = ~(u - 1);
	while (u) stk[++ top] = u % 10, u /= 10;
	if (!top) putchar('0');
	while (top) putchar(stk[top --] ^ 48);
	return putchar('\n'), void();
}
#define eb emplace_back
#define mkpr make_pair
#define lowbit(i) (i & (-i))
#define mod 1000000007
const int N = 1e4 + 114;
const int M = 1e6 + 5;
typedef long long ll;
// pair <int, int > ed[M];
int fa[N], n, m, k, cnt, c[10];
inline int get(int u) {
	// cerr << u << ' ' << fa[u] << " get_warning!\n";
	return u == fa[u] ? u : fa[u] = get(fa[u]);
}
struct Ed {
	int u, v, w, flg;
	bool operator< (const Ed &x) const { return w < x.w; }
}e[N * 11], ed[M];
inline void solve() {
	read(n), read(m), read(k), cnt = 0;
	for (int i = 1; i <= m; ++ i) read(ed[i].u), read(ed[i].v), read(ed[i].w);
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	ll ct = 0;
	sort(ed + 1, ed + m + 1);
	for (int i = 1; i <= m; ++ i) {
		int u = ed[i].u, v = ed[i].v;
		u = get(u), v = get(v);
		if (u == v) continue;
		e[++ cnt] = (Ed) { u, v, ed[i].w, -1};
		ct += ed[i].w;
		fa[v] = u;
	}
	// cerr << ct << '\n';
	for (int i = 0; i < k; ++ i) {
		read(c[i]);
		for (int j = 1; j <= n; ++ j) {
			e[++ cnt] = (Ed) { i + n + 1, j, 0, i};
			read(e[cnt].w);
		}
	}
	sort(e + 1, e + cnt + 1);
	ll ans = 1e16;
	for (int S = 0; S < (1 << k); ++ S) {
		// cerr << "this\n";
		int BLK = n; ll w = 0;
		for (int i = 1; i <= n; ++ i) fa[i] = i;
		for (int i = 0; i < k; ++ i) if ((S >> i) & 1) fa[i + n + 1] = i + n + 1, BLK ++, w += c[i];
		for (int i = 1; i <= cnt && BLK > 1; ++ i)
			if (e[i].flg == -1 || ((S >> e[i].flg) & 1)) {
				int u = e[i].u, v = e[i].v;
				u = get(u), v = get(v);
				if (u == v) continue;
				// cerr << "Merge: " << u << ' ' << v << '\n';
				// cerr << "Merge: " << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
				w += e[i].w;
				fa[v] = u, BLK --;
			}
		ans = min(ans, w);
		// cerr << S << ' ' << w << '\n';
	}
	write(ans);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
	while (T --) solve();
}