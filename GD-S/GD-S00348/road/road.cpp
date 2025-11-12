//canpass: 1,2,3,4,5,6,9,10,13,14
#include <bits/stdc++.h>
#define int long long
#define rep1(i,a,b) for (int i = (a);i <= (b);i++)
using namespace std;
const int N = 1e4 + 10;
const int M = 2e6 + 10;
const int Q = 1e3 + 10;
const int K = 11;
int n,m,k;
int fa[N];
//val:已激活的 val2:无限制 
int c[K],a[K][N],val[K][N],val2[K][N];
int mn[Q][Q];
int find(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(int u,int v)
{
	u = find(u);
	v = find(v);
	if (u != v)
	{
		//u->v
		fa[u] = v;
		rep1(i,1,k)
		{
			val[i][v] = min(val[i][u],val[i][v]);
			val2[i][v] = min(val2[i][u],val2[i][v]);
		}
	}
}
struct edge
{
	int u;
	int v;
	int w;
	bool operator<(const edge& xx) const { return w < xx.w; }
} e[M];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//可以爆搜激活哪些乡村 
	//用并查集是显然的 
	//在合并的同时，对每个乡村，维护当前集合中被激活且花费最小的元素 
	//也要维护当前集合中不管是否被激活，花费最小的元素 
	cin >> n >> m >> k;
	rep1(i,1,m)
		cin >> e[i].u >> e[i].v >> e[i].w;
	if (k == 0)
	{
		sort(e + 1,e + m + 1);
		rep1(i,1,n)	
			fa[i] = i;
		int ans = 0;
		rep1(i,1,m)
		{
			int u = find(e[i].u);
			int v = find(e[i].v);
			if (u != v)
			{
				ans += e[i].w;
				fa[u] = v;
			}
		}
		cout << ans;
		return 0;
	}
	rep1(i,1,k)
	{
		cin >> c[i];
		rep1(j,1,n)
			cin >> a[i][j];
	}
	//A性质：所有乡村都免费
	//假设对于i乡村，a[i][j]=0
	//将k与j连接需要花a[i][k]元
	//建出图，kruskal
	memset(mn,0x3f,sizeof mn);
	rep1(i,1,k)
	{
		int pos = 0;
		rep1(j,1,n)
			if (a[i][j] == 0)
			{
				pos = j;
				break;
			}
		rep1(j,1,n)
		{
			mn[j][pos] = min(mn[j][pos],a[i][j]);
			mn[pos][j] = min(mn[j][pos],a[i][j]);
		}
	}
	//kruskal
	rep1(i,1,n)
		rep1(j,i + 1,n)
			e[++m] = {i,j,mn[i][j]};
	sort(e + 1,e + m + 1);
	rep1(i,1,n)	
		fa[i] = i;
	int ans = 0;
	rep1(i,1,m)
	{
		int u = find(e[i].u);
		int v = find(e[i].v);
		if (u != v)
		{
			ans += e[i].w;
			fa[u] = v;
		}
	}
	cout << ans;
	return 0;
	/*int ans = 1e18;
	rep1(s,0,(1 << k) - 1)
	{
		int tans = 0;
		rep1(i,1,n)
			if (s & (1 << (i - 1)))
				tans += c[i];
		rep1(i,1,n)
			fa[i] = i;
		int mergecnt = 0;
		rep1(i,1,k)
			rep1(j,1,n)
			{
				val[i][j] = 1e9;
				val2[i][j] = a[i][j];
			}
		ans = min(ans,tans);
	}
	cout << ans;*/
}

