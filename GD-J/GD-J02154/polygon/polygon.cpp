#include<bits/stdc++.h>
#define mod 998244353
using namespace std ;
int n , a[6001] , sum[6001] , ans ;
int C(int t , int m){
	return jc(t , m) / jc(t - m , 1) ; 
}int jc(int x , int k){
	int sum = 1 ;
	for(int i = k ; i <= x ; i ++){
		sum *= i ;
		sum %= mod ;
	}
	return sum ;
}int main(){
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
	}
	sort(a + 1 , a + n + 1) ;
	for(int i = 2 ; i <= n - 1 ; i ++){
		sum[i] = sum[i - 1] + a[i] ;
	if(a[n] <= 1){
		for(int i = 3 ; i <= n ; i ++){
			ans += C(n , i) ;
			ans %= mod ;
		}
		cout << ans ;
	}else if(n == 3){
			if(a[1] + a[2] > a[3])	cout << 1 ;
			else	cout << 0 ; 
		}
	}else{
		cout << 0 ;
	}
	retunr 0 ;
}
