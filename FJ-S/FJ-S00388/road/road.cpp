#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 15;
struct edge{
	int u,v;
	long long w;
	bool operator < (const edge &s) const{
		return s.w > w;
	}
}edges[M + N * K];
long long w,c[K],ans;
int n,m,k,top,u,v,fa[N];
map <int,int> s[N];
long long res;
inline int find(int x){
	return (x == fa[x]?x:(fa[x] = find(fa[x])));
}
inline long long solve(int used){
	for (int i = 1;i <= n + k;++i) fa[i] = i;
	long long res = 0;
	int cnt = 0,nodes = n;
	for (int i = 1;i <= k;++i) if (used & (1 << (i - 1))) res += c[i],++nodes;
	for (int i = 1;i <= top;++i){
		if (edges[i].u > n) if (!(used & (1 << (edges[i].u - n - 1)))) continue;
		if (edges[i].v > n) if (!(used & (1 << (edges[i].v - n - 1)))) continue;
		int u = find(edges[i].u),v = find(edges[i].v);
		if (u == v) continue;
		fa[v] = u,++cnt,res += edges[i].w;
		if (cnt == nodes - 1) return res;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;++i){
		cin >> u >> v >> w;
		if (u > v) swap(u,v);
		if (s[u][v]) edges[s[u][v]].w = min(edges[s[u][v]].w,w);
		else edges[(s[u][v] = ++top)] = {u,v,w};
	}
	for (int i = 1;i <= k;++i){
		cin >> c[i];
		for (int j = 1;j <= n;++j){
			cin >> w;
			edges[++top] = {n + i,j,w};
		} 
	}
	sort(edges + 1,edges + 1 + top);
	ans = solve(0);
	for (int i = 1;i < (1 << k);++i) ans = min(ans,solve(i));
	cout << ans;
	return 0;
}
