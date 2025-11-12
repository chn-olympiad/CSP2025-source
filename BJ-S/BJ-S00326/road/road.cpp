#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,a[15][10005],fa[10005],f[1005][1005],mn = 1e18;
struct node
{
	int u,v,w;
}g[5000005];
bool cmp(node x,node y)
{
	return x.w < y.w;
}
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void dfs(int x,int s)
{
	if (s > mn) return;
	if (x > k)
	{
		for (int i = 1;i <= n;i++) fa[i] = i;
		int cnt = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				if (f[i][j] < 0x3f3f3f3f)
				{
					cnt++;
					g[cnt] = {i,j,f[i][j]};
				}
			}
		}
		sort(g+1,g+cnt+1,cmp);
		int ans = s;
		for (int i = 1;i <= cnt;i++)
		{
			int fx = find(g[i].u),fy = find(g[i].v);
			if (fx == fy) continue;
			ans += g[i].w;
			fa[fx] = fy;
		}
		mn = min(ans,mn);
		return ;
	}
	dfs(x+1,s);
	vector <node> b;
	int flag = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (a[x][i]+a[x][j] < f[i][j])
			{
				flag = 1;
				b.push_back({i,j,f[i][j]});
				f[i][j] = a[x][i]+a[x][j];
			}
		}
	}
	if (flag == 0) return;
	dfs(x+1,s+a[x][0]);
	for (auto t:b) f[t.u][t.v] = t.w;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) fa[i] = i;
	for (int i = 1;i <= n;i++) 
	{
		for (int j = 1;j <= n;j++)
		{
			f[i][j] = 2e9;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> g[i].u >> g[i].v >> g[i].w;
		f[g[i].u][g[i].v] = f[g[i].v][g[i].u] = min(g[i].w,f[g[i].u][g[i].v]);
	}
	int flag = 1;
	for (int i = 1;i <= k;i++)
	{
		for (int j = 0;j <= n;j++)
		{
			cin >> a[i][j];
		}
		if (a[i][0] != 0) flag = 0;
	}
	if (k == 0)
	{
		sort(g+1,g+m+1,cmp);
		int ans = 0;
		for (int i = 1;i <= m;i++)
		{
			int fx = find(g[i].u),fy = find(g[i].v);
			if (fx == fy) continue;
			ans += g[i].w;
			fa[fx] = fy;
		}
		cout << ans;
		return 0;
	}
	if (flag == 1)
	{
		for (int i = 1;i <= k;i++)
		{
			for (int x = 1;x <= n;x++)
			{
				for (int y = x+1;y <= n;y++)
				{
					f[x][y] = min(f[x][y],a[i][x]+a[i][y]);
				}
			}
		}
		int cnt = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				cnt++;
				g[cnt] = {i,j,f[i][j]};
			}
		}
		sort(g+1,g+cnt+1,cmp);
		int ans = 0;
		for (int i = 1;i <= cnt;i++)
		{
			int fx = find(g[i].u),fy = find(g[i].v);
			if (fx == fy) continue;
			ans += g[i].w;
			fa[fx] = fy;
		}
		cout << ans;
		return 0;
	}
	if (n <= 1000 && m <= 100000) 
	{
		dfs(1,0);
		cout << mn;
		return 0;
	}
	sort(g+1,g+m+1,cmp);
	int ans = 0;
	for (int i = 1;i <= m;i++)
	{
		int fx = find(g[i].u),fy = find(g[i].v);
		if (fx == fy) continue;
		ans += g[i].w;
		fa[fx] = fy;
	}
	cout << ans;
	
	return 0;
}
