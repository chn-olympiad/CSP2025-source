#include<bits/stdc++.h>
using namespace std;
int n , m , a[205];
int main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout );
	scanf ( "%d%d" , &n , &m ) ;
	for ( int i = 1; i <= n * m ; ++ i ) {
		scanf ( "%d" , &a[i] );
	}
	int op = a[1] , o = 1 ;
	sort ( a + 1 , a + n * m + 1 , greater<int>() );
	for ( int i = 1 ; i <= n * m ; i ++ ) {
		if ( a[i] == op ) {
			o = i ;
			break;
		} 
	}
	if ( o % n == 0 ) {
		if ( ( o / n ) % 2 == 1 ) {
			cout << o / n << " " << n ;
		} else {
			cout << o / n << " " << 1 ;
		}
		return 0;
	}
	if (( o / n ) % 2 == 0 || ( ( o % n ) == 0 && ( o / n ) % 2 == 1 ) ) {
		cout << o / n + 1 << " " << o % n ;
	}else {
		cout << o / n + 1 << " " << n - ( o % n ) + 1;
	}
	return 0;
}
