#include <bits/stdc++.h>

using namespace std ;

int q[20] ;

int main() {
    freopen("number.in" , "r" , stdin) ;
    freopen("number.out" , "w" , stdout) ;
    while (true) {
        char c ;
        scanf("%c" , &c) ;
        if (c == 10) {
            break ;
        }
        if ((c >= '0') && (c <= '9')) {
            q[c - '0']++ ;
        }
    }
    for (int i = 9 ; i >= 0 ; i--) {
        for (; q[i]-- ;) printf("%d" , i) ;
    }
    return 0 ;
}
