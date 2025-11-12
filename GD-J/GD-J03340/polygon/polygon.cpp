#include<bits/stdc++.h>
using namespace std ;
int a[5005] ; 
int n ;
long long mod = 998244353 ; 
int main(){
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ; 
	cin >> n ; 
	for(int i  =0 ; i < n ; i++){
		cin >> a[i] ; 
	}
	long long ans = 0 ; 
	for(int i = 0 ; i < (1<<n) ; i++){
		if(__builtin_popcount(i) < 3)continue ;
		long long sum = 0 ;
		int maxn = -1 ;
		for(int j = 0 ; j < n ; j++){
			if(i&(1<<j)){
				maxn = max(maxn , a[j]) ; 
				sum += a[j] ; 
			}
		}
		if(maxn*2 < sum){
			ans++ ;
		}
	}
	cout << ans%mod ; 
	return 0 ; 
}
