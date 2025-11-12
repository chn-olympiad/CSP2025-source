#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 15;
const int M = 1e6 + 15;

int n, m, k, cnt;
int v[15][N], fa[N], ji[15], siz[N];
vector < int > id;

struct Node {
    int u, v, w, id;
} a[M], b[M];

inline int find ( int x ) {
    if ( fa[x] == x ) {
        return x;
    }
    return fa[x] = find ( fa[x] );
}

inline void unionn ( int x, int y ) {
    x = find ( x ), y = find ( y );
    if ( siz[x] > siz[y] ) {
        swap ( x, y );
    }
    if ( x != y ) {
        fa[x] = y;
        siz[y] += siz[x];
    }
}

signed main () {
    freopen ( "road.in", "r", stdin );
    freopen ( "road.out", "w", stdout );
    ios :: sync_with_stdio ( false );
    cin.tie ( 0 ), cout.tie ( 0 );
    cin >> n >> m >> k;
    for ( int i = 1; i <= m; ++ i ) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].id = -1;
    }
    for ( int i = 0; i < k; ++ i ) {
        cin >> ji[i];
        for ( int j = 1; j <= n; ++ j ) {
            cin >> v[i][j];
        }
    }
    sort ( a + 1, a + 1 + m, [] ( Node x, Node y ) { return x.w < y.w; } );
    int ans = 0;
    for ( int i = 1; i <= n; ++ i ) {
        fa[i] = i, siz[i] = 1;
    }
    for ( int i = 1; i <= m; ++ i ) {
        if ( find ( a[i].u ) != find ( a[i].v ) ) {
            unionn ( a[i].u, a[i].v );
            id.push_back ( i );
            ans += a[i].w;
        }
    }
    for ( int x : id ) {
        b[++ cnt] = a[x];
    }
    for ( int j = 0; j < k; ++ j ) {
        for ( int l = 1; l <= n; ++ l ) {
            b[++ cnt] = { l, n + j + 1, v[j][l], j };
        }
    }
    sort ( b + 1, b + 1 + cnt, [] ( Node x, Node y ) { return x.w < y.w; } );
    for ( int i = 0; i < ( 1 << k ); ++ i ) {
        int res = 0, edges = n - 1;
        for ( int j = 0; j < k; ++ j ) {
            if ( i >> j & 1 ) {
                edges ++;
                res += ji[j];
            }
        }
        for ( int j = 1; j <= n + k; ++ j ) {
            fa[j] = j, siz[j] = 1;
        }
        for ( int j = 1; j <= cnt; ++ j ) {
            if ( b[j].id >= 0 & !( i >> b[j].id & 1 ) ) {
                continue;
            }
            if ( find ( b[j].u ) != find ( b[j].v ) ) {
                edges --;
                unionn ( b[j].u, b[j].v );
                res += b[j].w;
                if( res >= ans ) {
                    break;
                }
            }
            if ( edges == 0 ) {
                ans = min ( ans, res );
                break;
            }
        }
    }
    cout << ans;
    return 0;
}