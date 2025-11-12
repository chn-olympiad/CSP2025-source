#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 1, M = 1e6 + 1e5 + 11, K = 11;
ll fa[N * K + M], ans = 1e16, n, m, t, sum, kk;
ll a[K][N];
bool flag[K];
struct node{
	ll u, v, w;
}g[M], g1[M];
ll findfa(int x){
	if(fa[x] == x) return x;
	fa[x] = findfa(fa[x]);
	return fa[x];
}
bool cmp(node x, node y){
	return x.w < y.w;
}
void mintree(){
	for(ll i = 1;i <= t;i ++) fa[i] = i;
	sort(g + 1, g + t + 1, cmp);
	for(ll i = 1;i <= t;i ++){
		if(findfa(g[i].u) != findfa(g[i].v)){
			fa[fa[g[i].v]] = fa[g[i].u]; sum += g[i].w;
			ll q = fa[1];
			if(sum >= ans) return ;
			bool fl = 0;
			for(int i = 2;i <= n;i ++) if(findfa(i) != q){fl = 1; break;}
			if(fl == 0) break;
		}
	}
}
void dfs(ll x){
	if(x == kk + 1){
		for(ll i = 1;i <= m;i ++) g[i].u = g1[i].u, g[i].v = g1[i].v, g[i].w = g1[i].w;
		ll tt = t;
		t = m; sum = 0;
		for(ll i = 1;i <= kk;i ++){
			if(flag[i] == 1) sum += a[i][0];
			else continue;
			if(sum >= ans) return ;
			for(ll j = 1;j <= n;j ++){
				t ++; g[t].u = (i + 1) * n; g[t].v = j; g[t].w = a[i][j];
			}
		}
		for(ll i = t + 1;i <= tt;i ++) g[i].u = g[i].v = g[i].w = 0;
		mintree();
		ans = min(ans, sum);
		return ;
	}
	flag[x] = 1; dfs(x + 1);
	flag[x] = 0; dfs(x + 1);
	return ;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out" ,"w", stdout);
	cin >> n >> m >> kk;
	for(ll i = 1;i <= m;i ++) scanf("%lld %lld %lld", &g1[i].u, &g1[i].v, &g1[i].w);
	for(ll i = 1;i <= kk;i ++) for(ll j = 0;j <= n;j ++) scanf("%lld", &a[i][j]);
	dfs(1);
	cout << ans;
	return 0;
}
