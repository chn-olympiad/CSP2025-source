#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k;
struct e {
	int u, v, w;
	bool operator<(const e& x) {
		return w < x.w;
	}
}edge[1000001];
struct t {
	int c, a[10001];
}town[11];
bool vis[10001];
int dfs() {
	int res = 0, cnt = 1, idx = 0;
	while(cnt != n) {
		e E = edge[idx++];
		if(!vis[E.u] || !vis[E.v]) {
			res += edge[idx].w;
			cnt++;
			vis[E.u] = vis[E.v] = true;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	sort(edge + 1, edge + m + 1);
	for(int i = 1; i <= k; i++) {
		cin >> town[i].c;
		for(int j = 1; j <= n; j++) cin >> town[i].a[j];
	}
	cout << kruskal();
	return 0;
}
