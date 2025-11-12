#include <bits/stdc++.h>
#define ll long long

using namespace std ;

inline int read()
{
	int x = 0 , f = 1 ; char ch = 0 ;
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1 ; ch = getchar() ;}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

const int N = 2e6 + 10 , M = 1e4 + 100 ;

struct node{
	int u , v , w ;
}edge[N] , e[N];

int n , m , k , c[20] , a[20][M] , vis[20] , fa[N] , cnt ;
ll ans ;

inline bool compare(node xx , node yy)
{
	return xx.w < yy.w ;
}

inline int find(int x)
{
	if(fa[x] == x) return x ;
	return fa[x] = find(fa[x]) ;
}

inline void dfs(int x)
{
	if(x != k + 1)
	{
		vis[x] = false ;
		dfs(x + 1) ;
		vis[x] = true ;
		dfs(x + 1) ;
		vis[x] = false ;
		return ;
	}
	int cnt1 = cnt ;
	for(int i = 1 ; i <= cnt ; i ++ ) e[i] = edge[i] ;
	for(int i = 1 ; i <= n + k ; i ++ ) fa[i] = i ;
	ll res = 0 ;
	for(int i = 1 ; i <= k ; i ++ )
	{
		if(!vis[i]) continue ;
		res += c[i] ;
		for(int j = 1 ; j <= n ; j ++ )
		{
			cnt1 ++ ;
			e[cnt1].u = n + i , e[cnt1].v = j , e[cnt1].w = a[i][j] ;
		}
	}
	sort(e + 1 , e + 1 + cnt1 , compare) ;
	for(int i = 1 ; i <= cnt1 ; i ++ )
	{
		int fx = find(e[i].u) , fy = find(e[i].v) ;
		if(fx == fy) continue ;
		fa[fx] = fy ;
		res += e[i].w ;
	}
	if(res < ans) ans = res ;
}

signed main()
{
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;
	n = read() , m = read() , k = read() ;
	for(int i = 1 ; i <= m ; i ++ )
	{
		e[i].u = read() , e[i].v = read() , e[i].w = read() ;
	}
	sort(e + 1 , e + 1 + m , compare) ;
	for(int i = 1 ; i <= n ; i ++ ) fa[i] = i ;
	for(int i = 1 ; i <= m ; i ++ )
	{
		int fx = find(e[i].u) , fy = find(e[i].v) ;
		if(fx == fy) continue ;
		fa[fx] = fy , ans += e[i].w ;
		edge[++cnt] = e[i] ;
	}
	for(int i = 1 ; i <= k ; i ++ )
	{
		c[i] = read() ;
		for(int j = 1 ; j <= n ; j ++ ) a[i][j] = read() ;
	}
	dfs(1) ;
	printf("%lld\n" , ans) ;
	return 0 ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/