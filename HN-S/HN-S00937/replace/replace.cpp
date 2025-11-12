#include <bits/stdc++.h>
#define int long long

using namespace std;
using ull = unsigned long long;

const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int B = 13331;
const int B2 = 31113;

int n, m;
int ans[N], l[N], r[N];
string s[N], t[N], p[N], q[N];
ull pw[M], pw2[M];
vector < pair < ull, ull > > hsh[N], hsh2[N], hsh3[N], hsh4[N];
map < pair < pair < ull, ull >, pair < ull, ull > >, vector < int > > mp;

inline pair < ull, ull > query ( int id, int l, int r ) {
    return { ( hsh[id][r].first + mod - hsh[id][l - 1].first * pw[r - l + 1] % mod ) % mod, ( hsh[id][r].second + mod - hsh[id][l - 1].second * pw2[r - l + 1] % mod2 ) % mod2 };
}

inline pair < ull, ull > query2 ( int id, int l, int r ) {
    return { ( hsh2[id][r].first + mod - hsh2[id][l - 1].first * pw[r - l + 1] % mod ) % mod, ( hsh2[id][r].second + mod - hsh2[id][l - 1].second * pw2[r - l + 1] % mod2 ) % mod2 };
}

inline pair < ull, ull > query3 ( int id, int l, int r ) {
    return { ( hsh3[id][r].first + mod - hsh3[id][l - 1].first * pw[r - l + 1] % mod ) % mod, ( hsh3[id][r].second + mod - hsh3[id][l - 1].second * pw2[r - l + 1] % mod2 ) % mod2 };
}

inline pair < ull, ull > query4 ( int id, int l, int r ) {
    return { ( hsh4[id][r].first + mod - hsh4[id][l - 1].first * pw[r - l + 1] % mod ) % mod, ( hsh4[id][r].second + mod - hsh4[id][l - 1].second * pw2[r - l + 1] % mod2 ) % mod2 };
}

signed main () {
    freopen ( "replace.in", "r", stdin );
    freopen ( "replace.out", "w", stdout );
    ios :: sync_with_stdio ( false );
    cin.tie ( 0 ), cout.tie ( 0 );
    cin >> n >> m;
    pw[0] = pw2[0] = 1;
    for ( int i = 1; i < M; i ++ ) {
        pw[i] = pw[i - 1] * B % mod;
        pw2[i] = pw2[i - 1] * B2 % mod2;
    }
    for ( int i = 1; i <= n; i ++ ) {
        cin >> s[i] >> t[i];
        s[i] = " " + s[i], t[i] = " " + t[i];
        hsh[i].resize ( s[i].size () ), hsh2[i].resize ( t[i].size () );
        for ( int j = 1; j < s[i].size (); j ++ ) {
            hsh[i][j] = { ( hsh[i][j - 1].first * B % mod + s[i][j] ) % mod, ( hsh[i][j - 1].second * B2 % mod2 + s[i][j] ) % mod2 };
            hsh2[i][j] = { ( hsh2[i][j - 1].first * B % mod + t[i][j] ) % mod, ( hsh2[i][j - 1].second * B2 % mod2 + t[i][j] ) % mod2 };
        }
    }
    for ( int i = 1; i <= m; i ++ ) {
        cin >> p[i] >> q[i];
        p[i] = " " + p[i], q[i] = " " + q[i];
        if ( p[i].size () != q[i].size () ) {
            continue;
        }
        hsh3[i].resize ( p[i].size () ), hsh4[i].resize ( q[i].size () );
        for ( int j = 1; j < p[i].size (); j ++ ) {
            hsh3[i][j] = { ( hsh3[i][j - 1].first * B % mod + p[i][j] ) % mod, ( hsh3[i][j - 1].second * B2 % mod2 + p[i][j] ) % mod2 };
            hsh4[i][j] = { ( hsh4[i][j - 1].first * B % mod + q[i][j] ) % mod, ( hsh4[i][j - 1].second * B2 % mod2 + q[i][j] ) % mod2 };
        }
        int st = -1, ed = -1;
        for ( int j = 1; j < p[i].size (); j ++ ) {
            if ( p[i][j] != q[i][j] ) {
                st = j;
                break;
            }
        }
        for ( int j = p[i].size () - 1; j >= 1; j -- ) {
            if ( p[i][j] != q[i][j] ) {
                ed = j;
                break;
            }
        }
        l[i] = st, r[i] = ed;
        pair < ull, ull > _1 = { 0, 0 }, _2 = { 0, 0 };
        for ( int j = st; j <= ed; j ++ ) {
            _1 = { ( _1.first * B % mod + p[i][j] ) % mod, ( _1.second * B2 % mod2 + p[i][j] ) % mod2 };
            _2 = { ( _2.first * B % mod + q[i][j] ) % mod, ( _2.second * B2 % mod2 + q[i][j] ) % mod2 };
        }
        mp[{ _1, _2 }].push_back ( i );
    }
    for ( int i = 1; i <= n; i ++ ) {
        int st = -1, ed = -1;
        for ( int j = 1; j < s[i].size (); j ++ ) {
            if ( s[i][j] != t[i][j] ) {
                st = j;
                break;
            }
        }
        for ( int j = s[i].size () - 1; j >= 1; j -- ) {
            if ( s[i][j] != t[i][j] ) {
                ed = j;
                break;
            }
        }
        if ( st == -1 ) {
            continue;
        }
        pair < ull, ull > _1 = { 0, 0 }, _2 = { 0, 0 };
        for ( int j = st; j <= ed; j ++ ) {
            _1 = { ( _1.first * B % mod + s[i][j] ) % mod, ( _1.second * B2 % mod2 + s[i][j] ) % mod2 };
            _2 = { ( _2.first * B % mod + t[i][j] ) % mod, ( _2.second * B2 % mod2 + t[i][j] ) % mod2 };
        }
        for ( int id : mp[{ _1, _2 }] ) {
            if ( st <= l[id] && s[i].size () - ed <= p[id].size () - r[id] && query ( i, 1, st ) == query3 ( id, l[id] - st + 1, l[id] ) && query2 ( i, ed, s[i].size () - 1 ) == query4 ( id, r[id], r[id] + s[i].size () - ed - 1 ) ) {
                ans[id] ++;
            }
        }
    }
    for ( int i = 1; i <= m; i ++ ) {
        cout << ans[i] << '\n';
    }
    return 0;
}