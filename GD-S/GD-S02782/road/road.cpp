#include <iostream>
#include <algorithm>
#define endl '\n'
#define int long long
using namespace std;

const int N = 1e4 + 5, M = 2e6 + 5;

struct node {
	int u, v, w;
}edge[M], tmp[M];

int n, m, k, c[15], a[15][N], fa[N], minn = 1e18;
bool vis[15];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int x) {
	if(x == k + 1) {
		for(int i = 1; i <= n + 10; i++) fa[i] = i;
		for(int i = 1; i <= m; i++) edge[i] = tmp[i];
		int cnt = m;
		int sum = 0;
		for(int i = 1; i <= k; i++) {
			if(!vis[i]) continue;
			sum += c[i];
			for(int j = 1; j <= n; j++) {
				edge[++cnt] = {n + i, j, a[i][j]};
			}
		}
		sort(edge + 1, edge + cnt + 1, cmp);
		for(int i = 1; i <= cnt; i++) {
			int u = find(edge[i].u), v = find(edge[i].v), w = edge[i].w;
			if(u != v) {
				fa[u] = v;
				sum += w;
			}
		}
		minn = min(minn, sum);
		return;
	}
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
	dfs(x + 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i <= n + 10; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	bool flag = 1;
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		if(c[i] != 0) flag = 0;
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if(flag) {
		int cnt = m;
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
				edge[++cnt] = {n + i, j, a[i][j]};
			}
		}
		sort(edge + 1, edge + cnt + 1, cmp);
		int sum = 0;
		for(int i = 1; i <= cnt; i++) {
			int u = find(edge[i].u), v = find(edge[i].v), w = edge[i].w;
			if(u != v) {
				fa[u] = v;
				sum += w;
			}
		}
		cout << sum << endl;
	}
	else {
		if(k == 0) {
			sort(edge + 1, edge + m + 1, cmp);
			int sum = 0;
			for(int i = 1; i <= m; i++) {
				int u = find(edge[i].u), v = find(edge[i].v), w = edge[i].w;
				if(u != v) {
					fa[u] = v;
					sum += w;
				}
			}
			cout << sum << endl;
		}
		else {
			for(int i = 1; i <= m; i++) tmp[i] = edge[i]; 
			dfs(1);
			cout << minn << endl;
		}
	}
	return 0;
} 
