#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5, inf = 1e16;
int n, m, k, cnt, ans, vis[N], a[N], f[N], dis[N], e[N][N];
struct edge{
	int u, v, w;
} E[N * N];
int find(int x){
	return (x == f[x] ? x : f[x] = find(f[x]));
}
bool cmp(edge i, edge j){
	return i.w < j.w;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)
				e[i][j] = inf;
	for(int i = 1, u, v, w; i <= m; i++){
		cin >> u >> v >> w;
		e[u][v] = e[v][u] = min(e[u][v], w);
	}
	for(int i = 1, x, pos; i <= k; i++){
		cin >> x;
		a[0] = inf, pos = 0;
		for(int j = 1; j <= n; j++) {
			cin >> a[j];
			if(a[pos] > a[j]) pos = j;
		}
		for(int j = 1; j <= n; j++)
			if(pos != j)
				e[pos][j] = e[j][pos] = min(e[pos][j], a[pos]  + a[j] + x);
	}
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			E[++cnt] = {i, j, e[i][j]};
	sort(E + 1, E + 1 + cnt, cmp);
	int tot = 0;
	for(int i = 1; i <= cnt; i++){
		int u = find(E[i].u), v = find(E[i].v);
		if(u == v) continue;
		f[u] = v, ans += E[i].w, tot++;
		if(tot == n - 1) break;
	}
	cout << ans;
	return 0;
}
//17:00我去，这题我好像做过，只要找到最小的点权并与其它所有点连边即可 
//cao，我离正解只差一个prim，我为什么不多复习一下啊，我的1=啊    
//prim我这辈子都不会放过你！！！！！！！！！！！！！
//做鬼我都要拉你一起（还是感谢CCF给了我会写的题，只可惜这个prim不识好歹） 
//不是n^2*k的我怎么也挂了
//得了，AFO吧
//生而为人，我很抱歉，我在考前对更优秀算法的忽视，以及对平时训练的懈怠造就了这一切
//我一步步走到现在，花费所有休息时间，交上了一份并不满意的答卷
//风景总是美丽的，尽管终点总不是那么美好 
