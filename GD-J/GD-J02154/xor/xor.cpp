#include<bits/stdc++.h>
using namespace std ;
int n , k , a[500001] , sum[500001][3] , ans ;
bool flag ;
int main(){
	freopen("xor.in" , "r" , stdin) ;
	freopen("xor.out" , "w" , stdout) ;
	cin >> n >> k ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
	}for(int i = 1 ; i <= n ; i ++){
		int j = i ;
		for(int o = j ; o <= n ; o ++){
			sum[o - j + 1][0] = o ;
			sum[o - j + 1][1] = sum[o - (j - 1) + 1][1] ^ a[o - j + 1] ;
			if(sum[o - j + 1][1] == k){
				for(int p = o - j + 1 ; p <= o ; p ++){
					if(a[p] == -1){
						flag = 1 ;
						break ;
					}
				}if(flag){
					flag = 0 ;
					continue ;
				}
				//cout <<"[" << o - j + 1 <<"," << o <<"]" << endl ;
				ans ++ ;
				for(int p = o - j + 1 ; p <= o ; p ++){
					a[p] = sum[o - j + 1][1] = -1 ;
				}
			}
		}
	}
	cout << ans ;
} 
