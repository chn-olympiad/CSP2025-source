#include<bits/stdc++.h>
using namespace std;
struct Node {
	int x,w;
};
vector<vector<Node>>grid;
long long mincost = 1e9+5;
bool vis[100005];
bool vis1[100005];
int a[100005];
int b[100005];
int n,m,k;
bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (vis[i] != true){
			cnt ++;
		}
	}
	if (cnt == 1) {
		return true;
	}
	return false;
}
void dfs(int idx,long long cost) {
	
	int sz = grid[idx].size();
	for (int i = 0; i < sz; i ++) {
		if (!vis[grid[idx][i].x]) {
			vis[idx] = true;
			if (grid[idx][i].x >= n + 1) {
				dfs(grid[idx][i].x,cost+grid[idx][i].w + a[grid[idx][i].x]);
			}
			else {
				dfs(grid[idx][i].x,cost+grid[idx][i].w);
				if (check()) {
					mincost = min(mincost,cost+grid[idx][i].w);
				}
			}
			vis[idx] = false;
		}
	}
	
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	grid.resize(n + k + 1);
	for (int i = 1; i <= m; i ++) {
		int u,v,w;
		cin >> u >> v >> w;
		grid[u].push_back({v,w});
		grid[v].push_back({u,w});
	}
	for (int i = 1; i <= k; i ++) {
		int nx;
		cin >> nx;
		a[i + n] = nx;
		for (int j = 1; j <= n; j ++) {
			int cost;
			cin >> cost;
			grid[i + n].push_back({j,cost});
			grid[j].push_back({i + n,cost});
		}
	}
	dfs(1, 0);
	cout << mincost << endl;
	return 0;
}
