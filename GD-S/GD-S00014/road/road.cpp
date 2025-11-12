#include<bits/stdc++.h>
//-fsanitize=address,undefined
//For my dearest,Venti,[] and 3_7.
//st:15:53
//ed:17:03
//exp:test 0 | 0 pts
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e4 + 5;
const int MAXM = 1e6 + 5;
const int MAXK = 10 + 5;
int N, M, K;
int a, c;
// struct node{
//     int u, v, w;
// }e[MAXM * 2];
struct star{
    int nxt, to, w;
}edge[MAXM * 4];
int head[MAXN * 2], cnt;
// int cnt = 0;
void add( int u, int v, int w ){
    // cerr << u << " " << v << " " << w << endl;
    // e[++ cnt] = { u, v, w };
    edge[++ cnt] = { head[u], v, w };
    head[u] = cnt;
}

struct dsu{
    int fa[MAXN];
    void init( int n ){ for( int i = 1; i <= n; i ++ ) fa[i] = i; }

    int fnd( int x ){
        if( fa[x] == 0 ) return x;
        else return fa[x] = fnd( x );
    }

    void join( int x, int y ){//x -> y
        // int fx = fnd( x ), fy = fnd( y );
        fa[x] = y;
    }
}d;

struct Node{
    int id, x;
    bool operator < ( const Node & nd ) const{
        return x > nd.x;
    }
};

int dis[MAXN * 2];
bool vis[MAXN * 2];

void dij( int st ){
    for( int i = 1; i <= N * 2 + 2; i ++ ){
        dis[i] = inf;
        vis[i] = 0;
    }
    dis[st] = 0;
    priority_queue<Node> q;
    q.push({ st, 0 });
    while( !q.empty() ){
        int u = q.top().id;
        q.pop();
        if( vis[u] ) continue;
        vis[u] = true;
        for( int i = head[u]; i; i = edge[i].nxt ){
            int v = edge[i].to;
            if( dis[v] > edge[i].w + dis[u] ){
                dis[v] = edge[i].w + dis[u];
                q.push({ v, dis[v] });
            }
        }
    }
}

// bool cmp( node a, node b ){
//     return a.w < b.w;
// }

// int kru(){
//     d.init( N );
//     int ans = 0;
//     // cout << cnt;
//     sort( e + 1, e + cnt + 1, cmp );
//     // for( int i = 1; i <= cnt; i ++ ){
//     //     cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
//     // }
//     for( int i = 1, tot = 0; tot <= N && i <= cnt; i ++ ){
// //         cout << 1;
//         int fx = d.fnd( e[i].u );
//         int fy = d.fnd( e[i].v );
// //        cerr << e[i].u << " " << e[i].v << " " << e[i].w << endl;
//         if( fx == fy ) continue;
//         d.join( fx, fy );
//         ans += e[i].w;
//         tot ++;
//     }
//     cout << 1; 
//     return ans;
// }

int main(){
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cout.tie( 0 );
    // freopen( "road.in", "r", stdin );
    // freopen( "road.out", "w", stdout );
    cin >> N >> M >> K;
    for( int i = 1; i <= M; i ++ ){
        int u, v, w;
        cin >> u >> v >> w;
        add( u, v, w );
        add( v, u, w );
        // for( int j = 1; j <= K; j ++ ){
        int j = 1;
        // if( u > K ) add( u + ( j - 1 ) * N, u + j * N, w );
        // if( v > K ) add( v + ( j - 1 ) * N, v + j * N, w );
        add( u + j * N, v + j * N, w );
        add( v + j * N, u + j * N, w );
        // }
    }

    for( int i = 1; i <= K; i ++ ){
        cin >> c;
        add( i, i + N, c );
        // cout << c << endl;
        for( int j = 1; j <= N; j ++ ){
            cin >> a;
            add( i + N, j + N, a );
            add( j + N, i + N, a );
        }
    }
    int ans = 0;
    for( int i = 1; i <= N; i ++ ){
        dij( i );
        // cout << i << endl;
        for( int j = 1; j <= N; j ++ ){
            // cout << j << " " << dis[j] << " " << dis[j + N] << endl;
            ans = max( ans, min( dis[j], dis[j + N] ) );
        }
    }
    cout << ans + 2;
    // kru();
    // cout << kru();
    return 0;
}
