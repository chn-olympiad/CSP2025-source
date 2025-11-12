# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct edge { int x , y; LL w; } e[1100010] , b[1100010];
int n , m , k , p , fa[10020];
LL minn = 1e18 , c[20] , a[15][10010];
bool f[20];
int find(int x) { return (x == fa[x] ? x : fa[x] = find(fa[x])); }
LL mst()
{
	LL sum = 0;
	sort(b + 1 , b + p + 1 , [](edge x , edge y) { return x.w < y.w; } );
	for(int i = 1 ; i <= n + k ; i ++) fa[i] = i;
	for(int i = 1 , fx , fy ; i <= p ; i ++)
	{
		fx = find(b[i].x) , fy = find(b[i].y);
		if(fx != fy)
		{
			fa[fy] = fx;
			sum += b[i].w;
		}
	}
	return sum;
}
void dfs(int x)
{
	if(x > k)
	{
		LL sum = 0;
		p = m;
		for(int i = 1 ; i <= p ; i ++) b[i] = e[i];
		for(int i = 1 ; i <= k ; i ++)
		{
			if(f[i])
			{
				sum += c[i];
				for(int j = 1 ; j <= n ; j ++)
				{
					b[++ p] = {i + n , j , a[i][j]};
				}
			}
		}
		minn = min(minn , sum + mst());
		return ;
	}
	f[x] = 1;
	dfs(x + 1);
	f[x] = 0;
	dfs(x + 1);
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 , u , v , w ; i <= m ; i ++)
	{
		cin >> u >> v >> w;
		e[i] = {u , v , w};
	}
	for(int i = 1 ; i <= k ; i ++)
	{
		cin >> c[i];
		for(int j = 1 ; j <= n ; j ++) cin >> a[i][j];
	}
	dfs(1);
	cout << minn;
	return 0;
}
