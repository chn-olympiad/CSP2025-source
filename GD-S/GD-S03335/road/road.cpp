#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 15;
const int MAXM = 1e6 + 5;
const int MAXK = 11;

int n, m, k;
struct Edge {
	int u, v; ll w;
} e[MAXM * 2];
ll c[MAXK], a[MAXK][MAXN];

namespace Method1 {

ll E[1015][1015];
bool f[MAXK];
ll Ans, ans;
ll dis[MAXN];
bool vis[MAXN];

void dfs(int d) {
	if (d > k) {
//		printf("check\n");
		ans = 0;
		memset(dis, 0x3f, sizeof dis);
		memset(vis, false, sizeof vis);
		int cnt = 0;
		for (int i = 1; i <= k; i++) {
			if (f[i]) ans += c[i], cnt++;
			else vis[n + i] = true;
		}
//			ans += f[i] * c[i], vis[n + i] = !f[i], cnt += f[i];
		vis[1] = true;
		for (int i = 1; i <= n + k; i++) dis[i] = E[1][i];
		for (int i = 1; i <= n + cnt - 1; i++) {
			int id = 1;
			for (int j = 1; j <= n + k; j++) {
				if (vis[j]) continue;
				if (vis[id]) id = j;
				if (dis[j] < dis[id]) id = j;
			}
			vis[id] = true, ans += dis[id];
			for (int j = 1; j <= n + k; j++) dis[j] = min(dis[j], E[id][j]);
		}
		Ans = min(Ans, ans);
//		printf("ans : %lld\n", ans);
		return;
	}
	f[d] = false;
	dfs(d + 1);
	f[d] = true;
	dfs(d + 1);
}

void Main() {
	memset(E, 0x3f, sizeof E);
	for (int i = 1; i <= m; i++)
		E[e[i].u][e[i].v] = E[e[i].v][e[i].u] = e[i].w;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			E[n + i][j] = E[j][n + i] = a[i][j];
	Ans = 1e18;
//	printf("!\n");
	dfs(1);
	printf("%lld\n", Ans);
}

} // Method1

namespace Method2 {

bool f[MAXK];
Edge E[MAXM * 2];
int ecnt;
ll Ans, ans;

int fa[MAXN];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int d) {
	if (d > k) {
		int cnt = 0;
		ans = 0, ecnt = m;
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		for (int i = 1; i <= m; i++) E[i] = e[i];
		for (int i = 1; i <= k; i++) {
			if (f[i]) {
				cnt++;
				ans += c[i];
				for (int j = 1; j <= n; j++)
					E[++ecnt] = { n + i, j, a[i][j]};
			}
		}
		sort(E + 1, E + 1 + ecnt, [](Edge x, Edge y) { return x.w < y.w; });
		for (int i = 1; i <= ecnt; i++) {
			int u = E[i].u, v = E[i].v; ll w = E[i].w;
			if (find(u) == find(v)) continue;
			ans += w, fa[find(u)] = find(v);
		}
		Ans = min(Ans, ans);
		return;
	}
	f[d] = false;
	dfs(d + 1);
	f[d] = true;
	dfs(d + 1);
}

void Main() {
	Ans = 1e18;
	dfs(1);
	printf("%lld\n", Ans);
}

} // Method2

bool check() {
	for (int i = 1; i <= k; i++) {
		if (c[i]) return false;
		bool flag = false;
		for (int j = 1; j <= n; j++)
			if (!a[i][j]) flag = true;
		if (!flag) return false;
	}
	return true;
}

namespace Method3 {

bool f[MAXK];
Edge E[MAXM * 2];
int ecnt;
ll Ans, ans;

int fa[MAXN];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int d) {
	if (d > k) {
		int cnt = 0;
		ans = 0, ecnt = m;
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		for (int i = 1; i <= m; i++) E[i] = e[i];
		for (int i = 1; i <= k; i++) {
			if (f[i]) {
				cnt++;
				ans += c[i];
				for (int j = 1; j <= n; j++)
					E[++ecnt] = { n + i, j, a[i][j]};
			}
		}
		sort(E + 1, E + 1 + ecnt, [](Edge x, Edge y) { return x.w < y.w; });
		for (int i = 1; i <= ecnt; i++) {
			int u = E[i].u, v = E[i].v; ll w = E[i].w;
			if (find(u) == find(v)) continue;
			ans += w, fa[find(u)] = find(v);
		}
		Ans = min(Ans, ans);
		return;
	}
//	f[d] = false;
//	dfs(d + 1);
	f[d] = true;
	dfs(d + 1);
}

void Main() {
	Ans = 1e18;
	dfs(1);
	printf("%lld\n", Ans);
}

} // Method3

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
	}
	if (check()) Method3::Main();
	else Method2::Main();
//	if (n <= 1000) Method1::Main();
	return 0;
}

