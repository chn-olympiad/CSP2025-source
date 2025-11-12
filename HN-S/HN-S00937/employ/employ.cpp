#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505;
const int mod = 998244353;

int n, m;
int a[N], f[1 << 18][20];
string op;

inline bool check () {
    for ( int i = 1; i <= n; i ++ ) {
        if ( op[i] == '0' ) {
            return false;
        }
    }
    return true;
}

signed main () {
    freopen ( "employ.in", "r", stdin );
    freopen ( "employ.out", "w", stdout );
    ios :: sync_with_stdio ( false );
    cin.tie ( 0 ), cout.tie ( 0 );
    cin >> n >> m;
    cin >> op;
    op = " " + op;
    for ( int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    if ( n <= 18 ) {
        f[0][0] = 1;
        for ( int s = 0; s < ( 1 << n ); s ++ ) {
            for ( int j = 0; j <= n; j ++ ) {
                int cnt = 0;
                for ( int i = 0; i < n; i ++ ) {
                    cnt += ( s >> i & 1 );
                }
                for ( int i = 0; i < n; i ++ ) {
                    if ( !( s >> i & 1 ) ) {
                        if ( op[cnt + 1] == '0' ) {
                            f[s | ( 1 << i )][j + 1] += f[s][j];
                            f[s | ( 1 << i )][j + 1] %= mod;
                        }
                        else {
                            if ( j >= a[i + 1] ) {
                                f[s | ( 1 << i )][j + 1] += f[s][j];
                                f[s | ( 1 << i )][j + 1] %= mod;
                            }
                            else {
                                f[s | ( 1 << i )][j] += f[s][j];
                                f[s | ( 1 << i )][j] %= mod;
                            }
                        }
                    }
                }
                // cout << s << " " << j << " " << f[s][j] << '\n';
            }
        }
        int ans = 0;
        for ( int i = 0; i <= n - m; i ++ ) {
            ans += f[( 1 << n ) - 1][i];
            ans %= mod;
            // cout << i << " " << f[( 1 << n ) - 1][i] << '\n';
        }
        cout << ans;
    }
    else if ( m == n ) {
        int ans = 1;
        for ( int i = 1; i <= n; i ++ ) {
            ans *= i;
            ans %= mod;
            if ( op[i] == '0' ) {
                cout << 0;
                return 0;
            }
            if ( a[i] == '0' ) {
                cout << 0;
                return 0;
            }
        }
        cout << ans;
    }
    else if ( check () ) {
        int pos = 0, cnt = 0;
        while ( pos + 1 <= n && a[pos] <= cnt ) {
            pos ++;
            cnt ++;
        }
        int ans = 1;
        for ( int i = 1; i <= n - pos; i ++ ) {
            ans *= i;
            ans %= mod;
        }
        cout << ans;
    }
    else if ( m == 1 ) {
        cout << "ren sheng you mong, ge zi jing cai\n";
        cout << "qv bu liao WC le";
    }
    return 0;
}