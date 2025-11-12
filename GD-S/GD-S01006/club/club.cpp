#include<bits/stdc++.h> 
using namespace std ;
int t , n , a[200000][4] , n1 ;
int num[4] , d[20000] ;
long long ans = 0 ;
int main(){
	freopen( "club.in" , "r" , stdin ) ;
	freopen( "club.out" , "w" , stdout) ;
	cin >> t ;
	for( int q = 1 ; q <= t ; q++ )
	{
		cin >> n ;
		for( int i = 1 ; i <= n ; i++ )
		{
			d[i] = 0 ;
			num[i] = 0 ;
		}
		ans = 0 ;
		n1 = n / 2 ;
		for( int i = 1 ; i <= n ; i++ )
		{
			for( int j = 1 ; j <= 3 ; j++ )
			{
				cin >> a[i][j] ;
			}
		}
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = 1 ; j <= n ; j++ ){
				if( a[j][1] < a[j+1][1] ){
					swap( a[j][1] , a[j+1][1] ) ;
					swap( a[j][2] , a[j+1][2] ) ;
					swap( a[j][3] , a[j+1][3] ) ;
				}
			}
		} 
		for( int i = 1 ; i <= n ; i++ )
		{
			for( int j = 1 ; j <= 3 ; j++ )
			{
				d[i] = max ( a[i][j] , d[i] ) ;
			}
		}
		for( int z = 1 ; z <= 3 ; z++ )
		{
			for( int i = 1 ; i <= n ; i++ )
			{
				for( int j = 1 ; j <= n ; j++ )
				{
					if( a[i][z] > a[j][z] && a[i][z] == d[i] && num[z] < n1 )
					{
						ans += d[i] ;
						num[z] ++ ;
						for( int p = 1 ; p <= 3 ; p++ )
						{
							a[i][p] = 0 ;
						}
					}
				}
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}
