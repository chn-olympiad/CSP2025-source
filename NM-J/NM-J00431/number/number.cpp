#include <bits/stdc++.h> 
using namespace std;
string s ;
 int a[400000000] ;
int main () {
	freopen ( "number.in" , "r" , stdin) ;
	freopen ( "number.out" , "w" , stdout) ;
	cin >> s ;
	int x = 0 ;
	int len = s.length() - 1 ;
	for ( int i = 0 ; i <= len ; i++ ) {
		if ( s[i] == '1' ) {
			a[x] = 1 ;
			x++ ;
		}else if ( s[i] == '2') {
			a[x] = 2 ;	
			x++ ;		
		}else if ( s[i] == '3') {
			a[x] = 3 ;
			x++ ;			
		}else if ( s[i] == '4') {
			a[x] = 4 ;
			x++ ;			
		}else if ( s[i] == '5') {
			a[x] = 5 ;
			x++ ;			
		}else if ( s[i] == '6') {
			a[x] = 6 ;
			x++ ;			
		}else if ( s[i] == '7') {
			a[x] = 7 ;
			x++ ;			
		}else if ( s[i] == '8') {
			a[x] = 8 ;
			x++ ;			
		}else if ( s[i] == '9') {
			a[x] = 9 ;
			x++ ;			
		}else if ( s[i] == '0') {
			a[x] = 0 ;
			x++ ;			
		}
	} 
	sort ( a , a + x ) ;
	for ( int i = x - 1 ; i >= 0 ; i-- ) {
		cout << a[i] ;
	}
} 
