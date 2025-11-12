#include <bits/stdc++.h>
#define ll long long
#define pub push_back
using namespace std;
const int M = 1e6 + 1e5 + 5, N = 1e4 + 5;
int n, m, k, jz[15][N], xm, f[N], xz, d[N];
ll ans, zmin = 1e18;
struct Node2{
	int sz, bh, u, v;
};
bool operator < (Node2 t1, Node2 t2){
	return t1.sz < t2.sz;
}
priority_queue <Node2> q;
//struct Node2{
//	int to, w;
//};
//vector <Node2> ed[N];
struct Node{
	int u, v, w;
} a[M], tmp[M];
bool cmp(Node t1, Node t2){
	return t1.w < t2.w;
}
int zfind(int x){
	if(f[x] == x) return x;
	f[x] = zfind(f[x]);
	return f[x];
}
bool he(int x, int y){
	int zxx = zfind(x), zxy = zfind(y);
	if(zxx != zxy){
		f[zxx] = zxy;
		return 1;
	}
	return 0;
}
void scs(){
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1;i <= n;i++) f[i] = i;
	int cnt = 0;
	for(int i = 1;i <= m;i++){
		if(he(a[i].u, a[i].v)){
//			ed[a[i].u].pub((Node2) {a[i].v, a[i].w}), ed[a[i].v].pub((Node2) {a[i].u, a[i].w});
			ans += a[i].w, q.push((Node2) {a[i].w, 0, a[i].u, a[i].v});
			d[a[i].u]++, d[a[i].v]++;
			if(ans > zmin) break;
			if(++cnt == n - 1){
				break;
			}
		}
	}
}
//void dfs(int x, int fa){
//	dep[x] = dep[fa] + 1, ft[x][0] = fa, maxd = max(maxd, dep[x]);
//	for(auto bl : ed[x]){
//		int i = bl.to, dq = bl.w;
//		if(i != fa){
//			qz[i] = qz[x] + dq, d[i] = max(d[i], dq);
//			for(int j = 1;j <= k;j++) qz2[i][j] = qz2[x][j] + jz[j][i];
//			dfs(i, x);
//			d[x] = max(d[x], dq);
//		}
//	}
//}
//int lca(int u, int v){
//	if(dep[u] < dep[v]) swap(u, v);
//	while(dep[u] > dep[v]){
//		u = ft[u][lg[dep[u] - dep[v]]];
//	}
//	if(u == v) return u;
//	for(int i = lg[dep[u]];i >= 0;i--){
//		if(ft[u][i] != ft[v][i]){
//			u = ft[u][i], v = ft[v][i];
//		}
//	}
//	return ft[u][0];
//}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("road1.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		tmp[i] = a[i];
	}
	for(int i = 1;i <= k;i++){
		for(int j = 0;j <= n;j++){
			cin >> jz[i][j];
		}
	}
	scs();
//	for(int i = 1;i <= k;i++){
//		sort(jz[i] + 1, jz[i] + n + 1);
//		bool pd = 0;
//		ll dans = ans;
//		for(int j = 2;j <= n;j++){
//			if(n - 1 + j >= n + 1){
//				if(ans - q.top().sz + jz[i][j] + jz[i][1] + jz[i][0] < dans && q.top().sz != i && d[q.top().u] > 1 && d[q.top().v] > 1){
//					pd = 1;
////					cout << q.top().sz<<" "<<i<<"\n";
//					d[q.top().u]--, d[q.top().v]--, dans = ans - q.top().sz + jz[i][j] + jz[i][1] + jz[i][0], ans = (ans - q.top().sz) + jz[i][j];
//					cout << ans << "\n";
//					q.pop(), q.push((Node2) {jz[i][j], i}), d[i]++, d[j]++; 
//				}
//			}
//		}
//		if(pd) ans += jz[i][1] + jz[i][0];
//		if(pd) q.push((Node2) {jz[i][1], i}), d[i]++, d[jz[i][1]]++;
//	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
3 
*/
