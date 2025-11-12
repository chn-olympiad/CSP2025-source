#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 5;
struct Edge {
	int x, y, w;
	friend bool operator<(Edge x, Edge y) {
		return x.w < y.w;
	}
} e[maxn * 100], p[maxn], q[maxn], tp[15][maxn];
int ans = 9e18, n, m, k, tot;
struct dsu {
	int pre[maxn + 10];
	void init() {
		for (int i = 1; i <= n + k; i++)
			pre[i] = i;
	}
	int fnd(int x) {
		return (pre[x] == x ? x : pre[x] = fnd(pre[x]));
	}
} tree;
void kruskal1() {
	sort(e + 1, e + m + 1);
	tree.init();
	int res = 0;
	for (int i = 1; i <= m; i++) {
		int x = tree.fnd(e[i].x), y = tree.fnd(e[i].y);
		if(x == y)
			continue;
		tree.pre[x] = y, res += e[i].w;
		p[++tot] = e[i];
	}
	ans = min(ans, res);
}
int val[maxn], a[15][maxn], c[maxn];
void dfs(vector<Edge> &e, int d, int t) {
//	cout << d << " " << t << endl;
	if(d > k) {
		int s = 0;
		for (int i = 0; i < e.size(); i++)
			s += e[i].w;
		ans = min(ans, s + t);
		return ;
	}
	dfs(e, d + 1, t);
	vector<Edge> res;
	tree.init();
	int p1 = 0, p2 = 1;
	t += c[d];
	for (int i = 1; i <= e.size() + n; i++) {
		Edge rest;
		if((p1 < e.size()) && (p2 > n || e[p1].w < tp[d][p2].w))
			rest = e[p1++];
		else
			rest = tp[d][p2++];
		int x = tree.fnd(rest.x), y = tree.fnd(rest.y);
		if(x == y)
			continue;
		tree.pre[x] = y, res.push_back(rest);
	}
	dfs(res, d + 1, t);
}
int read() {
	int sum = 0; char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
		sum = sum * 10 + c - '0', c = getchar();
	return sum;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) 
		e[i].x = read(), e[i].y = read(), e[i].w = read();
	kruskal1();
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++)
			a[i][j] = read(), tp[i][j] = {i + n, j, a[i][j]};
		sort(tp[i] + 1, tp[i] + n + 1);
	}
	vector<Edge> e;
	for (int i = 1; i <= tot; i++)
		e.push_back(p[i]);
	dfs(e, 1, 0);
	cout << ans << endl;
	return 0;
} 
