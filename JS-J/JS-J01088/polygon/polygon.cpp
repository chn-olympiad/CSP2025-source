#include <bits/stdc++.h>

using namespace std ;

int n ;
int q[5010] ;
int sum ;

inline void dfs(int x , int cnt , int res) {
    if ((x == n) && (res > 2)) {
        sum++ ;
        sum %= 998244353 ;
        return ;
    }
    if (res < 3) {
        dfs(x + 1 , cnt + q[x] , res + 1) ;
        dfs(x + 1 , cnt , res) ;
        return ;
    }
    if (cnt > q[x]) {
        dfs(x + 1 , cnt + q[x] , res + 1) ;
        dfs(x + 1 , cnt , res) ;
    }
    else dfs(x + 1 , cnt , res) ;
}

int main() {
    freopen("polygon.in" , "r" , stdin) ;
    freopen("polygon.out" , "w" , stdout) ;
    scanf("%d" , &n) ;
    for (int i = 1 ; i <= n ; i++) scanf("%d" , &q[i]) ;
    sort(q + 1 , q + n + 1) ;
    if (n < 3) {
        puts("0") ;
    }
    if (n == 3) {
        if ((q[3] * 2) < (q[1] + q[2])) {
            puts("1") ;
            return 0 ;
        }
        else {
            puts("0") ;
            return 0 ;
        }
    }
    dfs(1 , 0 , 0) ;
    printf("%d\n" , sum) ;
    return 0 ;
}
