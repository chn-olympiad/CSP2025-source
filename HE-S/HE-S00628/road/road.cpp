#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6+5;

struct node
{
	int from,to,val;
} graph[maxn];

bool cmp(node x, node y)
{
	return x.val < y.val;
}

int n,m,k,ans;
vector<node> e[10005];
int fa[maxn];

int gets_fa(int u)
{
	if (fa[u] == u) return u;
	return gets_fa(fa[u]);
}

void make_fa(int u, int v)
{
	int fa1 = gets_fa(u),fa2 = gets_fa(v);
	fa[fa1] = fa2;
}

void kruskal()
{
	for (int i = 1; i <= m; i++)
	{
		int u = graph[i].from,v = graph[i].to,w = graph[i].val;
		int fa1 = gets_fa(u),fa2 = gets_fa(v);
		if (fa1 != fa2)
		{
			make_fa(fa1,fa2);
			ans += w;
		}
	}
}

void _swap(node x, node y)
{
	node z = y;
	y = x;
	x = z;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;//城市数量、道路数量和准备进行城市化改造的乡镇数量
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;//表示第i条道路连接的两座城市与修复该道路的费用
		e[u].push_back(node{v,w});
		e[v].push_back(node{u,w});
		graph[i].from = u; graph[i].to = v; graph[i].val = w;
	}
	sort(graph+1,graph+n+1,cmp);
	for (int i = 1; i <= k; i++)
	{
		int org = 0; cin >> org;
		for (int j = 1; j <= n; j++)
		{
			int w; cin >> w;
			e[n+i].push_back(node{j,w});
			e[j].push_back(node{n+i,w});
		}
	}
	kruskal();
	cout << ans << endl;
	return 0;
}
