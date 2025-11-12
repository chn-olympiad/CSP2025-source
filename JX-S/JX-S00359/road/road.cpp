#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll n , m , k , cost[100] , tot_m = 0 , tot_n = 0 , cnt = 0 , sum = 0 , sum2 = 0 , ans = LONG_LONG_MAX ;
bool b[100] ;
struct edge {
    int a , b ;
    int val ;
    friend bool operator < ( edge a , edge b ) {
        return a.val <= b.val ;
    }
}e[2000010];
int fa[2000010] ;
void build () {
    for ( int i = 1 ; i <= n+k+5 ; i ++ ) fa[i] = i ;
    return ;
}
void mergee ( int x , int y ) {
    fa[x] = fa[y] ;
    return ;
}
int findd ( int x ) {
    return fa[x]==x?x:fa[x]=findd(fa[x]) ;
}
void solve () {
    build() ;
    ll coun = 0 , res = sum ;
    for ( int i = 1 ; i <= tot_m ; i ++ ) {
        if (e[i].b > n) {
            if ( !b[e[i].b-n] ) continue ;
        }
        if ( findd(e[i].a) == findd(e[i].b) ) continue ;
        coun++ , mergee(e[i].a,e[i].b) , res += e[i].val ;
        if ( coun == n+sum2-1 ) break ;
    }
    ans = min(ans,res) ;
    return ;
}
void dfs ( int x ) {
    if ( x > k ) {
        sum = 0 , sum2 = 0 ;
            for ( int i = 1 ; i <= k ; i ++ ) {
                if ( b[i] ) sum2++ , sum+=cost[i] ;
            }
        solve() ;
        return ;
    }
    b[x] = 1 ;
    dfs(x+1) ;
    b[x] = 0 ;
    dfs(x+1) ;
}
int main () {
    freopen("road.in","r",stdin) ;
    freopen("road.out","w",stdout) ;
    //freopen("/home/noi/Desktop/road/road2.in","r",stdin) ;
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
    cin >> n >> m >> k ;
    tot_n = n+k ;
    tot_m = m+k*n ;
    for ( int i = 1 ; i <= m ; i ++ ) {
        cin >> e[i].a >> e[i].b >> e[i].val ;
    }
    for ( int i = 1 ; i <= k ; i ++ ) {
        cin >> cost[i] ;
        for ( int j = 1 ; j <= n ; j ++ ) {
            ++cnt ;
            cin >> e[cnt+m].val ;
            e[cnt+m].a = j , e[cnt+m].b = n+i ;
        }
    }
    sort(e+1,e+tot_m+1) ;
    dfs(1) ;
    cout << ans ;
    return 0 ;
}

