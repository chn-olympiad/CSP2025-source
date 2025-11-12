#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int father[1000010];
int val[1000010];
struct node{
	int u,v,w;
}h[2000010],g[2000100],p[2000100];
int vis[1000010];
int cnt = 0;
bool cmp(node a,node b) {
	return a.w < b.w;
}
int find(int x) {
	if(father[x] != x) father[x] = find(father[x]);
	return father[x]; 
} 
int ans = 0,siz[1000010],t;
void solve(int id) {
	int res = 0;
	int l = 0;
	for(int i=1;i<=k;i++) {
		if(id&(1<<(i-1))) res += val[i],vis[n+i] = t,l ++;
	}
	if(res >= ans) return;
	for(int i=1;i<=n+k;i++) father[i] = i,siz[i] = 1;
	for(int i=1;i<=cnt;i++) {
		int u = g[i].u;
		int v = g[i].v;
		if(u > n && vis[u] != t) continue;
		if(v > n && vis[v] != t) continue;
		int x = find(u),y = find(v);
		if(x == y) continue;
		res += g[i].w;
		father[x] = y;
		siz[y] += siz[x];
		if(siz[y] == l + n) break;
	}
	ans = min(ans,res);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=2*n;i++) father[i] = i;
	for(int i=1;i<=m;i++) {
		cin >>h[i].u >> h[i].v >> h[i].w;
	}
	for(int i=1;i<=k;i++) {
		cin >> val[i];
		for(int j=1;j<=n;j++) {
			g[++cnt].u = n+i,g[cnt].v = j;
			cin >> g[cnt].w;
		}
	}
	sort(h+1,h+m+1,cmp);
	for(int i=1;i<=m;i++) {
		int x = find(h[i].u);
		int y = find(h[i].v);
		if(x == y) continue;
		g[++cnt].u = h[i].u;
		g[cnt].v = h[i].v;
		g[cnt].w = h[i].w;
		ans += h[i].w;
		father[x] = y;
	}
	sort(g+1,g+cnt+1,cmp);
	int maxn = (1<<k)-1;
	for(int i=1;i<=maxn;i++) {
		t ++;
		solve(i);
	}
	cout << ans << '\n';
	return 0;
}
