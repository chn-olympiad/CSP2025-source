#include<bits/stdc++.h>
using namespace std ;
const int MAXNM = 105 ;
struct Node {
	int poi ;
	int u ;
}a[MAXNM];
bool cmp ( Node i , Node j ) {
	return i.poi > j.poi ;
}
signed main() {
	freopen( "seat.in" , "r" , stdin ) ;
	freopen( "seat.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n * m ; i ++ ) {
		cin >> a[i].poi ;
		a[i].u = i ;
	}sort ( a + 1 , a + 1 + n * m , cmp ) ;
	int dir ;
	for ( dir = 1 ; a[dir].u != 1 ; dir ++ ) ;
	int l = ( dir + n - 1 ) / n ;
	int h ;
	if ( l % 2 == 1 ) {
		h = ( dir - 1 ) % n + 1 ;
	}else {
		h = n - ( dir - 1 ) % n ;
	}cout << l << " " << h ;
	return 0 ;
}
