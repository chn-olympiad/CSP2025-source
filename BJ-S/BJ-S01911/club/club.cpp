#include<bits/stdc++.h>

using namespace std;

void init()
{
    freopen( "club.in" , "r" , stdin );
    freopen( "club.out" , "w" , stdout );
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

inline int diff( int b[5] )
{
    sort( b + 1 , b + 4 );
    return b[3] - b[2];
}

inline int getmx( int b[5] )
{
    int mx = max({ b[1] , b[2] , b[3] });
    if ( mx == b[1] ) return 1;
    else if ( mx == b[2] ) return 2;
    else return 3;
}

inline void solve()
{
    int n , ans = 0;
    vector < int > c[5];
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int a[5];
        cin >> a[1] >> a[2] >> a[3];
        c[ getmx( a ) ].push_back( diff( a ) );
        ans += max( { a[1] , a[2] , a[3] } );
    }
    int a[5] = { 0 , ( int ) c[1].size() , ( int ) c[2].size() , ( int ) c[3].size() };
    int idx = getmx(a);
    if ( c[idx].size() <= n >> 1 ) cout << ans << endl;
    else
    {
        for ( int i = 1 ; i <= 3 ; i++ )
            sort( c[i].begin() , c[i].end() );
        #ifdef lhw
        for ( int &x : c[idx] )
            cout << x << ' ';
        cout << endl;
        #endif
        for ( int i = 0 ; i < c[idx].size() - ( n >> 1 ) ; i++ )
            ans -= c[idx][i];
        cout << ans << endl;
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while ( t-- )
        solve();
    return 0;
}
