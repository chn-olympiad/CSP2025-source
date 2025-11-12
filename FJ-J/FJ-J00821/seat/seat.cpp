#include<bits/stdc++.h>
using namespace std;

int n, m;
int maj;
int arr[10005], brr[100][100];

bool cmp( int a, int b ) {
	return a > b;
}

int main() {
	freopen( "seat.in", "r", stdin );
	freopen( "seat.out", "w", stdout );

	scanf( "%d%d", &n, &m );
	for( int i = 0; i < n * m; i++ ) {
		scanf( "%d", arr + i );
	}
	maj = arr[0];
	int k = 0;
	sort( arr, arr + n * m, cmp );
	for( int i = 0; i < n; i++ ) {
		if( i % 2 == 0 ) {
			for( int j = 0; j < m; j++ ) {
				brr[i][j] = arr[k++];
			}
		}else{
			for( int j = m - 1; j >= 0; j-- ) {
				brr[i][j] = arr[k++];
			}
		}
	}
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			if( maj == brr[i][j] ) {
				cout << i + 1 << ' ' << j + 1;
			}
		}
	}
	return 0;
}
