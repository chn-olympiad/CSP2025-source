#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node{
	int u, v;
	long long w; 
}edge[N];
bool flag[15];
int cnt = 0;
long long self[15];
int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(x);
}
void merge(int x, int y){
	x = find(x);
	y = find(y);
	fa[y] = x;
}
bool cmp(node x, node y){
	return x.w > y.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		edge[++cnt] = {u, v, w};
		edge[++cnt] = {v, u, w};
	}
	for(int poi = 1; poi <= k; poi++){
		cin >> self[poi];
		for(int i = 1; i <= n; i++){
			long long w;
			cin >> w;
			edge[++cnt] = {n + poi, i, w};
			edge[++cnt] = {i, n + poi, w};
		}
	}
	sort(edge + 1, edge + cnt + 1, cmp);
	long long ans = 0;
	int sum = 0;
	for(int i = 1; i <= cnt; i++){
		int u = edge[i].u, v = edge[i].v;
		long long w = edge[i].w;
		if(find(u) != find(v)){
			merge(u, v);
			if(u > n) flag[u - n] = true;
			if(v > n) flag[v - n] = true;
			sum++;
			ans += w;
		}
		if(sum == n - 2) goto out;
	}
	out : for(int i = 1; i <= k; i++) if(flag[i]) ans += self[i];
	cout << ans; 
	return 0;
}
