#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005;

int n, m, k;
int c[N], a[10][N];

int ecnt = 0;
ll head[N];
struct Edge{
	int to, next, w;
};
vector<Edge> e(N);

void add(int u, int v, int w) {
	e[++ecnt] = {u, v, w};
	head[u] = ecnt;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		
		add(u, v, w);
		add(v, u, w);
	}
	
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	return 0;
}
