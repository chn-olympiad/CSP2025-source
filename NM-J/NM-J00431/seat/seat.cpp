#include <bits/stdc++.h> 
using namespace std;
int n , m ;
int a[18678] , b[1006][1006];
int main () {
	freopen ( "seat.in" , "r" , stdin) ;
	freopen ( "seat.out" , "w" , stdout) ;
	cin >> n >> m ;
	int x ;
	for ( int i = 1 ; i <= n * m ; i++ ) {
		if ( i == 1 ) {
			cin >> x ;
			a[i] = x ;
		}else cin >> a[i] ;
	}

	sort(a+1,a+n*m+1) ;
	int s = 1 ;
	int j = 1 ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( ; ; ) {
			b[j][i] = a[s] ;
			s++ ;
			if ( i % 2 == 1 ) {
				j++ ;
				if ( j > m ) {
					j-- ;
					break ;

				}
			}else {
				j-- ;
				if ( j < 1 ) {
					j++ ;
					break ;
				}
			}
		} 
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			if ( b[i][j] == x ) {
				cout << i << " " << j ;
			}
		} 
	}	
}  
