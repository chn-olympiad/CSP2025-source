#include<bits/stdc++.h>
using namespace std ;
int n , m , c , r , a[101] , a1 , k , sum ;
bool cmp(int x , int y){
	return x > y ;
}
int main(){
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n * m ; i ++){
		cin >> a[i] ;
		k = a[1] ;
	}
	sort(a + 1 , a + n * m + 1 , cmp) ;
	for(int i = 1 ; i <= n * m ; i ++){
		if(a[i] == k){
			sum = i ;
		}
	}
	if(sum % n == 0){
		c = sum / n ;
	}else{
		c = sum / n + 1 ;
	}if(c % 2 == 0){
		r = n - sum % n + 1 ;
	}else{
		if(sum % n == 0){
			r = n ;
		}else{
			r = sum % n ;
		}
	}
	cout << c <<" " << r ;
	return 0 ;
} 
