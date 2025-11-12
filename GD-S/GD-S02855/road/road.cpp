#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;
const int MAXM = 1e6+10;

int n, m, k;
int cnt;
struct edge
{
	int u, v, w, bl;
	bool operator<(const edge &x) const { return w < x.w;} 
}e[MAXM << 4];
int c[15];

int tot = 0;
int fa[MAXN];
int find(int u)
{
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

set<int> s;
int ans;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		e[++cnt] = {u, v, w, 0};
	}
	for(int t=1;t<=k;t++)
	{
		int a[MAXN];
		cin>>c[t];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<i;j++) e[++cnt] = {i, j, a[i]+a[j], t};
		}
	}
	sort(e+1, e+cnt+1);
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=cnt;i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w, id = e[i].bl;
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		tot++;
		ans += w;
		fa[fu] = fv;
		s.insert(id);
		if(tot == n-1) break;
	}
	for(auto p : s) ans += c[p];
	cout<<ans;
	return 0;
}
