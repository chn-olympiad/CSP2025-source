#include<bits/stdc++.h>
using namespace std;
int n, k, a[1000010];
int main() {
	freopen( "xor.in", "r", stdin );
	freopen( "xor.out", "w", stdout );
	scanf( "%d%d", &n, &k );
	for ( int i = 0; i < n; i++ )
		scanf( "%d", a + i );
	for ( int i = 0; i < n; i++ )
		if ( a[i] ^ 1 )
			goto meth2;
	printf( "%d", n / 2 );
	return 0;
meth2:
	;
	for ( int i = 0; i < n; i++ )
		if ( a[i] > 1 )
			goto meth3;
	if ( k ) {
		int cc = 0;
		for ( int i = 0; i < n; i++ )if ( a[i] )cc++;
		printf( "%d", cc );
	} else {
		int cc = 0;
		for ( int i = 0; i < n; i++ )
			if ( i && a[i] && a[i - 1] )
				cc++;
			else if ( !a[i] )
				cc++;
		printf( "%d", cc );
	}
	return 0;
meth3:
	;
	return 0;
}
