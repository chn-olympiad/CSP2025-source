#include<iostream>
using namespace std ;

int n , k ;
int a[500000] ;
int cnt1 , cnt0 ;


void solve() {
	int x = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( a[i] == 1 ) {
			x ++ ;
		}
	}
	cout << x << endl ;
}

void solve_2() {
	int x = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( a[i] == 0 ) {
			x ++ ;
		} else {
			if( a[i+1] == 1 ) {
				x ++ ;
				i ++ ;
			}
		}
	}
	cout << x << endl ;
}

void solve_3() {
	int cnt = cnt0 ;
	if( k == 0 ) {
		for( int i = 1 ; i <= n ; i ++ ) {
			if( a[i] != 0 ) {
				if( a[i+1] == a[i] ) {
					cnt ++ ;
					i ++ ;
				}
			}
		}
	}
	cout << cnt << endl ;
}

int main() {
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout) ;
	cin >> n >> k ;
	cnt0 = 0 ;
	cnt1 = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
		if( a[i] == 1 ) {
			cnt1 ++ ;
		} 
		if( a[i] == 0 ) {
			cnt0 ++ ;
		}
	}
	if( cnt1 == n && k == 0 ) {  // A
		int y = n / 2 ;
		cout << y << endl ;
		return 0 ;
	}
	if( cnt1 + cnt0 == n && k <= 1 ) {  // B
		if( k == 0 ) {
			if( cnt0 == n ) {
				cout << cnt0 << endl ;
				return 0 ;
			}
			solve_2() ;
		} else {
			solve() ;	
		}
	}
	if( cnt1 + cnt0 < n ) {  // C
		solve_3() ;
	}
	return 0 ;
}
