#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define ll long long

using namespace std;

const int N = 1005;
const int M = 1100010;

struct Edge
{
	int u,v;
	ll w;
}e[M];

int cnt,fa[N],n,m,k;

struct Ed
{
	int v;
	ll w;
};
vector<Ed>G[N];
ll a[12][N],ans;

bool Check_A()
{
	for(int i = 1;i <= k;i++) if(a[i][0]) return 0;
	return 1;
}

int Find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}

bool cmp(const Edge& x,const Edge& y)
{
	return x.w < y.w;
}

void Kruskal()
{
	int tmp = 0;
	sort(e + 1,e + cnt + 1,cmp);
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= cnt;i++)
	{
		if(tmp == n - 1) break;
		int ru = Find(e[i].u),rv = Find(e[i].v);
		if(ru != rv)
		{
			ans+=e[i].w;
			fa[ru] = rv;
			tmp++;
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,j;
	cin>>n>>m>>k;
	for(i = 1;i <= m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		G[e[i].u].push_back((Ed){e[i].v,e[i].w});
		G[e[i].v].push_back((Ed){e[i].u,e[i].w});
	}
	for(i = 1;i <= k;i++) for(j = 0;j <= n;j++) cin>>a[i][j];
	if(Check_A())
	{
		cnt = m;
		for(i = 1;i <= k;i++)
		{
			int u = 1;
			for(j = 1;j <= n;j++) if(a[i][j] == 0)
			{
				u = j;
				break;
			}
			for(j = 1;j <= n;j++)
			{
				cnt++;
				e[cnt].u = u;
				e[cnt].v = j;
				e[cnt].w = a[i][j];
			}
		}
		Kruskal();
	}
	cout<<ans;
	return 0;
}
