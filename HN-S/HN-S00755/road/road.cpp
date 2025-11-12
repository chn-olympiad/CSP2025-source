#include <bits/stdc++.h>
using namespace std;
const int N = 11010, M = 1200010;
struct ST{
	int x, y, z;
	bool operator < (const ST &X) const{
		return z < X.z;
	}
}a[M], e[M];
int parent[N], b[15], c[15][N], d[15], n, m, k;
long long ans = 1e18;
int g[1050][1050], vis[N], dis[N];

int find(int x){
	if(x != parent[x]) return parent[x] = find(parent[x]);
	return parent[x];
}

long long kruskal(int n, int m, int st, ST a[]){
	for(int i = 1; i <= n; i++) parent[i] = i;
	sort(a + 1, a + 1 + m);
	
	long long res = st, cnt = 0;
	for(int i = 1; i <= m; i++){
		if(find(a[i].x) != find(a[i].y)){
			parent[find(a[i].x)] = find(a[i].y);
			cnt++;
			res += a[i].z;
		} 
		if(cnt == n - 1) break;
	}
	return res;
}

long long prim(int n, long long st){
	for(int i = 1; i <= n; i++){
		dis[i] = 2e9, vis[i] = 0;
	}
	dis[1] = 0;
	long long r = st;
	for(int i = 1; i <= n; i++){
		int t = -1;
		for(int j = 1; j <= n; j++){
			if(vis[j] == 0 && (t == -1 || dis[j] < dis[t])) t = j;
		}
		vis[t] = 1;
		r += dis[t];
		for(int j = 1; j <= n; j++) dis[j] = min(dis[j], g[t][j]);
	}
	return r;
}

void dfs(int x){
	if(x == k + 1){
		long long nn = n, st = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i != j) g[i][j] = 1e9;
		for(int i = 1; i <= m; i++){
			g[e[i].x][e[i].y] = g[e[i].y][e[i].x] = min(g[e[i].x][e[i].y], e[i].z);
		}
		for(int i = 1; i <= k; i++){
			if(d[i] == 1){
				nn++;
				st += b[i];
				for(int j = 1; j <= n; j++){
					g[nn][j] = g[j][nn] = c[i][j];
				}
			}
		}
		ans = min(ans, prim(nn, st));
		return;
	}
	dfs(x + 1);
	d[x] = 1;
	dfs(x + 1);
	d[x] = 0;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].z);
	if(k == 0) printf("%lld", kruskal(n, m, 0, e));
	else{
		int flag = 0;
		for(int i = 1; i <= k; i++){
			scanf("%d", &b[i]);
			if(b[i] != 0) flag = 1;
			for(int j = 1; j <= n; j++){
				scanf("%d", &c[i][j]);
			}
		}
		if(flag == 1){
			dfs(1);
			printf("%lld", ans);
		}
		else{
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= n; j++){
					if(c[i][j] == 0){
						for(int u = 1; u <= n; u++){
							m++;
							e[m] = {j, u, c[i][u]};
						}
					}
				}
			}
			printf("%lld", kruskal(n, m, 0, e));
//			for(int i = 1; i <= k; i++){
//				for(int j = 1; j <= n; j++){
//					m++;
//					e[m] = {n + 1, j, c[i][j]};
//				}
//			}
//			n++;
//			printf("%lld", kruskal(n, m, 0, e));
		}
	}
	return 0;
} 
