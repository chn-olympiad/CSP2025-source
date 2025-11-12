#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int u,v;
	ll w;
} edge[1100011],g[1100011];

ll ans;
int n,m,k,l;
int t[11],fa[10021];
ll a[11][10011],c[11];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

bool cmp(const node &x,const node &y) {
	return x.w < y.w;
}

void dfs(int x,ll s) {
	if (x == k + 1) {
		l = m;
		for(int i=1;i<=n+k;i++)
			fa[i] = i;
		for(int i=1;i<=m;i++)
			g[i] = edge[i];
		for(int i=1;i<=k;i++) {
			if (!t[i])
				continue;
			for(int j=1;j<=n;j++) {
				l++;
				g[l].u = n + i;
				g[l].v = j;
				g[l].w = a[i][j]; 
			}
		}
		sort(g + 1,g + l + 1,cmp);
		ll res = s;
		for(int i=1;i<=l;i++) {
			int u = g[i].u;
			int v = g[i].v;
			ll w = g[i].w;
			if (find(u) != find(v)) {
				fa[find(u)] = find(v);
				res += w;
			}
		}
		ans = min(ans,res);
		return ;
	}
	t[x] = 0;
	dfs(x + 1,s);
	t[x] = 1;
	dfs(x + 1,s + c[x]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	int flag = 1;
	for(int i=1;i<=k;i++) {
		scanf("%lld",&c[i]);
		if (c[i] != 0)
			flag = 0;
		for(int j=1;j<=n;j++) {
			scanf("%lld",&a[i][j]);
			if (a[i][j] != 0)
				flag = 0;
		}
	}
	ans = 0x3f3f3f3f3f3f3f3fll;
	if (!flag || k <= 5)
		dfs(1,0ll);
	else
		ans = 0;
	printf("%lld",ans);
	return 0;
}
