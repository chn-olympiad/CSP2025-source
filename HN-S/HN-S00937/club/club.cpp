#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;

int t, n, ans;
int a[N][3], cnt[3], pos[N];
vector < int > p;

signed main () {
    freopen ( "club.in", "r", stdin );
    freopen ( "club.out", "w", stdout );
    ios :: sync_with_stdio ( false );
    cin.tie ( 0 ), cout.tie ( 0 );
    cin >> t;
    while ( t -- ) {
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = ans = 0;
        p.clear ();
        for ( int i = 1; i <= n; ++ i ) {
            int maxi = 0;
            for ( int j = 0; j < 3; ++ j ) {
                cin >> a[i][j];
                maxi = max ( maxi, a[i][j] );
            }
            for ( int j = 0; j < 3; ++ j ) {
                if ( a[i][j] == maxi ) {
                    cnt[j] ++, pos[i] = j, ans += maxi;
                    break;
                }
            }
        }
        if ( max ( { cnt[0], cnt[1], cnt[2] } ) <= n / 2 ) {
            cout << ans << '\n';
        }
        else {
            if ( cnt[0] > n / 2 ) {
                for ( int i = 1; i <= n; ++ i ) {
                    if ( pos[i] == 0 ) {
                        p.push_back ( max ( a[i][1] - a[i][0], a[i][2] - a[i][0] ) );
                    }
                }
                sort ( p.begin (), p.end (), [] ( int x, int y ) { return x > y; } );
                for ( int i = 0; i < cnt[0] - n / 2; ++ i ) {
                    ans += p[i];
                }
                cout << ans << '\n';
            }
            else if ( cnt[1] > n / 2 ) {
                for ( int i = 1; i <= n; ++ i ) {
                    if ( pos[i] == 1 ) {
                        p.push_back ( max ( a[i][0] - a[i][1], a[i][2] - a[i][1] ) );
                    }
                }
                sort ( p.begin (), p.end (), [] ( int x, int y ) { return x > y; } );
                for ( int i = 0; i < cnt[1] - n / 2; ++ i ) {
                    ans += p[i];
                }
                cout << ans << '\n';
            }
            else {
                for ( int i = 1; i <= n; ++ i ) {
                    if ( pos[i] == 2 ) {
                        p.push_back ( max ( a[i][0] - a[i][2], a[i][1] - a[i][2] ) );
                    }
                }
                sort ( p.begin (), p.end (), [] ( int x, int y ) { return x > y; } );
                for ( int i = 0; i < cnt[2] - n / 2; ++ i ) {
                    ans += p[i];
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}