#include <bits/stdc++.h>

using namespace std ;

int n , m ;
int q , id ;

inline int up(int x) {
    if (x % n == 0) return x / n ;
    return x / n + 1 ;
}

inline int down(int x) {
    if ((x % n) == 0) return n ;
    return x % n ;
}

int main() {
    freopen("seat.in" , "r" , stdin) ;
    freopen("seat.out" , "w" , stdout) ;
    scanf("%d %d" , &n , &m) ;
    scanf("%d" , &q) ;
    id = 1 ;
    for (int i = 1 ; i < (n * m) ; i++) {
        int num ;
        scanf("%d" , &num) ;
        if (num > q) id++ ;
    }
    printf("%d " , up(id)) ;
    if ((id / n) % 2 == 1) {
        if (id % n == 0) printf("%d\n" , n) ;
        else printf("%d\n" , m - id % n + 1) ;
    }
    else {
        if (id % n == 0) puts("1") ;
        else printf("%d\n" , down(id)) ;
    }
    return 0 ;
}
