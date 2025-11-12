#include <cstdio>
#include <iostream>
#include <string>
using std::string ;
using std::cin ;

int n , q , ans ;
string l1 , l2 ;
string cp[200721][3] ;

int main(void){
	cin.tie(0) ;
	freopen("replace.in" , "r" , stdin) ;
	freopen("replace.out" , "w" , stdout) ;
	scanf("%d %d" , &n , &q) ;
	for(int i = 0 ; i < n ; i ++)  cin >> cp[i][1] >> cp[i][2] ;
	while(q --){
		ans = 0 ;
		cin >> l1 >> l2 ;
		for(int i = 0 ; i < n ; i ++){
			for(int loc = 0 ; loc <= (int)l1.length() - (int)cp[i][1].length() ; loc ++){
				if(l1.substr(loc , (int)cp[i][1].length()) == cp[i][1]){
					if(l1.substr(0 , loc) + cp[i][2] + l1.substr(loc + cp[i][1].length() , l1.length() - loc - cp[i][1].length()) == l2)  ans ++ ;
				}
			}
		}
		printf("%d\n" , ans) ;
	}
}

//  :(

