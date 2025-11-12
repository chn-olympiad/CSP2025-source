#include <bits/stdc++.h>
using namespace std ;
int t , n[100] ;
struct a {
	int b1 ;
	int b2 ;
	int b3 ;
};
a xs[1145] ;
int main () {
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
	cin >> t ;
	for ( int i = 1 ; i <= t ; i++ ) {
		cin >> n[i] ;
		int cb[1145] = {0};
		int sn= n[i] / 2 ;
		int sb1 = 0 ;
		int sb2 = 0 ;
		int sb3 = 0 ;
		
		bool ss1 = true ; 
		bool ss2 = true ; 
		bool ss3 = true ;
		for ( int j = 1 ;j <= n[i] ; j++ ) {
			cin >> xs[j].b1 >> xs[j].b2 >> xs[j].b3 ;
		}
		for ( int j = 1 ;j <= n[i] ; j++ ) {
			if ((xs[j].b1 > xs[j].b2 && xs[j].b1 > xs[j].b3) && ss1 ){
				cb[j] = xs[j].b1 ; 
				sb1++ ;
			}else if ((xs[j].b2 > xs[j].b1 && xs[j].b2 > xs[j].b3) && ss2) {
				cb[j] = xs[j].b2 ; 
				sb2++ ;
			}else if ((xs[j].b3 > xs[j].b2 && xs[j].b3 > xs[j].b1) && ss3) {
				cb[j] = xs[j].b3 ; 
				sb3++ ;
			} 
			if ( sb1 == sn ) {
				ss1 = false ;
			}else if ( sb2 == sn ) {
				ss2 = false ;
			}else if ( sb3 == sn ) {
				ss3 = false ;
			}
		}
		sort(cb+1,cb+n[i]+1) ;
		int ans = 0 ;	
		for ( int j = 1 ; j <= n[i] ; j++ ) {
			ans+=cb[j] ;
	    }
		cout << ans << endl ;
	}
	
}

