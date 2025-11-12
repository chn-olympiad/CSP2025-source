#include <bits/stdc++.h>
using namespace std ;

int n , m , k ;
int fa[10005] ;
long long ans = 0 ;

struct Node {
	int u , v , l ;
} a[1010020] ;

int cmp ( Node x , Node y ) {
	return x.l < y.l ;
}

int innn () {
	int k = 0 , f = 1 ;
	char c = getchar() ;
	while ( c < '0' || c > '9' )
	{
		if ( c == '-' ) f = -1 ;
		c = getchar() ;
	}
	while ( c >= '0' && c <= '9' )
	{
		k = k * 10 + c - '0' ;
		c = getchar() ;
	} 
	return k * f ;
}

bool uion ( int u , int v ) { // bing
	if ( u != v )
	{
		fa[u] = v ;
		return 0 ;
	}
	return 1 ;
}

int findd ( int x )
{
	if ( x == fa[x] ) return x ;
	else return fa[x] = findd(fa[x]) ;
}

int main () {
	freopen("road2.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;
	
	n = innn() , m = innn() , k = innn() ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		fa[i] = i ;
	}
	
	for ( int i = 1 ; i <= n ; i ++ )
	{
		a[i].u = innn() , a[i].v = innn() , a[i].l = innn() ;
	}
	for ( int i = 1 ; i <= k ; i ++ )
	{
		int c = innn() ;
		for ( int j = 1 ; j <= n ; j ++ )
		{
			a[n+i].u = n+i ;
			a[n+i].v = j ;
			a[n+i].l = innn() ;
		}
	}
	sort(a+1,a+n+m+1,cmp) ;
	
	int cnt = 0 ;
	for ( int i = 1 ; i <= n + m ; i ++ )
	{
		if ( uion(findd(a[i].u) , findd(a[i].v)) )
		{
			ans += a[i].l ;
			cnt ++ ;
		}
	}
	cout << ans ;
	return 0 ;
}