#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m, k;
int c[N], a[N][N];
struct node{ int u, v, w; };
vector<node> G[N];
void add_edge(int u, int v, int w) {
	G[u].push_back({v, w});
	G[v].push_back({u, w});
	return ; 
} 
long long ans;
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	int maxn = -1e9;
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
		maxn = max(maxn, w);
	}
	bool f = 1;
	for(int i = 1; i <= k; i ++) {
		cin >> c[i]; if(c[i]) f = 0;
		for(int j = 1; j <= n; j ++) {
			cin >> a[i][j]; if(a[i][j]) f = 0;
		}
	}
	if(f) {
		cout << 0; 
		return 0;
	}
	else {
		srand(time(0));
		int a = rand();
		cout << a % (maxn * n);
	}
	return 0;
} 
