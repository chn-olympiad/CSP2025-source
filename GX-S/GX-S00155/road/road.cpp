#include<bits/stdc++.h>
using namespace std; 

const int N = 1e4 + 25 , M = 1e6 + 5 ; 

int n , m , k ;

array<int,3> ed[M] ;

int fa[N] ;

inline int find(int x) {
    if(x == fa[x]) return x ;
    return fa[x] = find(fa[x]) ;
}

array<int,3>  a[11][N] ;

int cost[N] ;

vector<array<int,3 >> B , nwb , nx ; 

inline int read() {
    int x = 0 ; char c = getchar() ; 
    while ( c < '0' || c > '9' ) c = getchar() ; 
    while( c >= '0' && c <='9' ) x = x * 10 + c -'0' , c = getchar() ;
    return x ;
}

using ll = long long ;

signed main() {
    freopen("road.in","r",stdin) ;
    freopen("road.out","w",stdout) ;
    double t = clock() ; 
    n = read() ; m =read() ;  k= read() ; 
    for(int i = 1 ;i <= n ; i ++ ) fa[i] = i ; 
    for(int i = 1 ;i <= m ; ++ i)  ed[i][0] = read() , ed[i][1] = read() ,  ed[i][2] = read()  ;
    sort(ed+1,ed+1+m,[&](array<int,3> t1,array<int,3> t2 ) { 
        return t1[2] < t2[2] ; 
    }) ;

    ll ans = 0 ;

    for(int i = 1 ; i <= m ; i ++ ) {
        int x = find(ed[i][0]) , y = find(ed[i][1]) ; 
        if(find(x) == find(y) ) continue ;
        fa[x] = y ; ans += ed[i][2] ;
        B.push_back(ed[i]) ; 
    }

    for(int i = 1 ; i <= k ; i ++ ) {
        cost[i] = read() ;
        for(int j = 1 ; j <= n ; j ++ ) a[i][j][2] = read() , a[i][j][0] = i + n , a[i][j][1] = j ;
        sort(a[i]+1,a[i]+1+n,[&](array<int,3> t1,array<int,3> t2 ) { 
            return t1[2] < t2[2] ; 
        }) ;
    }

    for(int S = 1; S < (1<<k) ; S ++ )  {
        ll calc = 0 ;nwb.clear() ;
        nwb = B; 
        for(int i = 1 ; i <= k ; i++ ) if ( S >> (i-1) & 1 ) {
            calc += cost[i];
            nx.clear() ;
            for(int j = 1 , als = 0 ; j <= n || als < nwb.size() ; ) {
                if(j <= n && (als == nwb.size() || a[i][j][2] <= nwb[als][2]) ) nx.push_back(a[i][j++]) ; 
                else nx.push_back(nwb[als++]) ; 
            } nwb = nx  ;
        } 
        if(calc >= ans ) continue ;
        for(int i = 1 ;i <= n + k ; i ++ ) fa[i] = i ; 
        for(auto z : nwb ) {
            int x = find(z[0]) , y = find(z[1]) , w = z[2] ;
            if(x  == y ) continue ;
            calc += w ; fa[x] = y ;
            if(calc >= ans )break ; 
        } ans = min(ans, calc) ; 

    } cout << ans << '\n' ;
    return 0 ;
}