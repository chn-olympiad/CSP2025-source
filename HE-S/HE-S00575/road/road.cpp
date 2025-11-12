#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x,id;
	friend bool operator <(const node x,const node y)
	{
		return x.x > y.x;
	}
};
int sum = 0;
bool vis[11000];
vector<int> v[11000],g[11000],vv[11000],gg[11000];
int c[15],a[15][10005];
void prim()
{
	priority_queue<node> q;
	memset(vis,0,sizeof(vis));
	node x;
	x.x = 0,x.id = 1;
	q.push(x);
	while(q.size())
	{
		int x = q.top().id,z = q.top().x;
		q.pop();
		if(vis[x])
		{
			continue;
		}
		vis[x] = 1;
		sum += z;
		for(int i = 0;i < v[x].size();i++)
		{
			int y = v[x][i],w = g[x][i];
			if(vis[y])
			{
				continue;
			}
			node zz;
			zz.x = w;
			zz.id = y;
			q.push(zz);
	 	}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		vv[x].push_back(y);
		vv[y].push_back(x);
		gg[x].push_back(w);
		gg[y].push_back(w);
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 1e18;
	for(int i = 0;i < (1 << k);i++)
	{
		for(int kkk = 1;kkk <= n;kkk++)
		{
			v[kkk] = vv[kkk];
			g[kkk] = gg[kkk];
		}
		sum = 0;
		for(int j = 1;j <= k;j++)
		{
			if((i & (1 << (j - 1))) == 1)
			{
				sum += c[j];
				for(int kkk = 1;kkk <= n;kkk++)
				{
					v[n + j].push_back(kkk);
					v[kkk].push_back(n + j);
					g[n + j].push_back(a[j][kkk]);
					g[kkk].push_back(a[j][kkk]);
				}
			}
		}
		prim();
		ans = min(ans,sum);
	}
	cout << ans;
	return 0;
}
