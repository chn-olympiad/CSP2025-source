#include<bits/stdc++.h>

using namespace std ;

int n ;

int a[5005] ;

int sum ;

long long ans ;

long long sum1[5005] ;

signed main() {
	
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ; 

	scanf("%d" , &n) ;
	for(int i = 1 ; i <= n ; i ++) {
		scanf("%d" , &a[i]) ;
		sum += a[i] ;
		sum1[i] = sum1[i-1] + a[i] ; 
	}

	sort(a + 1 , a + n + 1) ;

	if(n == 3) {
		if(a[3] * 2 < sum) {
			ans ++ ;
		}
		printf("%lld" , ans) ;
		return 0 ;
	}
	bool flag = 0 ;
	for(int i = 1 ; i <= n ;  i++) {
		if(a[i] != 1) {
			flag = 1 ;
		}
	}
	if(flag == 0) {
		for(int i = n ; i >= 3 ; i --) {
			for(int j = i - 2 ; j >= 1 ; j --) {
				ans += j ;
				//cout << i << " " << j << endl ;
			}
			ans %= 998244353 ;
		}
		printf("%lld" , ans % 998244353) ;
	}


	return 0 ;
}
/*
5
2 2 3 8 10

6

5
1 2 3 4 5

9

*/
