#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, sum;
struct node {
	int u, v, w;
};
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	vector<node> edge(m + 1), ans;
	vector<int> fa(n + 1), c(k + 1);
	vector<vector<int>> a(k + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	for(int i = 1; i <= m; ++ i) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	for(int i = 1; i <= k; ++ i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++ j) cin >> a[i][j];
	}
	sort(edge.begin(), edge.end(), [](node a, node b) -> bool { return a.w < b.w; });
	auto query_fa = [&](int x, auto&& query_fa) -> int {
		return x == fa[x] ? x : (fa[x] = query_fa(fa[x], query_fa));
	};
	auto hebing = [&](int u, int v) -> bool {
		if(query_fa(u, query_fa) == query_fa(v, query_fa)) return false;
		fa[v] = fa[u];
		return true;
	};
	for(int i = 1, cnt = 0; i <= m; ++ i) { //Why dev_c++ can't use the auto+[]!!!!!
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if(hebing(u, v)) {
			ans.push_back(edge[i]);
			++ cnt;
			if(cnt == n - 1) break;
		}
	}
	for(int i = 0; i < ans.size(); ++ i) { //mei kai er du
		int u = ans[i].u, v = ans[i].v, w = ans[i].w;
		for(int j = 1; j <= k; ++ j)
			w = min(w, a[j][u] + a[j][v] + c[j]);
		sum += w;
	}
	cout << sum << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
