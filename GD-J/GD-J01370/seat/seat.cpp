#include <bits/stdc++.h>
using namespace std ;

int n , m , a[1005] , sum ;
//struct
//bool cmp ( int x , int y ) {
//	return x.s > y.s ;
//}

int main () {
	freopen ("seat.in" , "r" , stdin ) ;
	freopen ("seat.out" , "w" , stdout ) ;
	
//	ios::sync_with_stdio(false) ;
//	cin.tie(0) , cout.tie(0) ;
	
	cin >> n >> m >> a[1] ;
	
	for ( int i = 2 ; i <= n * m ; i ++ ) {
		cin >> a[i] ;
		if ( a[i] > a[1] ) {
			sum ++ ;
		}
	}
	
//	sort ( a + 1 , a + n * m , cmp ) ;
	
	
	int x = sum / n + 1 ;
	int y = sum % m + 1 ;
	if ( (sum / n) % 2 == 1 ) {
		y = m - y + 1 ;
	}
	
	
	
	cout << x << " " << y ;
	
	
	
	
	
	
	
	
	return 0 ;
} 
/*

2 2
98 99 100 97

*/
