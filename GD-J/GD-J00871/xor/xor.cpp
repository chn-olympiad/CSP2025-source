#include <bits/stdc++.h>
using namespace std ;
int n , k , a[500005] , w = 0 ;
struct node
{
	int x , y ;
} qj [500005] ;
bool cmp ( node p , node q )
{
	return p.y < q.y ;
}
int main () {
	std::ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0) ;
	freopen ( "xor.in" , "r" , stdin ) ;
	freopen ( "xor.out" , "w" , stdout ) ;
	cin >> n >> k ;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[i] ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		int z = a[i] ;
		if ( z == k )
		{
			qj[ ++ w ].x = i ;
			qj[w].y = i ;
		}
		for ( int j = i + 1 ; j <= n ; j ++ )
		{
			z ^= a[j] ;
			if ( z == k )
			{
				qj[ ++ w ].x = i ;
				qj[w].y = j ;
			}
		}
	}
	sort ( qj + 1 , qj + w + 1 , cmp ) ;
	int tail = qj[1].y , ans = 1 ;
	for ( int i = 2 ; i <= w ; i ++ )
		if ( qj[i].x > tail ) ans ++ , tail = qj[i].y ;
	cout << ans ;
	return 0 ;
}
/*
4 2
2 1 0 3
*/
