#include<bits/stdc++.h>
using namespace std;
int n , k , flag , cnt , a[1005] , op[1005][1005] , let[1005] , rigt[1005];
struct s {
	int b , c;
}o[1005];
bool cmp ( s x, s y ){
	if( x.b == y.b ) return x.c < y.c;
	return x.b < y.b; 
}
int main() {
	scanf ( "%d%d" , &n  , &k ) ;
	for ( int i = 1; i <= n  ; i ++ ) {
		scanf ( "%d" , &a[i] ) ;
		if ( a[i] != 1 ) {
			flag = 1;
		}
	}
	if ( flag == 0)  {
		cout << n / 2;
		return 0;
	}
	if ( k == 1 ) {
		int sum = 0;
		for ( int i = 1; i <= n ; i ++ ) {
			if ( a[i] == 1 ) sum ++;
		}
		cout << sum ;
		return 0 ;
	} else {
		int sum = 0;
		for ( int i = 1; i <= n ; i ++ ) {
			if ( a[i] == 0 ) {
				sum ++;
			}
		}
		for ( int i = 2; i <= n ; i ++ ) {
			if ( a[i] == 1 && a[i - 1] == 1 ) {
				sum ++;
				i += 1;
			}
		}
		cout << sum ;
		return 0;
	}
	for ( int i = 1 ; i <= n ; i  ++ ) {
		for ( int j = i ; j <= n ; j  ++ ) {
			op[i][j] = op[i][j - 1] ^ a[j];
			if ( op[i][j] == k ) {
				o[++cnt].b = i;
				o[cnt].c = j;
			}
		}
	}
	int maxx = 0;
	sort ( o + 1 , o + cnt + 1 , cmp ) ;
	for ( int i = 1; i <= cnt ; i ++ ) {
		int l = o[i].b , r = o[i].c , sum = 0;
		for ( int j = i + 1 ; j <= cnt ; j ++ ) {
			if ( o[j].b > r ) {
				r = o[i].c;
				sum ++;
			}
		}
		maxx = max ( maxx , sum );
	}
	cout << maxx;
	return 0;
}
