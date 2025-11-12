#include<bits/stdc++.h>

using namespace std ;

int n ;

int a[6000] = {} ;
int ans = 0 ;


int main(){
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	
	cin >> n ;
	for(int i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
	}
	int m = 3 ;
	while(m < n ){
		int q = n - m +1  ;
		int num = 0 ;
		
		for(int i = 1 ; i <= q ; i++){
			int maxn = -1 ;
			for(int j = i ; j <= i+m-2;j++){
				num +=a[j] ;
				maxn = max(maxn,a[j]) ;
			}
			
			for(int j = i+m-2 ; i <= n ; i++ ){
				int maxn1 = maxn ;
				maxn1 = max(maxn1, a[j]) ;
				maxn1 *= 2 ;
				int sum = num + a[j] ;
				if(sum > maxn1){
					ans++ ;
				}
			}
		}
		
		m++ ; 
	}
	ans-- ; 
	cout << ans ;
	return 0 ;
}
