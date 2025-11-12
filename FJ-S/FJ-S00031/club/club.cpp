#include <bits/stdc++.h>
using namespace std ;

int n , lenn ;
int a[100005][4] , f[5] ;

long long ff ( int u , int k ) {
	if ( f[k] >= lenn ) return 0 ;
	long long sum = a[u][k] ;
	f[k] ++ ;
	if ( u == n )
	{
		return sum ;
	}
	else
	{
		int c1 = ff(u+1,1) ;
		f[1] -- ;
		int c2 = ff(u+1,2) ;
		f[2] -- ;
		int c3 = ff(u+1,3) ;
		f[3] -- ;
		//cout << u << " " << k <<  " " << c1 << " " << c2 << " " << c3 << "\n" ;
		return sum + max(c1 , max(c2 , c3)) ;                                 
	}
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

void solve () {
	memset(a,0,sizeof(a)) ;
	memset(f,0,sizeof(f)) ;
	n = innn() ;
	for ( int i = 1 ; i <= n ; i ++ ) a[i][1] = innn() , a[i][2] = innn() , a[i][3] = innn() ;
	lenn = n >> 1 ;
	
	cout << ff(0,0) << "\n" ;
}

int main () {
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	     
	for ( int T = innn() ; T -- ; ) solve() ;
	return 0 ;
}