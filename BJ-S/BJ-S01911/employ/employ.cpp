#include<bits/stdc++.h>

using namespace std;

void init()
{
    freopen( "employ.in" , "r" , stdin );
    freopen( "employ.out" , "w" , stdout );
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int mod = 998244353;

int n , m , a[510] , k , ans;
char s[510];

int main()
{
    init();
    cin >> n >> m >> s + 1;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a[i];
    sort( a + 1 , a + n + 1 );
    for ( int i = 1 ; i <= n ; i++ )
        k += s[i] == '1';
    if ( n == m )
    {
        cout << ( k == n ) << endl;
        return 0;
    }
    int p[510];
    for ( int i = 1 ; i <= n ; i++ )
        p[i] = i;
    do
    {
        int now = 0 , b[510] , cnt = 0;
        for ( int i = 1 ; i <= n ; i++ )
            b[p[i]] = i;
        for ( int i = 1 ; i <= n ; i++ )
            if ( now < a[b[i]] && s[i] == '1' ) cnt++;
            else now++;
        if ( cnt >= m ) ans++;
    } while( next_permutation( p + 1 , p + n + 1 ) );
    cout << ans << endl;
    return 0;
}
