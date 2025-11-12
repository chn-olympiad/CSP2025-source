#include <bits/stdc++.h>
#define N 20
using namespace std ;
int n , m , a[N * N] , b[N][N] , tmp , x = 1 , y = 1 ;
bool cmp(int a , int b) {
	return a > b ;
}
int main() {

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	ios :: sync_with_stdio(false) ;
	cin . tie(0) , cout . tie(0) ;

	cin >> n >> m ;
	cin >> a[1] ;
	tmp = a[1] ;
	for(int i = 2 ; i <= n * m ; i++) {
		cin >> a[i] ;
	} 
	
	sort(a + 1 , a + 1 + n * m , cmp) ;
	for(int i = 1 ; i <= n ; i += 2) {
		for(int j = 1 ; j <= m ; j++) {
			b[i][j] = a[(i - 1) * n + j] ;
		}
	}
	for(int i = 2 ; i <= n ; i += 2) {
		for(int j = m ; j >= 1 ; j--) {
			b[i][j] = a[(i - 1) * n + m - j + 1] ;	
		}
	}
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			if(tmp == b[i][j]) {
				cout << i << ' ' << j ;
				return 0 ;
			}
		}
	}
	return 0 ;

}

