#include <bits/stdc++.h>

using namespace std ;

#define ll long long

int tong[20] ;


int main (){
	 freopen ("number.in" , "r" , stdin) ;
	 freopen ("number.out" , "w" , stdout) ;
	
//	scanf ("%s" , s) ;
	char ch = getchar_unlocked() ;
	while (ch != ' ' && ch != '\n') {
		if (ch <= '9' && ch >= '0')	tong[ch - '0']++ ;
		ch = getchar_unlocked() ;
	}


	for (int i = 9 ; i >= 0 ; --i) {
		for (int j = 1 ; j <= tong[i] ; ++j) {
			putchar (i + '0') ;
		}
	}
	
	return 0 ;
}