#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 10 + 5 ;

int n , m ;
int b[N * N] ;
int a[N][N] ;
int ans ;
int sum ;

signed main () {
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	
	cin >> m >> n ;
	
	for (int i = 1 ; i <= n * m ; i ++) {
		cin >> b[i] ;
	}
	
	ans = b[1] ;
	
	bool f = 0 ;
	
	sort(b + 1 , b + n * m + 1) ;
	
	sum = n * m ;
	
	for (int i = 1 ; i <= n ; i ++) {
		if (f == 0) {
			// 正
			for (int j = 1 ; j <= m ; j ++) {
				a[i][j] = b[sum--] ;
				if (a[i][j] == ans) {
					cout << i << " " << j ;
					return 0 ;
				}
			}
			f = 1 ;
		}
		else {
			//反
			for (int j = m ; j >= 1 ; j --) {
				a[i][j] = b[sum--] ;
				if (a[i][j] == ans) {
					cout << i << " " << j ;
					return 0 ;
				}
			}
			f = 0 ;
		}
	}
	
	return 0 ;
	
}