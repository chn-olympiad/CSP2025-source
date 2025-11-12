#include <bits/stdc++.h>

using namespace std;

int n, m, a[200][200], ans, b[1100], t = 1;
bool cmp ( const int& x, const int& y ) {
	return x > y;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for ( int i = 1; i <= n * m;i ++ ) cin >> b[i];
	ans = b[1];
	sort ( b + 1, b + n * m + 1, cmp );
	for ( int i = 1; i <= m; i ++ ) {
		for ( int j = 1; j <= n;j ++ ) {
			a[j][i] = b[t ++]; 
		}
	}
	for ( int j = 2; j <= m; j += 2 ) {
		for ( int i = 1; i <= n / 2; i ++ ) {
			int q = a[i][j];
			a[i][j] = a[n - i + 1][j];
			a[n - i + 1][j] = q;
		}
	}
	/*for ( int i = 1; i <= n ; i ++ ) {
		for ( int j = 1; j <= m; j ++ ) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	for ( int i = 1; i <= n; i ++ ) {
		for ( int j = 1; j <= m; j ++ ) {
			if ( a[i][j] == ans ) {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}
