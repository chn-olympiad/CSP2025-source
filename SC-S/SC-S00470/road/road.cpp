//long long + scanf!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//dfs
#include <bits/stdc++.h>
using namespace std;
struct lll {
	long long u, w, c;
	lll (int _u, int _w, int _c = 0) {
		u = _u;
		w = _w;
		c = _c;
	}
};
bool flag[1011];
vector <lll> G[1011];
long long n, m, k;
//void bfs() {
//	queue <lll> q;
//	q.push(lll(0, 0));
//	while(!q.empty()){
//		
//	}
//}
long long f[1001][1001];
void dfs(int u, int ls) {
	for (int j = 0; j < G[u].size(); j++) {
		if(!f[u][G[u][j].u]){
			f[u][G[u][j].u] = max(f[u][G[u][j].u], f[u][ls] + G[ls][u].w);
			dfs(G[u][j].u, u);
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	//vector <long long> c;
	bool c[11];
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(lll(b, c));
		G[b].push_back(lll(a, c));
	}
	for(int i = 0; i < k; i++) {
		long long t;
		cin >> t;
		//c.push_back(t);
		for(int j = 0; j < n; j++) {
			long long te;
			cin >> te;
			G[j].push_back(lll(i, te, t));
			G[i].push_back(lll(j, te, t));
		}
	}
	for(int i = 0; i < n + k; i++) {
		dfs(i,i);
	}
	long long minn = 114514;
	for(int j = 0; j < n; j++) {
		long long maxn = 0;
		for(int i = 0; i < n; i++) {
			maxn = max(f[i][j], maxn);
		}
		minn = min(minn, maxn); 
	}
	cout << minn;
	return 0;
} 
