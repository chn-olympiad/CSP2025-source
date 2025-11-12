#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[201], r, c;

bool cmp( int x, int y ){ return x > y; }

int main(){
	freopen( "seat.in", "r", stdin );
	freopen( "seat.out", "w", stdout );
	cin >> n >> m;
	for ( int i=1; i<=n*m; i++ )
		cin >> a[i];
	sort( a+2, a+m*n+1, cmp );
	int f = 2;
	while ( a[f] > a[1] )
		++f;
	--f;
	if ( f % n == 0 ){
		r = f / n;
		c = r%2 ? n : 1;
	}
	else{
		r = f / n + 1;
		c = r%2 ? f%n : n-f%n+1;
	}
	cout << r << " " << c << endl;
	return 0;
}