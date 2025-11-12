#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename _Tp>
void read(_Tp &res) {
	res = 0; bool f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		f |= (ch == '-'), ch = getchar();
	while (ch >= '0' && ch <= '9')
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	res = f ? -res : res;
}
constexpr int MAXN = 1e4 + 20;
constexpr int MAXM = 1e6 + 1e5 + 5;
constexpr int LOG = 22;
struct mp{
	struct ed{
		int to, nxt, val; 
	}edge[MAXM << 1];
	int head[MAXN];
	int tot;
	void add_edge(int u, int v, int w) {
		edge[++tot].to = v, edge[tot].val = w, edge[tot].nxt = head[u], head[u] = tot;
	}
}ma[2];
struct Edge{
	int u, v;
	ll w;
	bool operator < (const Edge& b)const {
		return w < b.w;
	}
}e2[MAXM], e[MAXM];
int st[MAXN][LOG];
int c[15];
ll a[15][MAXN];
int fa[MAXN];
int pos;
int n, m, k;
ll cost;
ll ans = 0x3f3f3f3f3f3f3f3f;
int tot1, tot2;
int find(int x) {
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)
		fa[fx] = fy;
}
void MST() {
	for (int i = 1; i <= tot2; ++i)
		fa[i] = i;
	sort(e + 1, e + tot1 + 1);
	int cnt = 0;
	for (int i = 1; i <= tot1; ++i) {
		if (find(e[i].u) != find(e[i].v))
			merge(e[i].u, e[i].v), ++cnt, cost += e[i].w;
		if (cnt == tot2 - 1)
			return;
	}
}
int flag1 = 1;
int main() {
#if DEBUG
	freopen(".\\road\\road4.in", "r", stdin);
	freopen(".\\road\\road4.out", "w", stdout);
#else
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	int begin_t = clock();
	read(n), read(m), read(k);
	for (int i = 1; i <= m; ++i)
		read(e2[i].u), read(e2[i].v), read(e2[i].w);
	for (int i = 1; i <= k; ++i) {
		read(c[i]);
		if (c[i] != 1)
			flag1 = 0;
		for (int j = 1; j <= n; ++j) {
			read(a[i][j]);
			if (a[i][j] != 1)
				flag1 = 0;
		}
	}
	if (flag1)
		return cout << 0, 0;
	for (int i = 0; (i < (1 << k)) && (clock() - begin_t <= 0.90 * CLOCKS_PER_SEC); ++i) {
		memcpy(e + 1, e2 + 1, sizeof(Edge) * m);
		cost = 0, tot1 = m, tot2 = n;
		for (int j = 0; j < k ; ++j)
			if ((i >> j) & 1) {
				cost += c[j + 1];
				++tot2;
				for (int l = 1; l <= n; ++l) 
					e[++tot1] = {tot2, l, a[j + 1][l]};
			}
		MST();
		ans = min(ans, cost);
	}
	cout << ans;
	return 0;
}