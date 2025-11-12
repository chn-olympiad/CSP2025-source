#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100 ;
int n , m ;
int a[N] , key ; 
bool cmp( int x , int y ) { return x > y ; }
int main() {
	freopen( "seat.in" , "r" , stdin ) ;
	freopen( "seat.out" , "w" , stdout ) ; 
	cin>>n>>m ;
	for( int i = 1 ; i <= n * m ; i++ ) cin>>a[i] ;
	key = a[1] ;
	sort( a + 1 , a + n * m + 1 , cmp ) ;
	for( int i = 1 ; i <= n * m ; i++ ) if( a[i] == key ) { key = i ; break ; }
	if( key % n != 0 ) {
		int u = key / n + 1 ;
		cout<< u << " " ;
		if( u & 1 ) cout<< key - ( u - 1 ) * n ;
		else cout<< u * n - key + 1 ;
	}else {
		int u = key / n ; 
		cout<< u << " " ;
		if( u & 1 ) cout<<n ;
		else cout<<1 ;
	}
	return 0 ;
}
