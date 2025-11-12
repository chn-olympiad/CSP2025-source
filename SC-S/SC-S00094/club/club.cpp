#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 1e5 + 5 ;

int t ;

signed main () {
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	
	freopen("clud.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	
	cin >> t ;
	
	while (t --) {
		int n ;
		cin >> n ;
		int sum = 0 ;
		int a[N][3] ;
		int x[N] , y[N] , z[N] ;
		for (int i = 1 ; i <= n ; i ++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2] ;
			x[i] = a[i][0] ;
			y[i] = a[i][1] ;
			z[i] = a[i][2] ;
		}
		sort(x + 1 , x + n + 1) ;
		sort(y + 1 , y + n + 1) ;
		sort(z + 1 , z + n + 1) ;
		for (int i = n ; i >= n - n / 2 ; i --) {
			sum += x[i] + y[i] + z[i] ;
		}
		cout << sum ;
	}
	
	return 0 ;
	
}