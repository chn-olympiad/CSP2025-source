#include<bits/stdc++.h>
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define rep2(i, a, b) for(int i = a; i >= b; --i)
#define ft first
#define sd second
#define pii pair <int, int>
#define ll long long
#define pb push_back
#define gmin(a, b) a = min(a, b)
#define gmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define debug cout << "------------------\n"
const int N = 4e5 + 10, M = 5e6 + 10, mod = 1e9 + 223;
using namespace std;
ll hsh[2][N], pw[M];
int L[N], R[N], len[N];
ll query(int tp, int l, int r) {
    ll val = hsh[tp][r] + mod - hsh[tp][l - 1] * pw[r - l + 1] % mod;
    return val % mod;
}
ll val[2][N];
void solve() {
    pw[0] = 1;
    rep1(i, 1, 5e6) pw[i] = pw[i - 1] * 131 % mod;

    int n, q; cin >> n >> q;
    rep1(i, 1, n) {
        string s, t; cin >> s >> t;
        int m = len[i] = s.size();
        s = ' ' + s; t = ' ' + t;
        rep1(j, 1, m) if(s[j] != t[j]) R[i] = j;
        rep2(j, m, 1) if(s[j] != t[j]) L[i] = j;
        rep1(j, 1, m) {
            val[0][i] = (val[0][i] * 131 % mod + s[j]) % mod;
            val[1][i] = (val[1][i] * 131 % mod + t[j]) % mod;
            // cout << val[0][i] << ' ' << val[1][i] << ' ' << s << ' ' << t << '\n';
        }
    }
    rep1(i, 1, q) {
        string s, t; cin >> s >> t;
        if(s.size() != t.size()) {cout << 0 << '\n'; continue;}
        int id = i + n;
        int m = len[id] = s.size();
        s = ' ' + s; t = ' ' + t;
        rep1(j, 1, m) if(s[j] != t[j]) R[id] = j;
        rep2(j, m, 1) if(s[j] != t[j]) L[id] = j;
        rep1(j, 1, m) {
            hsh[0][j] = (hsh[0][j - 1] * 131 % mod + s[j]) % mod;
            hsh[1][j] = (hsh[1][j - 1] * 131 % mod + t[j]) % mod;
        }
        // cout << query(0, L[id], R[id]) << ' ' << query(1, L[id], R[id]) << '\n';
        int ans = 0;
        rep1(j, 1, n) if(L[j] && R[j]) {
            int l = L[id] - L[j] + 1, r = R[id] + len[j] - R[j];
            if(l < 1 || r > m) continue;
            if(query(0, l, r) != val[0][j]) continue;
            if(query(1, l, r) != val[1][j]) continue;
            ++ans;
        }
        cout << ans << '\n';
    }
    
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int T = 1; //cin >> T;
    while(T--) solve();
    return 0;
}