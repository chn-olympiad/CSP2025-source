#include<bits/stdc++.h>
using namespace std;
const int N = 2e6, M = 3e4, inf = 1e9;
int n, m, k, c[M], c1[M][15], fa[N];
long long ans = inf;
struct Node{
	int u, v, w;
}node[N], node1[N];
inline bool cmp(Node x, Node y){
	return x.w < y.w;
}
inline int find_root(int x){
	if(fa[x] == x) return fa[x];
	fa[x] = find_root(fa[x]);
	return fa[x];
}
inline void init(){
	for(int i = 1;i <= n + k;i ++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i ++){
		node1[i].u = node[i].u;
		node1[i].v = node[i].v;
		node1[i].w = node[i].w;
	}
}
inline long long solve(int cnt){
//	cout << m+cnt*n << endl;
	sort(node1+1,node1+m+cnt*n+1,cmp);
	int cntt = 0;
	long long ans1 = 0;
	int cc = m+cnt*n;
	for(int i = 1;i <= cc; i++){
		if(cntt == n+cnt-1) break;
		int x = node1[i].u, y = node1[i].v;
		int tx = find_root(x), ty = find_root(y);
		if(tx == ty)continue;
		cntt ++;
		ans1 += node1[i].w;
		fa[tx] = ty;
	}
	return ans1;
}
inline void dfs(int x,long long sum, int cnt){
	if(x == k+1){
		init();
		ans = min(solve(cnt)+sum, ans);
		init();
		return;
	}
	for(int i = m + cnt*n + 1;i <= m + (cnt+1)*n;i ++){
		node1[i].u = x + n, node1[i].v = i - m - cnt*n, node1[i].w = c1[x][i - m - cnt*n];
//		cout << node1[i].u <<" "<< node1[i].v <<" "<< node1[i].w <<" \n";
	}
	dfs(x+1, sum + c[x], cnt+1);
	dfs(x+1, sum, cnt);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n+k;i ++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i ++){
		cin >> node[i].u >> node[i].v >> node[i].w;
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> c1[i][j];
		}
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}