#include <bits/stdc++.h>
using namespace std ;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
const int N = 2e4 + 9 ;
const int M = 4e6 + 9 ;
const int inf = 1e18 ;
int n , m , k ;
struct node{
    int u , v , w ;
}a[M];
// vector<node> e[N] ;
node e[M] ;
int tot ;
bool p[N] ;
int ans ;
void add ( int u , int v , int w ){
    e[++tot] = (node) { u , v , w } ;
}
struct point{
    int w ;
    int len[N] ;
}c[15] ;
struct Set{
    int fa[N] ;
    void init ( ){
        for ( int i = 0 ; i < N ; ++i ) fa[i] = i ;
    }
    int find ( int x ){
        if ( x != fa[x] ){
            return fa[x] = find ( fa[x] ) ;
        }else{
            return x ;
        }
    }
    void marge ( int x , int y ){
        fa[x] = y ;
    }
}s;
int work ( ){
    int res = 0 ;
    s.init ( ) ;
    tot = 0 ;
    // for ( int i = 1 ; i <= m ; ++i ){
    //     add ( a[i].u , a[i].v , a[i].w ) ;
    // }
    int sum_point = n ;
    for ( int i = 1 ; i <= k ; ++i ){
        // cout << p[i] << " " ;
        if ( p[i] == false ) continue ;
        res += c[i].w ;
        ++sum_point ;
        for ( int j = 1 ; j <= n ; ++j ){
            add ( n + i , j , c[i].len[j] ) ;
        }
    }
    sort ( e + 1 , e + tot + 1 , []( const node &x , const node &y ){
        return x.w < y.w ;
    }) ;
    // cout << "\n" ;
    int u , v , w ;
    int sum_edge = 0 ;
    int a_pos = 0 ;
    for ( int i = 1 ; i <= tot ; ++i ){
        u = e[i].u , v = e[i].v , w = e[i].w ;
        u = s.find ( u ) , v = s.find ( v ) ;
        while ( w > a[a_pos+1].w && a_pos < m ){
            ++a_pos ;
            int au = a[a_pos].u , av = a[a_pos].v , aw = a[a_pos].w ;
            // cout << aw << " " ;
            au = s.find ( au ) , av = s.find ( av ) ;
            if ( au != av ){
                res += aw ;
                ++sum_edge ;
                if ( sum_edge == sum_point - 1 ) break ;
                s.marge ( au , av ) ;
            }
        }
        if ( sum_edge == sum_point - 1 ) break ;
        // cout << w << " " ;
        if ( u != v ){
            res += w ;
            ++sum_edge ;
            if ( sum_edge == sum_point - 1 ) break ;
            s.marge ( u , v ) ;
        }
        if ( sum_edge == sum_point - 1 ) break ;
    }
    if ( a_pos != m ){
        for ( int i = a_pos + 1 ; i <= m ; ++i ){
            int u = a[i].u , v = a[i].v , w = a[i].w ;
            u = s.find ( u ) , v = s.find ( v ) ;
            if ( u != v ){
                res += w ;
                ++sum_edge ;
                if ( sum_edge == sum_point - 1 ) break ;
                s.marge ( u , v ) ;
            }
            if ( sum_edge == sum_point - 1 ) break ;
        }
    }
    if ( sum_edge != sum_point - 1 ) res = inf ;
    // cout << "\n" ;
    // cout << res << "\n" ;
    return res ;
}
void dfs ( int t ){
    if ( t > k ){
        ans = min ( ans , work ( ) ) ;
        return ;   
    }
    p[t] = true ;
    dfs ( t + 1 ) ;
    p[t] = false ;
    dfs ( t + 1 ) ;
    return ;
}
signed main ( ){
    freopen ( "road.in" , "r" , stdin ) ;
    freopen ( "road.out" , "w" , stdout ) ;
    IOS ;
    ans = inf ;
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= m ; ++i ){
        // cin >> a[i].u >> a[i].v >> a[i].w ;
        cin >> a[i].u >> a[i].v >> a[i].w ;
        
    }
    sort ( a + 1 , a + m + 1 , [](const node &x , const node &y){
        return x.w < y.w ;
    }) ;
    for ( int i = 1 ; i <= k ; ++i ){
        cin >> c[i].w ;
        for ( int j = 1 ; j <= n ; ++j ){
            cin >> c[i].len[j] ;
        }
    }
    dfs ( 1 ) ;
    cout << ans << "\n" ;
    return 0 ;
}