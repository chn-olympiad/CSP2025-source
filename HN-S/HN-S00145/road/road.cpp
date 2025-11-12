#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5 , M = 2e6 + 5;
/*
struct Edge{
	int n , v , w;
}edge[M << 1];
int head[N] , eid;
void eadd(int u , int v , int w) {
	edge[++ eid].n = head[u] , edge[eid].v = v , edge[head[u] = eid].w = w;
}
*/
struct node{
	int u , v , w;
}e[M];
int n , m , k , c[N] , a[12][N] , fa[N] , sta[N] , top;
bool cmp(node x , node y) {
	return x.w < y.w;
}
int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int tot = m , flag = 0;
	for(int i = 1 ; i <= k ; i ++) {
		cin >> c[i];
		if(c[i] > 0) flag = 1;
		for(int j = 1 ; j <= n ; j ++) {
			cin >> a[i][j];
			tot ++;
			e[tot].u = j , e[tot].v = n + i , e[tot].w = a[i][j];
		}
	}
	sort(e + 1 , e + tot + 1 , cmp);
	long long ans = 0;
	if(!flag) {
		for(int i = 1 ; i <= n + k ; i ++) fa[i] = i;
		for(int i = 1 ; i <= tot ; i ++) {
			int u = e[i].u , v = e[i].v , w = e[i].w;
			if(find(u) == find(v)) continue;
			fa[find(u)] = find(v);
			ans += w;
		}
		cout << ans << '\n';
		return 0;
	}
	int nm = (1 << k);
	ans = 0x3f3f3f3f3f3f3f3f;
	for(int s = 0 ; s < nm ; s ++) {
		long long now = 0;
		for(int i = 1 ; i <= n + k ; i ++) fa[i] = i;
		for(int i = 1 ; i <= tot ; i ++) {
			int u = e[i].u , v = e[i].v , w = e[i].w;
			if(v > n && (!(s & (1 << (v - n - 1))))) continue;
			if(find(u) == find(v)) continue;
			fa[find(u)] = find(v);
			now += w;
		}
		for(int i = 0 ; i < k ; i ++) {
			if(s & (1 << i)) now += c[i + 1];
		}
		ans = min(ans , now);
	}
	cout << ans;
	return 0;
}


