#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0, len = 1, a1, a1i, a1j;
int a[1000002], aa[1000002];
int s[12][12], b[12][12], c[12][12], cc[12][12];

int main(){
	
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	fin >> n >> m;
	for( int i = 1; i <= n * m; ++ i ){
		fin >> a[ i ];
		++ cnt;
	}
	a1 = a[ 1 ];
	sort( a, a + cnt + 1 );
	for( int i = cnt; i >= 1; -- i ){
		aa[ len ] = a[ i ];
		++ len;
	}
	len = 1;
	for( int i = 1; i <= m; ++ i ){
		for( int j = 1; j <= n; ++ j ){
			if( i % 2 == 1 ){
				b[ i ][ j ] = aa[ len ];
				++ len;
			}
			if( i % 2 == 0 ){
				c[ i ][ j ] = aa[ len ];
				++ len;
			}
		}
	}
	len = n;
	for( int i = 1; i <= m; ++ i ){
		for( int j = 1; j <= n; ++ j ){
			cc[ i ][ j ] = c[ i ][ len ];
			-- len;
		}
		len = n;
	}
	len = 1;
	for( int i = 1; i <= m; ++ i ){
		for( int j = 1; j <= n; ++ j ){
			if( i % 2 == 1 ){
				s[ i ][ j ] = b[ i ][ j ];
			}
			if( i % 2 == 0 ){
				s[ i ][ j ] = cc[ i ][ j ];
			}
		}
	}
	for( int i = 1; i <= m; ++ i ){
		for( int j = 1; j <= n; ++ j ){
			if( s[ i ][ j ] == a1 )
			a1i = i;
			a1j = j;
			break;
		}
	}
	fout << a1i << " " << a1j; 
	fin.close();
	fout.close();
	
	return 0;
	
} 
