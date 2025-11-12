#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 1e2,p = 998244353;

int n,a[MAXN],ans;

inline void dfs( int x,int sum,int ma ){
    if( x == n + 1 ){
        if( sum > 2 * ma ) ans++,ans %= p;
        return;
    }
    dfs( x + 1,sum + a[x],max( ma,a[x] ) );
    dfs( x + 1,sum,ma );
}

int main(){
    freopen( "polygon.in","r",stdin );
    freopen( "polygon.out","w",stdout );
    scanf( "%d",&n );
    for( int i = 1;i <= n;i++ ) scanf( "%d",&a[i] );
    dfs( 1,0,0 );
    printf( "%d\n",ans );


    return 0;

}
