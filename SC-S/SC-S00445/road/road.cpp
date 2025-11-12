#include <iostream>
#include <bitset>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long int lli;
struct edge
{
	int v;
	lli w;
};
struct node
{
	int now;
	lli tot;
	bool operator > (const node &a) const
	{
		return tot > a.tot;
	}
}
front;
vector< vector<edge> > g;
priority_queue< node,vector<node>,greater<node> > pq;
int n,m,k;
lli c[15],a[15][10005];
int u,v;
lli w;
bool vis[10015];
int lefts;
lli ans = 1e18;
int powered;
void dijkstra()
{
//	cerr << endl << powered << endl;
	lli res = 0;
	for(int i = 1;i <= k;i++)
	{
		if((powered >> (i - 1)) & 1)
		{
			res += c[i];
			if(res > ans)
			{
				return ;
			}
		}
	}
	for(int i = 1;i <= n + k;i++)
	{
		vis[i] = false;
	}
	lefts = n;
	pq = {};
	pq.push({1,0ll});
	vis[1] = true;
	while(true)
	{
		front = pq.top();
		pq.pop();
//		cerr << front.now << ' ' << front.tot << endl;
		if(front.now <= n)
		{
			res += front.tot;
			if(res > ans)
			{
				return ;
			}
			lefts--;
			if(lefts == 0)
			{
				break;
			}
		}
		for(edge i : g[front.now])
		{
			if(vis[i.v])
			{
				continue;
			}
			if(i.v <= n)
			{
				if(res > ans)
				{
					return ;
				}
				pq.push({i.v,i.w + front.tot});
				vis[i.v] = true;
			}
			else
			{
				if((powered >> (i.v - n - 1)) & 1)
				{
					pq.push({i.v,i.w + front.tot});
					vis[i.v] = true;
				}
			}
		}
	}
	ans = min(ans,res);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	g.resize(n + k + 1);
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> w;
			g[n + i].push_back({j,w});
			g[j].push_back({n + i,w});
		}
	}
	for(powered = 0;powered < (1 << k);powered++)
	{
		dijkstra();
	}
	cout << ans << endl;
	return 0;
}