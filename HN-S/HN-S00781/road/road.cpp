#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 2e6 + 10;
int n, m, k, v[N], f[N], tot;
bool vis[N];
long long ans = 1e18;
struct Edge {
	int u, v;
	long long w;
	bool operator <(const Edge &rhs) const {
		return w < rhs.w;
	}
} E[M];
int Find(int x) {
	return (x == f[x] ? x : f[x] = Find(f[x]));
}
long long calc() {
	long long res = 0, cnt = 0;
	for (int i = 1; i <= n + k; i ++) {
		f[i] = i;
		if (vis[i]) cnt ++;
	}
	for (int i = 1; i <= tot && cnt > 1; i ++) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if ((!vis[u]) || (!vis[v])) continue;
		int fu = Find(u), fv = Find(v);
		if (fu != fv) f[fv] = u, res += w, cnt --;
	}
	return res;
}
void dfs(int step) {
	if (step == n + k) {
		long long cost = 0;
		for (int i = n + 1; i <= n + k; i ++) {
			if (vis[i]) cost += v[i - n];
		}
		ans = min(ans, cost + calc());
		return ;
	}
	vis[step + 1] = 1;
	dfs(step + 1);
	vis[step + 1] = 0;
	dfs(step + 1);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++) {
		vis[i] = 1;
	}
	long long w;
	for (int i = 1, u, v; i <= m; i ++) {
		cin >> u >> v >> w;
		E[++ tot] = {u, v, w};
	}
	for (int i = 1; i <= k; i ++) {
		cin >> v[i];
		long long w;
		for (int j = 1; j <= n; j ++) {
			cin >> w;
			E[++ tot] = {j, n + i, w};
		}
	}
	sort(E + 1, E + tot + 1);
	dfs(n);
	cout << ans;
	return 0;
}

/*
又是我，

我要上迷惑行为大赏！！！还有伊蕾娜我老婆 

Luogu: OIerElaina
*/
