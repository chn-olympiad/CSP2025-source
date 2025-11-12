#include <bits/stdc++.h>
using namespace std ;
struct stu {
	bool xm = 0 ;
	int Grade ;
}a[105]; 
bool cmp (const stu &a1 , const stu &a2 ) {
	return a1.Grade > a2.Grade ;
}
int k = 1 ;
bool sx ;
int main () {
	
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	cin >> a[1].Grade ;
	a[1].xm = 1 ; 
	for (int i = 2 ; i <= n*m ; i++ ) 
		cin >> a[i].Grade ; 
	sort(a+1 , a+1+n*m , cmp ) ;
	for (int x = 1 , y = 1 ; x <= n && y <= m && x >= 1 ; ) {
		if (a[k++].xm) {
			cout << y << " " << x ;
			break ;
		}
		if (!sx) {
			if ( x == n) {
				y++ ;
				sx = 1 ;
			}else 
				x++ ;
			continue ;
		}
		if (sx) {
			if (x == 1) {
				y++ ;
				sx = 0 ;	
			}else
				x-- ;
			continue ;
		}
	}
	return 0 ; 
} 
