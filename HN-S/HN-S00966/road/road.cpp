#include<bits/stdc++.h>
using namespace std;
const int kN = 1e4 + 7, kM = 1e6 + 7;
int n, m, k, fa[kN], c[kN];
bool vis[kN];
struct Edge{int u, v, w, id;}e[kM];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
void kru(){
	for(int i = 1; i <= n; ++i){
		fa[i] = i;
	}
	int cnt = 0, ans = 0;
	sort(e + 1, e + 1 + m, cmp);
	for(int i = 1; i <= m; ++i){
		int u = find(e[i].u), v = find(e[i].v);
		if(u == v){
			continue;
		}
		fa[u] = v;
		cnt++;
		if(vis[i] == 1){
			ans += c[e[i].id];
			vis[i] = 0;
		}
		ans += e[i].w;
		if(cnt == n - 1){
			break;
		}
	}
	cout << ans << "\n";
	return ;
}
signed main(){
	cin.tie(0) -> ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].id = 0;
	}
	++m;
	for(int i = 1; i <= k; ++i){
		cin >> c[i];
		for(int j = 1; j <= n; ++j){
			int x;
			cin >> x;
			if(e[m + 1].w > x){
				vis[e[i].id] = 0;
				e[m + 1] ={i, j, x, i};
				vis[i] = 1;
			}
		}
	}	
	kru();
	return 0;
}
/*
4 6 0
1 2 3
1 4 4
1 3 5
2 4 1
2 3 1
3 4 10

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
