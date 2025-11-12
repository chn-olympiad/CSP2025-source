#include<bits/stdc++.h>

using namespace std;

void init()
{
    freopen( "road.in" , "r" , stdin );
    freopen( "road.out" , "w" , stdout );
}

/*
4 5 0
1 2 2
1 3 3
2 3 0
2 4 5
3 4 4

*/

inline int read()
{
    char c = getchar();
    int ret = 0;
    while ( !isdigit(c) ) c = getchar();
    while ( isdigit(c) )
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}

struct edge
{
    int u , v , w;
    bool operator < ( const edge &b ) const
    {
        if ( w == b.w )
            if ( u == b.u )
                return v < b.v;
            else return u < b.u;
        else return w < b.w;
    }
}a[20][10010];

set < edge > g;

int n , m , k;
long long ans = ~0ULL >> 1;
int c[20] , f[10020] , cnt[10020];
bool flag;

inline void bd()
{
    for ( int i = 1 ; i <= n + k ; i++ )
        f[i] = i , cnt[i] = i <= n;
}

inline int find( int x )
{
    if ( f[x] == x )
        return x;
    else return f[x] = find( f[x] );
}

inline void merge( int x , int y , int &now )
{
    if ( find(x) != find(y) )
    {
        f[find(x)] = f[find(y)];
        cnt[x] += cnt[y];
        now = max( now , cnt[x] );
    }
}

inline long long solve( int st )
{
    int tmp = m , tmpp = st , now = 1;
    long long ret = 0;
    bd();
    for ( int i = 1 ; st ; i++ )
    {
        if ( st & 1 )
        {
            for ( int j = 1 ; j <= n ; j++ )
                g.insert(a[i][j]);
            ret += c[i];
        }
        st >>= 1;
    }
    st = tmpp;
    for ( auto it = g.begin() ; now <= n - 1 && it != g.end() ; ++it )
    {
        if ( find( it -> u ) != find( it -> v ) )
        {
            ret += it -> w;
            merge( it -> u , it -> v , now );
            if ( ret > ans ) break;
        }
    }

    for ( int i = 1 ; st ; i++ )
    {
        if ( st & 1 )
            for ( int j = 1 ; j <= n ; j++ )
                g.erase( g.lower_bound( a[i][j] ) );
        st >>= 1;
    }
    return ret;
}

int main()
{
    init();
    #ifdef lhw
    auto t1 = time(0);
    #endif 
    n = read();
    m = read();
    k = read();
    for ( int i = 1 ; i <= m ; i++ )
        g.insert( { read() , read() , read() } );

    for ( int i = 1 ; i <= k ; i++ )
    {
        c[i] = read();
        if ( c[i] ) flag = 1;
        for ( int j = 1 ; j <= n ; j++ )
        {
            a[i][j].w = read();
            a[i][j].u = n + i;
            a[i][j].v = j;
        }
    }

    ans = solve(0);
    for ( int i = 1 ; i < 1 << k ; i++ )
    {
        if ( !flag ) i = ( 1 << k ) - 1;
        ans = min( ans , solve(i) );
    }
    
    printf( "%lld\n" , ans );
    #ifdef lhw
    cout << time(0) - t1 << endl;
    #endif
    return 0;
}
