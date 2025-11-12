#include <bits/stdc++.h>

using namespace std ;

int n , k ;
int q[500010] ;
int m ;
int sum ;

struct Info {
    int l , r ;
    bool v ;
} p[500010] ;

int main() {
    freopen("xor.in" , "r" , stdin) ;
    freopen("xor.out" , "w" , stdout) ;
    scanf("%d %d" , &n , &k) ;
    for (int i = 1 ; i <= n ; i++) scanf("%d" , &q[i]) ;
    for (int i = 1 ; i <= n ; i++) {
        int cnt = q[i] ;
        for (int j = i ; j <= n ; j++) {
            if (j != i) cnt ^= q[j] ;
            if (cnt == k) {
                p[++m].l = i , p[m].r = j ;
            }
        }
    }
    for (int i = 1 ; i <= m ; i++) {
        int cnt = 1 ;
        int R = p[i].r ;
        for (int j = i + 1 ; j <= m ; j++) if (p[j].l > R) R = p[j].r , cnt++ ;
        sum = max(sum , cnt) ;
    }
    printf("%d\n" , sum) ;
    return 0 ;
}
