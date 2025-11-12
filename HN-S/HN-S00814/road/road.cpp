#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring> 
#define __Debug

using namespace std;
typedef long long ll;

const int N = 2e4 + 10;
const int M = 1e6 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll ans = INF;
int n, m, k;
int c[20], a[20][N]; 
bool viss[N], vis[N];
vector<pair<int, int>> edge[N];

ll Search(int ns, ll sum) {
	priority_queue<pair<int, int> > q;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	ll anss = sum;
	for (pair<int, int> cur : edge[1]) {
		if (!viss[cur.first]) continue;
		q.push(make_pair(-cur.second, cur.first));
	}
	int u, w, cnt = 1;
	while (!q.empty()) {
		u = q.top().second;
		w = -q.top().first;
		q.pop();
		if (vis[u]) continue;
		anss += w;
		if (anss >= ans) return ans;
		cnt++;
		vis[u] = true;
		if (cnt == ns){
			return anss;
		}
		for (pair<int, int> cur : edge[u]) {
			if (vis[cur.first] || !viss[cur.first]) continue;
			q.push(make_pair(-cur.second, cur.first));
		}
	}
	return anss;
}

ll cnt, sum;

void Dfs(int dep) {
	if (dep == k + 1) {
		ans = min(ans, Search(n + cnt, sum));
		return;
	}
	viss[dep + n] = true;
	cnt++, sum += c[dep];
	Dfs(dep + 1); 
	viss[dep + n] = false;
	cnt--, sum -= c[dep];
	Dfs(dep + 1);
	return ;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].emplace_back(make_pair(v, w));
		edge[v].emplace_back(make_pair(u, w));		
	}
	bool flag = true;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int val;
			cin >> val;
			edge[i + n].emplace_back(make_pair(j, val));
			edge[j].emplace_back(make_pair(i + n, val));
		}
		if (c[i] != 0) flag = false; 
	}
	for (int i = 1; i <= n; i++) viss[i] = true;
	if (flag) {
		ll ccc = 0;
		for (int i = n + 1; i <= n + k; i++) {
			viss[i] = true;	
			ccc += c[i];
		}
		ans = Search(n + k, ccc);
	}
	else Dfs(1);
	printf("%lld\n", ans);
	
	return 0; 
} 
