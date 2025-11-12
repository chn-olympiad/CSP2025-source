#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 20;
const int MAXM = 1e6 + 10;

/*
直觉上是个魔改过的最小生成树
暂时不会。
哦是不是把原图最小生成树的边保留下来即可。
写一发看看。
我擦咋对了。
然后这个 log nk 应该能用魔幻手法改成 log k。我试试看。
成功了。但是能不能跑过就是另一回事了 
时间复杂度 O(mlogm + 2^k*nklogk)。
神机保佑我冲过去。。。
哦数据造的好的话后面可以没掉个 k，保佑数据造的好。。。 
*/

inline 
void read(int &x) {
	x = 0; char c = getchar();
	for (; isspace(c); c = getchar());
	for (; isdigit(c); x = x * 10 + c - '0', c = getchar());
}

struct edge {
	int u, v, w;
	edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
	bool operator < (const edge &rhs) const { return w < rhs.w; }
} e[MAXM], ta[11][MAXN]; int tot;

struct node {
	int id, pos; edge e;
	node(int id = 0, int pos = 0, edge e = 0) : id(id), pos(pos), e(e) {}
	bool operator < (const node &rhs) const { return rhs.e < e; }
};

int n, m, k, fa[MAXN], c[11], a[11][MAXN], len[11]; ll sum, ans;

int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++) read(e[i].u), read(e[i].v), read(e[i].w);
	for (int i = 1; i <= k; i++) {
		read(c[i]);
		for (int j = 1; j <= n; j++) read(a[i][j]);
		for (int j = 1; j <= n; j++) ta[i][j] = edge(n + i, j, a[i][j]);
		sort(ta[i] + 1, ta[i] + n + 1), len[i] = n;
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue; ans += e[i].w;
		fa[v] = u, ta[0][++tot] = e[i];
		if (tot == n - 1) break;
	}
	len[0] = tot;
	for (int s = 1; s < 1 << k; s++) {
		tot = m, sum = 0;
		priority_queue<node> q; q.emplace(0, 1, ta[0][1]);
		for (int i = 1; i <= k; i++) {
			if (s >> i - 1 & 1) sum += c[i], q.emplace(i, 1, ta[i][1]);
		}
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		int cnt = n + __builtin_popcount(s) - 1;
		for (node x; !q.empty(); ) {
			x = q.top(), q.pop();
			if (x.pos < len[x.id]) q.emplace(x.id, x.pos + 1, ta[x.id][x.pos + 1]);
			int u = find(x.e.u), v = find(x.e.v);
			if (u != v) {
				sum += x.e.w, fa[v] = u, cnt--;
				if (!cnt) break;
			}
		}
		ans = min(ans, sum);
	}
	printf("%lld", ans);
}
