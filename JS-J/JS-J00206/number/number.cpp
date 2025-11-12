#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1e2;

char s[MAXN];

int a[MAXN],n,len;

int main(){
    freopen( "number.in","r",stdin );
    freopen( "number.out","w",stdout );
    scanf( "%s",s + 1 ),len = strlen( s + 1 );
    for( int i = 1;i <= len;i++ )
        if( '0' <= s[i] && s[i] <= '9' ) a[++n] = s[i] - '0';
    sort( a + 1,a + n + 1 );
    for( int i = n;i;i-- ) printf( "%d",a[i] );
    printf( "\n" );

    return 0;

}
