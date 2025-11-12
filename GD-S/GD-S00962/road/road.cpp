#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1010 + 5;
const int M = 1e6 + 5;

int n, m, k, u, cnt, Ans = 1e18, h[11], c[11], fa[N];

struct node {
	int u, v, w, x;
} g[M];

bool cmp (node x, node y) {
	return x.w < y.w;
}

int find (int x) {
	if (x == fa[x]) return fa[x];
	fa[x] = find (fa[x]); return fa[x];
}

void merge (int x, int y) {
	fa[find (x)] = find (y);
}

int solve () {
	int x = 0, ans = 0, tl = 0;
	for (int i = 0; i < N; i ++) fa[i] = i;
	for (int i = 1; i <= k; i ++)
		if (h[i] == 1) tl ++;
	for (int i = 1; i <= cnt; i ++)	{
		if (x == n + tl - 1) break;
		if (h[g[i].x] == 0 || find (g[i].u) == find (g[i].v)) continue;
		merge (find (g[i].u), find (g[i].v));
		x ++; ans += g[i].w;
		if (ans >= Ans) break;
	}
	return ans;
}

void dfs (int t) {
	if (t >= k) {
		int sum = 0;
		for (int i = 1; i <= k; i ++)
			if (h[i] == 1) sum += c[i];
		Ans = min (Ans, solve () + sum);
		return;
	}
	h[t + 1] = 0; dfs (t + 1);
	h[t + 1] = 1; dfs (t + 1);
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k; h[0] = 1;
	for (int i = 1; i <= m; i ++)
		cin >> g[++ cnt].u >> g[cnt].v >> g[cnt].w;
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			cin >> u;
			g[++ cnt].u = n + i; g[cnt].v = j;
			g[cnt].w = u; g[cnt].x = i;
		}
	}
	sort (g + 1, g + cnt + 1, cmp);
	dfs (0); cout << Ans << "\n"; 
	return 0;
}
