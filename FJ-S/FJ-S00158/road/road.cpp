#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
}b[1000005],g[2000005];
int n,m,k,fa[10050],c[15],a[15][10005],ans = 1e18;
bool vis[15],flag = true;
int find_fa(int x){return fa[x] == x?x:fa[x] = find_fa(fa[x]);}
bool cmp(edge x,edge y){return x.w < y.w;}
int kruskal()
{
	int id = m,res = 0,tot = 0,now = n;
	for(int i = 1;i <= m;i++) g[i] = b[i];
	for(int i = 1;i <= k;i++)
	{
		if(vis[i])
		{
			res += c[i];
			now++;
			for(int j = 1;j <= n;j++) g[++id] = {now,j,a[i][j]};
		}
	}
	for(int i = 1;i <= now;i++) fa[i] = i;
	sort(g+1,g+id+1,cmp);
	for(int i = 1;i <= id;i++)
	{
		int p = find_fa(g[i].u),q = find_fa(g[i].v);
		if(p != q)
		{
			fa[p] = q;
			res += g[i].w;
			tot++;
		}
		if(tot == now-1) break;
	}
	return res;
}
void dfs(int x)
{
	if(x == k+1)
	{
		ans = min(ans,kruskal());
		return;
	}
	vis[x] = 1;
	dfs(x+1);
	if(!flag)
	{
		vis[x] = 0;
		dfs(x+1);	
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> b[i].u >> b[i].v >> b[i].w;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		flag &= (c[i] == 0);
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	dfs(1);
	cout << ans;
	return 0;
}

