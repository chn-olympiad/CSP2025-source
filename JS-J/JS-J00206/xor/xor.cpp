#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 1e2;

int n,k,a[MAXN],c[MAXN],f[MAXN][2];

int s[MAXN][MAXN];

int main(){
    freopen( "xor.in","r",stdin );
    freopen( "xor.out","w",stdout );
    scanf( "%d%d",&n,&k );
    for( int i = 1;i <= n;i++ ) scanf( "%d",&a[i] );
    for( int i = 1;i <= n;i++ ){
        c[i] = 1 << 30;
        for( int j = i;j <= n;j++ ){
            s[i][j] = s[i][j - 1] ^ a[j];
            if( s[i][j] == k ){c[i] = j;break;}
        }
    }
    //for( int i = 1;i <= n;i++ ) printf( "%d ",c[i] );
    //printf( "\n" );
    memset( f,128,sizeof( f ) ),f[1][0] = 0;
    if( c[1] == 1 ) f[1][1] = 1;
    for( int i = 1;i <= n;i++ ){
        for( int j = 1;j <= i;j++ )
            if( c[j] == i ) f[i][1] = max( f[i][1],f[j][0] + 1 );
            else f[i][0] = max( f[i][0],f[j][0] + ( c[j] < i ? 1 : 0 ) );
        for( int j = 1;j < i;j++ )
            if( c[j + 1] == i ) f[i][1] = max( f[i][1],f[j][1] + 1 );
            else f[i][0] = max( f[i][0],f[j][1] + ( c[j + 1] < i ? 1 : 0 ) );
    }
    //for( int i = 1;i <= n;i++ ) printf( "%d %d\n",f[i][0],f[i][1] );
    printf( "%d\n",max( f[n][0],f[n][1] ) );

    return 0;

}
