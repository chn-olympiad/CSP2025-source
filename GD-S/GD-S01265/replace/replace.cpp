#include <bits/stdc++.h>
#define int long long
using namespace std;
#define test cerr << "test\n"

bool b1;
const int N = 5e6 + 5;
int n, q; string x[N], y[N];
bool chk(string &s) {
    int ca = 0, cb = 0;
    for (char c : s) ca += c == 'a', cb += c == 'b';
    return ca == s.size() - 1 && cb == 1;
}
namespace Sol1 {
    const int bas = 13221321, mod = 1e9 + 9; // bas yaogai!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int pw[N], va[N], vb[N], ha[N], hb[N];
    void init(string s, int hs[]) {
        int n = s.size(); s =  " " + s;
        for (int i = 1; i <= n; i++) hs[i] = (hs[i - 1] * bas + (s[i] - 'a' + 1)) % mod;
    } int qry(int l, int r, int hs[]) { return (hs[r] - hs[l - 1] * pw[r - l + 1] % mod + mod) % mod; }
    int solve() {
        for (int i = (pw[0] = 1); i < N; i++) pw[i] = (pw[i - 1] * bas) % mod;
        for (int o = 1; o <= n; o++) {
            int n = x[o].size() - 1;
            for (int i = 1; i <= n; i++) va[o] = (va[o] * bas + (x[o][i] - 'a' + 1)) % mod;
            for (int i = 1; i <= n; i++) vb[o] = (vb[o] * bas + (y[o][i] - 'a' + 1)) % mod;
        } 
        for (string s, t; q--; ) {
            cin >> s >> t; if (s.size() != t.size()) { cout << "0\n"; continue; }
            int n = s.size();
            init(s, ha); init(t, hb); int ans = 0;
            for (int l = 1; l <= n; l++) if (qry(1, l - 1, ha) == qry(1, l - 1, hb)) {
                for (int o = 1; o <= ::n; o++) {
                    int r = l + ::x[o].size() - 1 - 1; if (r > n) continue;
                    if (qry(l, r, ha) == va[o] && qry(l, r, hb) == vb[o] && qry(r + 1, n, ha) == qry(r + 1, n, hb)) ans++;
                }
            } cout << ans << '\n';
        }
        return 0;
    }
}
namespace Sol2 {
    int ans[N];
    vector <array <int, 4>> v[N]; // x, y, type, id
    int c[N]; int qwq(int x) { return x & (-x); }
    void mdf(int x, int k) { for (x++; x <= n; x += qwq(x)) c[x] += k; }
    int qry(int x) { int a = 0; for (x++; x; x -= qwq(x)) a += c[x]; return a; }
    void calc(int z) {
        sort(v[z].begin(), v[z].end());
        for (auto [x, y, t, o] : v[z]) {
            if (t == 1) ans[o] = qry(y);
            else mdf(y, 1);
        } for (auto [x, y, t, o] : v[z]) if (!t) mdf(y, -1);
    }
    int solve() {
        for (int o = 1; o <= n; o++) {
            int p1 = 0; int n = x[o].size() - 1;
            for (p1 = 1; p1 <= n; p1++) if (x[o][p1] == 'b') break; 
            int p2 = 0;
            for (p2 = 1; p2 <= n; p2++) if (y[o][p2] == 'b') break; 
            v[::n + p2 - p1].push_back({p1 - 1, n - p2, 0, 0});
        }
        for (int i = 1; i <= q; i++) {
            string x, y; cin >> x >> y; int n = x.size();
            x = " " + x, y = " " + y;
            if (x.size() != y.size()) { ans[i] = -1; continue; }
            int p1 = 0;
            for (p1 = 1; p1 <= n; p1++) if (x[p1] == 'b') break; 
            int p2 = 0;
            for (p2 = 1; p2 <= n; p2++) if (y[p2] == 'b') break; 
            v[::n + p2 - p1].push_back({p1 - 1, n - p2, 1, i});
        } 
        for (int i = 1; i <= 2 * n; i++) calc(i);
        for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
        return 0;
    }
}
bool b2;

signed main() {
    freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cerr << (&b1 - &b2) / 1024. / 1024 << '\n';
    cin >> n >> q; bool flg = true;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        flg &= chk(x[i]) & chk(y[i]);
        x[i] = " " + x[i], y[i] = " " + y[i];
    } if (flg) return Sol2::solve();
    return Sol1::solve();
    return 0;
}
