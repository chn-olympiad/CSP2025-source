#include <bits/stdc++.h>
using namespace std ;
long long n , k , a [ 500005 ] , maxa ;
bool b [ 500005 ] [ 21 ] ;
void den_to_bin ( int x , int pos ) {
	int t = x ;
	string s = "" ;
	while ( t > 0 ) {
		if ( t % 2 == 1 ) s = s + '1' ;
		else s = s + '0' ;
		t /= 2 ;
	}
	int vis = 20 ;
	//cout << s << endl ;
	for ( int i = 0 ; i < s.length ( ) ; i++ ) {
		if ( s [ i ] == '1' ) b [ pos ] [ vis ] = true ;
		vis-- ;
	}
}
int bin_to_den ( string x ) {
	int bincnt = 1 , ben = 0 ;
	for ( int i = 19 ; i >= 0 ; i-- ) {
		ben += ( x [ i ] - '0' ) * bincnt ;
		bincnt *= 2 ;
	}
	return ben ;
}
int main ( ) {
	freopen ( "xor.in" , "r" , stdin ) ;
	freopen ( "xor.out" , "w" , stdout ) ;
	cin >> n >> k ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a [ i ] ;
		maxa = max ( maxa , a [ i ] ) ;
	}
	if ( k == 0 && maxa == 1) cout << n / 2 ;
	else if ( k <= 1 && maxa == 1 ) {
		int ans = 0 ;
		for ( int i = 1 ; i < n ; i++ ) if ( a [ i ] != a [ i + 1 ] ) ans++ ;
	}
	else {
		for ( int i = 1 ; i <= n ; i++ ) den_to_bin ( a [ i ] , i ) ;
		/*
		for ( int i = 1 ; i <= n ; i++ ) {
			for ( int j = 1 ; j <= 20 ; j++ ) cout << b [ i ] [ j ] << ' ' ;
			cout << endl ;
		}
		*/
		int ans = 0 ;
		bool f [ 21 ] ;
		memset ( f , 0 , sizeof ( f ) ) ;
		for ( int st = 1 ; st <= n ; st++ ) {
			int cnt_for_k = 0 ;
			for ( int bianli = st ; bianli <= n ; bianli++ ) {
				for ( int i = 1 ; i <= 20 ; i++ ) {
					if ( b [ bianli ] [ i ] != f [ i ] ) f [ i ] = 1 ;
					else f [ i ] = 0 ;
				}
				string sf = "" ;
				for ( int i = 1 ; i <= 20 ; i++ ) sf = sf + char ( f [ i ] + '0' ) ;
				int now_num = bin_to_den ( sf ) ;
				//for ( int i = 1 ; i <= 20 ; i++ ) cout << f [ i ] << ' ' ;
				//cout << now_num << ' ' << st << ' ' << bianli << endl ;
				if ( now_num == k ) {
					cnt_for_k++ ;
					memset ( f , 0 , sizeof ( f ) ) ;
				} 
			}
			ans = max ( cnt_for_k , ans ) ;
		}
		cout << ans ;
	}
}
