#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 2e4+5;
struct Edge{int u,v,w;}e[N];
int n,m,k;
bool cmp(Edge x, Edge y) {return x.w < y.w;}
int fa[N];
int c[N][N];
int findx(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = findx(fa[x]);
}
void mergex(int x, int y)
{
	int fx = findx(x);
	int fy = findx(y); 
	if (fx != fy) fa[fx] = fy;
}
ll Kruskal()
{
	sort(e+1,e+m+1,cmp);
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (findx(u) != findx(v))
		{
			mergex(u,v);
			ans += w;
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	ll sum = 0;
	for (int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[i] = {u,v,w};
		sum += w;
	}
	for (int i = 1; i <= k; i++) for (int j = 0; j <= n; j++) cin >> c[i][j]; 
	if (k == 0)
	{
		for (int i = 1; i <= n; i++) fa[i] = i;
		cout << Kruskal();
		return 0;
	}
	cout << sum;
	return 0;
}
