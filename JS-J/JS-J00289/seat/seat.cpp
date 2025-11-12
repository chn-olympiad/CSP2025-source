#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], c, d;
int main() {
	freopen( "seat.in", "r", stdin );
	freopen( "seat.out", "w", stdout );
	cin >> n >> m;
	for ( int i = 0; i < n * m; i++ )
		cin >> a[i];
	d = a[0];
	sort( a, a + n * m, greater<>() );
	for ( int i = 0; i < n * m; i++ )
		if ( a[i] == d ) {
			d = i;
			break;
		}
	for ( int i = 0; i < m; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( c == d ) {
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
			c++;
		}
		i++;
		for ( int j = n - 1; j + 1; j-- ) {
			if ( c == d ) {
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
			c++;
		}
	}
	return 0;
}
