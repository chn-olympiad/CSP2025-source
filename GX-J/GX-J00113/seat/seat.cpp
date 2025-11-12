#include<iostream>
#include<algorithm>
using namespace std ;

int n , m ;
int a[10010] ;

bool cmp(int p , int q ) {
	return p > q ;
}

int main() {
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	cin >> n >> m ;
	for( int i = 1 ; i <= n * m ; i ++ ) {
		cin >> a[i] ;
	}
	int pos = a[1] ;
	int x = n * m ;
	sort(a+1,a+x+1,cmp) ;
	int po = 0 ;
	for( int i = 1 ; i <= x ; i ++ ) {
		if( a[i] == pos ) {
			po = i ;
		}
	}
	int y1 = 0 ;
	int x1 = po / n ;
	if( n * x1 < po ) {
		x1 ++ ; 
	}
	if( x1 % 2 == 0 ) {
		int t = po % n ;
		y1 = n - t + 1 ;
	} else {
		y1 = po % n ;
		if( y1 == 0 ) {
			y1 = n ;
		}
	}
	cout << x1 << " " << y1 << endl ;
	return 0 ;
}
