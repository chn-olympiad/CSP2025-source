#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+10, M  = 1e6+10;
ll n, m, k, tot = 1, fa[N], res, cnt, head[N], c[15][N];
struct edge{
	int to, nxt, w, u, of;
}e[M+N*15];
bool cmp(edge A, edge B){
	return A.w < B.w;
}
void add(int u, int v, int w, int of){
	e[tot].of = of;
	e[tot].to = v;
	e[tot].w = w;
	e[tot].u = u;
	e[tot].nxt = head[u];
	head[u] = tot++;
}
int find(int s){
	if (fa[s] == s) return s;
	return fa[s] = find(fa[s]);
}
bool vii[15];
int kruskal(){
	for (int i = 1; i <= k*n+m; i++){
		int uu = find(e[i].u), vv = find(e[i].to);
		if (uu != vv){
			//cout << e[i].to << " " << e[i].u << " " << e[i].of << " " << e[i].w << "\n";
			fa[uu] = vv;
			if (e[i].of){
				if (vii[e[i].of]) res -= c[e[i].of][0];
				else vii[e[i].of] = 1;
			}
			res += e[i].w;
			cnt++;
			if (cnt == n-1){
				return res;
			}
		}
	}
}
int main(){
	freopen("road.in", "r", stdin);
 	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		head[i] = -1;
		fa[i] = i;
	}
	for (int i = 1, u, v, w; i <= m; i++){
		cin >> u >> v >> w;
		add(u, v, w, 0);
	}
	int tmp;
	for (int i = 1; i <= k; i++){
		cin >> c[i][0];
		for (int j = 1, w; j <= n; j++){
			cin >> c[i][j];
		}
		for (int j = 1; j <= n; j++){
			for (int p = 1; p <= n; p++){
				if (j == p) continue;
				add(j, p, c[i][j] + c[i][0] + c[i][p], i);
			}
		}
	}
	sort(e+1, e+1+k*n+m, cmp);
	cout << kruskal();
	
	return 0;
}
