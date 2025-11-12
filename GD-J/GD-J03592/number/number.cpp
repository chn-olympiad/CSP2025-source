#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
char a[N] ;
int d[15] , cnt;
int main() {
	freopen( "number.in" , "r" , stdin );
	freopen( "number.out" , "w" , stdout);
	scanf ( "%s" , a + 1 );
	int len = strlen(a + 1);
	for ( int i = 1; i <= len ; ++ i ) {
		if ( a[i] <= '9' && a[i] >= '0' ) {
			d[a[i] - '0'] ++;
		}
	}
	for ( int i = 9; i >= 0 ; i -- ) {
		for ( int j = 1 ; j <= d[i] ; ++ j ) { 
			cout << i ;
		}
	}
	return 0;
}
