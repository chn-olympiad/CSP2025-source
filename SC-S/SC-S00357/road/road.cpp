#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 50;
int n,m,q,tot;
int fa[maxn * 11],c[15];
struct edge
{
	int u,v,w;
	friend bool operator<(const edge &x,const edge &y){return x.w < y.w;}
};
vector<edge> e;
int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
	while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
	return x * f;
}
int id(int dep,int x){return (dep - 1) * n + x;}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	q = read();
	iota(fa + 1,fa + n + 1,1);
	int u,v,w;
	while (m--)
	{
		u = read(),v = read(),w = read();
		e.push_back({u,v,w});
	}
	for (int i = 1; i <= q; i++)
	{
		c[i] = read();
		for (int j = 1; j <= n; j++)
			e.push_back({n + i,j,read()});
	}
	sort(e.begin(),e.end());
	int ans = 0;
	for (auto x : e)
	{
		int u = x.u,v = x.v,w = x.w;
		u = find(u),v = find(v);
		if (u != v)
		{
			ans += w;
			fa[u] = v;
		}
	}
	cout << ans << '\n';
	return 0;
}
// retired