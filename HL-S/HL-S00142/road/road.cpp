#include <bits/stdc++.h>
using namespace std ;
#define int long long 
int n , m , k , ans = 0x3f3f3f3f3f3f3f3f ;
int c[15] , a[15][10005] ;
struct llll
{
	int u , v , w ;
};
vector<llll> g[10005] ;
bool xiujian[15] ;
bool cmp ( llll x , llll y )
{
	return x.w < y.w ;
}
int fa[50000] ;
int getfa ( int x )
{
	if ( fa[x] != x ) fa[x] = getfa(x) ;
	return fa[x] ;
}
bool judge ( int x , int y )
{
	return getfa(x) == getfa(y) ;
}
void merge ( int x , int y )
{
	fa[getfa(y)] = getfa(x) ;
}
void dfs( int p )
{
	if ( p == k )
	{
			int ret = 0 ;
			llll line[20005] ;
			int top = 0 ;
			for ( int i = 0 ; i < n+k ; i ++ )
				fa[i] = i ;
			for ( int i = 0 ; i < n ; i ++ )
				for ( int j = 0 ; j < g[i].size() ; j ++ )
					line[top++] = {i,g[i][j].v,g[i][j].w} ;
			for ( int i = 0 ; i < k ; i ++ )
			{
				if ( xiujian[i] )
				{
					ret += c[i] ;
					for ( int j = 0 ; j < n ; j ++ )
						line[top++] = {i+n,j,a[i][j]} ;
				}
			}
			sort(line,line+top,cmp);
			for ( int i = 0 ; i < top ; i ++ )
			{
				int x = line[i].u , y = line[i].v ;
				/*if ( judge(x,y) ) continue ;
				merge(x,y);*/
				ret += line[i].w ;
			}
		ans = min(ans,ret) ;
		return ;
	}
	dfs(p+1);
	xiujian[p] = 1 ;
	dfs(p+1);
	xiujian[p] = 0 ;
}
signed main()
{
	freopen("raod.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for ( int i = 0 ; i < m ; i ++ )
	{
		int u , v , w ;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back({u,v,w}) ;
	}
	for ( int i = 0 ; i < k ; i ++ )
	{
		int x , y ;
		scanf("%lld",&x);
		c[i] = x ;
		for ( int j = 0 ; j < n ; j ++ )
		{
			scanf("%lld",&y);
			a[i][j] = y ;
		}
	}
	dfs(0);
	cout << ans ;
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}
