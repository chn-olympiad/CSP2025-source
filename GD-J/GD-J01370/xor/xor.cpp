#include <bits/stdc++.h>
using namespace std ;

int n , K , a[500005] ;
bool a0 = true , b1 = true ;
bool f[500005] ;
int main () {
	freopen ("xor.in" , "r" , stdin ) ;
	freopen ("xor.out" , "w" , stdout ) ;
	
	ios::sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	
	cin >> n >> K ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
		if ( a[i] != 1 ) {
			a0 = false ;
		}
//		if ( a[i] > 1 ) {
//			b1 = false ;
//		}
	}
	
	if ( a0 ) {
		int sum = n / 2 ;
//		cout << k / 2 ;
		
//		for ( int i = 4 ; i <= n ; i *= 2 ) {
//			sum += n / i ;
//		}
		cout << sum ;
		return 0 ;
	}
//	if ( b1 ) {
//		if ( k == 0 ) {
//			bool f[500005] ;
//			int sum = 0 ;
//			memset (f , 0 , sizeof (f)) ;
//			for ( int i = 2 ; i <= n ; i ++ ) {
//				if ( (a[i] == a[i-1]) && f[i-1] == 0 ) {
//					f[i] = 1 ;
////					f[i-1] 
//					sum ++ ;
//				}
//			} 
//			cout << sum ;
//			return 0 ;
//		} else {
//			bool f[500005] ;
//			int sum = 0 ;
//			memset (f , 0 , sizeof (f)) ;
//			for ( int i = 2 ; i <= n ; i ++ ) {
//				if ( (a[i] != a[i-1]) && f[i-1] == 0 ) {
//					f[i] = 1 ;
//					sum ++ ;
//				}
//			} 
//			cout << sum ;
//			return 0 ;
//		}
//	}
	
	// ±©Á¦
	
	int sum = 0 ;
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= n - i + 1 ; j ++ ) {
			int s = a[j] ;
//			int s ;
			for ( int k = 1 ; k < i ; k ++ ) {
				if (f[j + k - 1] == 1 || f[j] == 1 || f[j + k] == 1 ) {
					break ;	
				} 
//				cout << f[j + k] << endl ; 
				s ^= a[j + k] ;
			} 
			if ( s == K ) {
				for ( int k = 1 ; k <= i ; k ++ ) {
					f[j + k - 1] = 1 ;
				}
//				cout << "i=" << i << " j=" << j << " s=" << s << endl ;
				sum ++ ;
			}
		}
	} 
	
	cout << sum ;
	
	
	
	return 0 ;
} 

/*
4 0
2 1 0 3

*/
/*
4 2
2 1 0 3

*/


/*
4 3
2 1 0 3

*/
/*
4 2
2 1 0 3

*/ 

/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
