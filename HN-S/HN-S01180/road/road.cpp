#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 50;
const int MAX_M = 1e6 + 50;
const int MAX_K = 15;

int n, m, k, tot, f[MAX_N], c[MAX_K];
long long ans;

struct Edge {
	int u, v, w, vis;
	Edge() {vis = 0; }
} e[MAX_M], tmp[MAX_M], a[MAX_K][MAX_N], b[MAX_K][MAX_N];

inline bool cmp(const Edge& x, const Edge& y) {
	return x.w < y.w;
}

inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

long long Kruskal(int cnt, int tag) {
	iota(f + 1, f + n + k + 1, 1);
	long long ans = 0;
	for (int i = 1; i <= tot && cnt > 1; i++) {
		int x = e[i].u, y = e[i].v;
		if (find(x) != find(y)) {
			f[f[x]] = f[y];
			ans += e[i].w;
			e[i].vis = tag;
			cnt--;
		}
	}	
	return ans;
}

void dfs(int i, int cnt, long long sum) {
	static int tag = 1;
	if (i > k || sum > ans)
		return ;
	dfs(i + 1, cnt, sum);
	
	copy(e + 1, e + tot + 1, b[i] + 1);
	
	int pre = tot;
	tot = 0;
	int p = 1, q = 1;
	while (p <= pre && q <= n)
		if (e[p].w < a[i][q].w)
			tmp[++tot] = e[p++];
		else
			tmp[++tot] = a[i][q++];
	while (p <= pre)
		tmp[++tot] = e[p++];
	while (q <= n)
		tmp[++tot] = a[i][q++]; 
	
	copy(tmp + 1, tmp + tot + 1, e + 1);
	cnt++, sum += c[i];
	ans = min(ans, sum + Kruskal(cnt, ++tag));
	
	int t = tot;
	tot = 0;
	for (int j = 1; j <= t; j++)
		if (e[j].vis == tag)
			e[++tot] = e[j];
	dfs(i + 1, cnt, sum);
	
	tot = pre;
	copy(b[i] + 1, b[i] + tot + 1, e + 1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j].w;
			a[i][j].u = n + i;
			a[i][j].v = j;
		}
		sort(a[i] + 1, a[i] + n + 1, cmp);	
	}

	sort(e + 1, e + m + 1, cmp);
	tot = m;
	ans = Kruskal(n, 1);
	tot = 0;
	for (int i = 1; i <= m; i++)
		if (e[i].vis == 1) 
			e[++tot] = e[i];
	dfs(1, n, 0);
	
	cout << ans << '\n';
	return 0;
}
