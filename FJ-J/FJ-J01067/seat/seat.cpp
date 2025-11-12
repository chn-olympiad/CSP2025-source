# include <bits/stdc++.h>
# define N (102)
using namespace std;

int a[N], n, m, tot, Grade_R, t = 1;

struct node{
	int x, y;
}seatt[N];

int main( ) {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for ( int i = 1; i <= n * m; ++i ) cin >> a[i];
	
	for ( int i = 1; i <= m; ++i ) {
		if ( i % 2 == 1 ) {
			for ( int j = 1; j <= n; ++j ) {
				tot++;
				seatt[tot].x = i;
				seatt[tot].y = j;
			}
		} else {
			for ( int j = n; j >= 1; --j ) {
				tot++;
				seatt[tot].x = i;
				seatt[tot].y = j;
			}
 		}
	}
	
//	cout << "n : " << n << " m : " << m << "\n";
	
	Grade_R = a[1];
//	cout << "Grade_R : " << Grade_R << "\n";
	
	sort( a + 1, a + ( n * m ) + 1 );
	
	for ( int i = n * m; i >= 1; --i, ++t ) {
		if ( a[i] == Grade_R ) {
			cout << seatt[t].x << " " << seatt[t].y;
			return 0;
		}
	}
	
	cout << "1 1";
	
	return 0;
}
