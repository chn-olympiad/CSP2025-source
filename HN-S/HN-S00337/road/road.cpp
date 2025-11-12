#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node
{
	int u,v,w;
	bool operator<(const node &a)const
	{
		return w < a.w;
	}
};
node edges[2000005];
node edges2[2000005];
int c[15];
int a[15][10005];
int fa[10005];
bool f[15];
int ans = 1e18;
int find(int x)
{
	if(x == fa[x])return x;
	return fa[x] = find(fa[x]);
}
void solve()
{
	int sum = 0;
	int tot = m;
	for(int i = 1;i <= m;i++)
	{
		edges2[i] = edges[i];
	}
	for(int i = 1;i <= k;i++)
	{
		if(!f[i])continue;
		sum += c[i];
		for(int j = 1;j <= n;j++)
		{
			edges2[++tot] = {n+i,j,a[i][j]};
		}
	}
	sort(edges2+1,edges2+tot+1);
	for(int i = 1;i <= n+k;i++)
	{
		fa[i] = i;
	}
	for(int i = 1;i <= tot;i++)
	{
		int one = find(edges2[i].u);
		int two = find(edges2[i].v);
		if(one != two)
		{
			fa[one] = two;
			sum += edges2[i].w;
		}
	}
	ans = min(ans,sum);
//	cout << sum << "\n";
	return;
}
void dfs(int step)
{
	if(step > k)
	{
		solve();
		return;
	}
	f[step] = false;
	dfs(step+1);
	f[step] = true;
	dfs(step+1);
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	bool flag = true;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		if(c[i] > 0)flag = false;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
			if(a[i][j] > 0)flag = false;
		}
	}
	if(k == 0)
	{
		sort(edges+1,edges+m+1);
		for(int i = 1;i <= n;i++)
		{
			fa[i] = i;
		}
		int ans = 0;
		for(int i = 1;i <= m;i++)
		{
			int one = find(edges[i].u);
			int two = find(edges[i].v);
			if(one != two)
			{
				fa[one] = two;
				ans += edges[i].w;
			}
		}
		cout << ans;
		return 0;
	}
	if(flag)
	{
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
