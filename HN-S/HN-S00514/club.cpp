#include <bits/stdc++.h>
using namespace std ;

int t , A1[200005] , A2[200005] , A3[200005] ;

int main()
{
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	cin >> t ;
	for( int ij = 1 ; ij <= t ; ij ++ )
	{
		int n = 0 , d1 = 0 , d2 = 0 , d3 = 0 , a1 , a2 , a3 , ans = 0 ; 
		cin >> n ;
		for( int i = 1 ; i <= n ; i ++ )
		{
			cin >> a1 >> a2 >> a3 ;
			if( a1 >= a2 && a1 >= a3 )
			{
				ans += a1 ;
				A1[i] = max(a2 - a1 , a3 - a1) ;
				A2[i] = 0 ;
				A3[i] = 0 ;
				d1 ++ ;
			}
			else if( a2 >= a1 && a2 >= a3 )
			{
				ans += a2 ;
				A1[i] = 0 ;
				A2[i] = max(a1 - a2 , a3 - a2) ;
				A3[i] = 0 ;
				d2 ++ ;
			}
			else
			{
				ans += a3 ;
				A1[i] = 0 ;
				A2[i] = 0 ;
				A3[i] = max(a1 - a3 , a2 - a3) ;
				d3 ++ ;
			}
		}
		sort( A1 + 1 , A1 + n + 1 ) ; 
		sort( A2 + 1 , A2 + n + 1 ) ; 
		sort( A3 + 1 , A3 + n + 1 ) ; 
		int j = 0 ;
//		cout << d1 << "\n" ;
//		cout << d2 << "\n" ;
//		cout << d3 << "\n" ;
		while( d1 > n / 2 )
		{
			ans += A1[n - j] ;
			if(A1[n - j] != 0)d1 -- ;
			j ++ ;
		}
		while( d2 > n / 2 )
		{
			ans += A2[n - j] ;
			if(A2[n - j] != 0)d2 -- ;
			j ++ ;
		}
		while( d3 > n / 2 )
		{
			ans += A3[n - j] ;
			if(A3[n - j] != 0)d3 -- ;
			j ++ ;
		}
		cout << ans << "\n" ;
	}
	return 0 ;
} 
