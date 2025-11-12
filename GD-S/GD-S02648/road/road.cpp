#include <bits/stdc++.h>
#define int long long

using namespace std;

constexpr int M = 1e6 + 7, N = 1e4 + 7;
struct Edge {
	int u, v, w;
}edges[M], edge2[M];

int n, m, k;
bool isopen[15];
int value[15];
int road[15][N];
int fa[N];
int idx, idx2;

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int find(int x) {
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	fa[x] = y;
}

int kruscal(int point) {
	
	int cnt = 0, cost = 0;
	for(int i = 1; i <= point; i++) fa[i] = i;
	sort(edge2 + 1, edge2 + idx2 + 1, cmp);
	for(int i = 1; i <= idx2; i++) {
		int u = edge2[i].u, v = edge2[i].v;
		u = find(u), v = find(v);
		if(u != v) {
			merge(u, v);
			cost += edge2[i].w;
			cnt += 1;
		}
	}
	if(cnt == point - 1) return cost;
	else return 1e18;
}

signed main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[++idx] = {u, v, w};
	}
	
	for(int i = 1; i <= k; i++) {
		cin >> value[i];
		for(int j = 1; j <= n; j++) {
			cin >> road[i][j];
		}
	}
	
	int minn = 1e18;
	for(int i = 0; i < (1 << k); i++) {
		memset(isopen, false, sizeof(isopen));
		idx2 = idx;
		int cost = 0;
		bitset<11> st = i;
		for(int j = 0; j < 10; j++) {
			if(st[j] == 1) {
				cost += value[k - j];
				isopen[k - j] = 1;
			}
		}
		
		for(int j = 1; j <= idx; j++) {
			edge2[j] = edges[j];
		}
		
		int cnt = 0;
		for(int j = 1; j <= k; j++) {
			if(isopen[j] == 1) {
				cnt += 1;
				for(int m = 1; m <= n; m++) {
					edge2[++idx2] = {n + cnt, m, road[j][m]};
				}
			}
		}
		
		minn = min(minn, cost + kruscal(n + cnt));
	}
	
	cout << minn;
	
	return 0;
} 
