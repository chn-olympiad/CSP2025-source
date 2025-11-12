#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int c[MAXN][MAXN],n,m,a[MAXN];

inline bool cmp( const int &x,const int &y ){return x > y;}

int main(){
    freopen( "seat.in","r",stdin );
    freopen( "seat.out","w",stdout );
    scanf( "%d%d",&n,&m );
    for( int i = 1;i <= n * m;i++ ) scanf( "%d",&a[i] );
    int ans = a[1];
    sort( a + 1,a + n * m + 1,cmp );
    //for( int i = 1;i <= n * m;i++ ) printf( "%d ",a[i] );
    //printf( "\n" );
    int len = 0;
    for( int i = 1;i <= m;i++ )
        if( i & 1 )
            for( int j = 1;j <= n;j++ ) c[j][i] = a[++len];
        else
            for( int j = n;j;j-- ) c[j][i] = a[++len];
    //for( int i = 1;i <= n;i++,printf( "\n" ) )
        //for( int j = 1;j <= m;j++ )
            //printf( "%d ",c[i][j] );
    bool flag = false;
    for( int i = 1;i <= n && !flag;i++ )
        for( int j = 1;j <= m && !flag;j++ )
            if( c[i][j] == ans ) printf( "%d %d\n",j,i ),flag = true;

    return 0;

}
