#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k;
int fa[10010],vis[10010],a[11][10010],c[11],minn = 1e18;

struct node
{
	int u,v,w;
	friend bool operator < (node x,node y)
	{
		return x.w < y.w;
	}
};

vector <node> v;

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void dfs(int x)
{
	if (x >= k + 1)
	{
		int cost = 0;
		for (int i = 1;i <= n;i ++) fa[i] = i;
		for (int i = 1;i <= k;i ++)
		{
			if (vis[i])
			{
				cost += c[i];
				for (int j = 1;j <= n;j ++) v.push_back({n + i , j , a[i][j]});
			}
		}
		int ans = 0;
		for (node it : v)
			if (find(it.u) != find(it.v))
			{
				fa[find(it.u)] = find(it.v);
				ans += it.w;
			}
		minn = min(minn , ans);
		return;
	}
	for (int i = 0;i <= 1;i ++)
	{
		vis[x] = i;
		dfs(x + 1);
		vis[x] = 0;
	}
}

signed main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i ++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		v.push_back({x , y , z});
	}
	for (int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for (int j = 1;j <= n;j ++) cin >> a[i][j];
	}
	dfs(1);
	cout << minn;
	return 0;
}
