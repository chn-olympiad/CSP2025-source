#include <bits/stdc++.h>
using namespace std ;

int t , n , a[100005][5] , maxn ;

void dfs( int step , int cnta , int cntb , int cntc , int sum )
{
	if( cnta > n / 2 ) return ;
	if( cntb > n / 2 ) return ;
	if( cntc > n / 2 ) return ;
	if( step == n + 1 )
	{
		maxn = max( sum , maxn ) ;
		return ;
	}
	dfs( step + 1 , cnta + 1 , cntb , cntc , sum + a[step][1] ) ;
	dfs( step + 1 , cnta , cntb + 1 , cntc , sum + a[step][2] ) ;
	dfs( step + 1 , cnta , cntb , cntc + 1 , sum + a[step][3] ) ;
	return ;
}

int main()
{
	freopen( "club.in" , "r" , stdin ) ;
	freopen( "club.out" , "w" , stdout ) ;
	cin >> t ;
	while( t -- )
	{
		cin >> n ;
		for( int i = 1 ; i <= n ; i ++ )
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3] ;
		}
		dfs( 0 , 0 , 0 , 0 , 0 ) ;
		cout << maxn << endl ;
		maxn = 0 ;
	}
	return 0 ;
} 
