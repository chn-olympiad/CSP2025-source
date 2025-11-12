#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 5, M = 5e7 + 5;
int n, m, k, w[N], a[15][N], fa[N];
bool vis[N];
struct node{
	int u, v, w;
}edge[M];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void uniset(int x, int y){
	x = find(x), y = find(y);
	if(x != y) fa[y] = x;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	for(int i = 1; i <= k; i++){
		cin >> w[i];
		vector<int> tmp;
		for(int j = 1; j <= n; j++) vis[j] = 1;
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 0){
				vis[j] = 0;
				tmp.push_back(j);
			}
		}
		for(int j = 1; j <= n; j++)
			if(vis[j]){
				for(int v: tmp){
					m++;
					edge[m].u = v;
					edge[m].v = j;
					edge[m].w = a[i][j];
				}
			}
	}
	sort(edge + 1, edge + m + 1, [](node x, node y){
		return x.w < y.w;
	});
	int ans = 0;
	for(int i = 1; i <= m; i++)
		if(find(edge[i].u) != find(edge[i].v)){
			ans += edge[i].w;
			uniset(edge[i].u, edge[i].v);
		}
	cout << ans;
	return 0;
}
//48pts
