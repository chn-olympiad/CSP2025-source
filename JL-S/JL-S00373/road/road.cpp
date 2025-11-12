#include <bits/stdc++.h>
using namespace std ;
int main (){
    int n, m, k ;
    scanf ("%d%d%d", &n, &m, &k) ;
    for (int i=1; i<=m; i++){
        int u, v, w ;
        scanf ("%d%d%d", &u, &v, &w) ;
    }
    int c[90], a[90][10006] ;
    for (int i=1; i<=k; i++){
        scanf ("%d", &c[i]) ;
        for(int j=1; j<=n; j++)
            scanf ("%d", &a[i][j]) ;
    }
    long long cnt = 0 ;
    printf ("%lld", cnt) ;
    return 0 ;
    }
