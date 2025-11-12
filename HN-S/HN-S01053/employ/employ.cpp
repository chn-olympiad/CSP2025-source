#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using std::cin ;
using std::string ;
using std::sort ;

int n , m , isum = 0 , ans = 1 ;
int a[510] ;
string k ;

int main(void){
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
	scanf("%d %d" , &n , &m) ;
	cin >> k ;
	for(int i = 0 ; i < n ; i ++)  scanf("%d" , &a[i]) ;
	sort(a , a + n) ;
	for(int i = 0 ; i < k.length() ; i ++){
		if(k[i] == '1')  isum ++ ;
	}
	for(int i = k.length() - 1 ; i >= 0 ; i --){
		int cr = 0 ;
		if(k[i] == '0')  cr = i + 1 ;
		else{
			for(int j = n - 1 ; j >= 0 ; j --){
				if(a[i] >= i){
					a[i] = -1 ;
					cr ++ ;
				}
				else  break ;
			}
		}
		//std::cout << cr << std::endl ;
		ans *= cr % 998244353 ;
	}
	printf("%d\n" , ans) ;
}

/**
  至那个曾经奋斗过的自己： 
  	结束了。
  	也感谢那些一路走来陪伴我的人。
  	虽然结果可能稍微差了点，
  	但是开心最好喵~ 
	    					    2025-11-1
**/

