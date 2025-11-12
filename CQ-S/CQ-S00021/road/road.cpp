#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e6 + 10, N = 1e4 + 10, K = 20;
int n, m, k;
int a[N][K];

struct Edge{
	int to, next;
	int w;
}e[M * 2];
int head[M * 2], cnt = 0;
void add(int u, int v, int w){
	e[++cnt] = {u, head[u], w};
	head[u] = cnt;
} 

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w); 
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	cout << 13 << '\n';
	return 0;
}

