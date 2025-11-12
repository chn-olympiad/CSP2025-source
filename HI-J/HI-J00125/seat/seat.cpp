#include<bits/stdc++.h>

using namespace std ;

long long a[105] ;

int cmp (int a , int b) {
	return a > b ;
}

int main () {
	
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	
	int n , m ;
	
	cin >> n >> m ;
	
	for(int i = 1 ; i <= n * m ; i ++) {
		cin >> a[i] ;
	}
	
	int h = a[1] , cnt;
	
	sort (a + 1 , a + n * m + 1 , cmp) ;
	
	for(int i = 1 ; i <= n * m ; i ++) {
		if(a[i] == h) {
			cnt = i ;
		}
	}
	
	
	int x = 1 , y = 1 , l = 1 , i = 1;
	
	while (1) {
		if(i == cnt) {
			cout << y << " " << x ;
			return 0 ;
		}else {
			if(l == 1 && x != n) {
				x ++ ;
			}else if(l == 0 && x != 1) {
				x -- ;
			}else if(x == n) {
				y ++ ;
				l = 1 - l ;
			}else if (x == 1) {
				y ++ ;
				l = 1 - l ;
			}
			i ++ ;
		}
	}
	
	return 0 ;
}
