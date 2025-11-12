#include <bits/stdc++.h>
#define ll long long 
#define i2 __int128
using namespace std;

const int N = 5e5 + 10;
const int L = 5e6 + 10;
const int T = 1e7 + 10;
const int S = 131;
const ll P = (1ll << 61) - 1;
typedef pair <int, int> pii;
int n, q;
int cnt;
int le[N];
int ch[T][27], tot;
int tvl[N], tvr[N];
int pl[N], pr[N];
int lq[N];
int ql[N], qr[N];
int qrl[N], qrr[N];
int dfn[T], tim;
int sz[T];
int ctq;
int ans[N];
int ctc;
pii vl[N], ndc[T];
string s1[N], s2[N];
string t1[N], t2[N];
vector <int> v1[N], v2[N];
map <pii, int> mp;

struct query{
    int tp, x;
    int l, r, y, w, id;

    bool operator < (const query &k) const {
        if (x == k.x) return tp < k.tp;
        return x < k.x;
    }
}Q[N];
struct BIT{
    int t[T];

    int lb(int x) { return x & (-x); }
    void upd(int x, int k) {
        for (int i = x; i <= tot + 10; i += lb(i)) t[i] += k;
    }
    void mdf(int l, int r, int k) {
        upd(l, k), upd(r + 1, -k);
    }
    int qry(int x) {
        int res = 0;
        for (int i = x; i; i -= lb(i)) res += t[i];
        return res;
    }
}B;

void init() {
    for (int i = 1; i <= n; i++) {
        le[i] = s1[i].size();
        s1[i] = " " + s1[i], s2[i] = " " + s2[i];
        int l = 1;
        while (s1[i][l] == s2[i][l]) l++;
        int r = le[i];
        while (s1[i][r] == s2[i][r]) r--;
        tvl[i] = l, tvr[i] = r;
        ll ha1 = 0, ha2 = 0;
        for (int j = l; j <= r; j++) {
            ha1 = ((i2)ha1 * S % P + s1[i][j]) % P;
            ha2 = ((i2)ha2 * S % P + s2[i][j]) % P;
        }
        pii pi = {ha1, ha2};
        // cout << ha1 << ' ' << ha2 << '\n';
        if (!mp[pi]) mp[pi] = ++cnt;
        vl[i] = pi;
        v1[mp[pi]].push_back(i);
    }
}
void insert1(int i, int tp, string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
        if (!ch[u][x]) { ch[u][x] = ++tot, ndc[++ctc] = {u, x}; }
        u = ch[u][x];
    }
    if (!tp) pl[i] = u;
    else pr[i] = u;
}
void insert2(int i, int tp, string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
        if (!ch[u][x]) { ch[u][x] = ++tot, ndc[++ctc] = {u, x}; };
        u = ch[u][x];
    }
    if (!tp) qrl[i] = u;
    else qrr[i] = u;
}
void dfs(int u) {
    dfn[u] = ++tim, sz[u] = 1;
    for (int i = 0; i < 26; i++) {
        if (!ch[u][i]) continue;
        dfs(ch[u][i]);
        sz[u] += sz[ch[u][i]];
    }
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
    }
    init();
    for (int i = 1; i <= q; i++) {
        cin >> t1[i] >> t2[i];
        if (t1[i].size() != t2[i].size()) continue;
        int len = t1[i].size();
        t1[i] = " " + t1[i], t2[i] = " " + t2[i];
        lq[i] = len;
        int l = 1;
        while (t1[i][l] == t2[i][l]) l++;
        int r = len;
        while (t1[i][r] == t2[i][r]) r--;
        ql[i] = l, qr[i] = r;
        ll ha1 = 0, ha2 = 0;
        for (int j = l; j <= r; j++) {
            ha1 = ((i2)ha1 * S % P + t1[i][j]) % P;
            ha2 = ((i2)ha2 * S % P + t2[i][j]) % P;
        }
        // cout << ha1 << ' ' << ha2 << '\n';
        pii pi = {ha1, ha2};
        if (!mp[pi]) continue;
        v2[mp[pi]].push_back(i);
    }
    for (int i = 1; i <= cnt; i++) {
        if (!v1[i].size() || !v2[i].size()) continue;
        string tmp;
        for (int j : v1[i]) {
            // cout << j << ' ';
            tmp.clear(), tmp.shrink_to_fit();
            for (int k = tvl[j] - 1; k; k--) {
                tmp.push_back(s1[j][k]);
            }
            insert1(j, 0, tmp);
        }
        for (int j : v1[i]) {
            tmp.clear(), tmp.shrink_to_fit();
            for (int k = tvr[j] + 1; k <= le[j]; k++) {
                tmp.push_back(s1[j][k]);
            }
            insert1(j, 1, tmp);
        }
        // cout << '\n';
        for (int j : v2[i]) {
            // cout << j << ' ';
            tmp.clear(), tmp.shrink_to_fit();
            for (int k = ql[j] - 1; k; k--) {
                tmp.push_back(t1[j][k]);
            }
            insert2(j, 0, tmp);
        }
        for (int j : v2[i]) {
            tmp.clear(), tmp.shrink_to_fit();
            for (int k = qr[j] + 1; k <= lq[j]; k++) {
                tmp.push_back(t1[j][k]);
            }
            insert2(j, 1, tmp);
        }
        // for (int i = 0; i <= tot; i++) {
        //     for (int j = 0; j < 26; j++) {
        //         if (ch[i][j]) cout << i << ' ' << ch[i][j] << ' ' << (char)(j + 'a') << '\n';
        //     }
        // }
        dfs(0);
        for (int j : v1[i]) {
            // cout << j << ' ' << dfn[pl[j]] << ' ' << dfn[pr[j]] << '\n';
            Q[++ctq] = {0, dfn[pl[j]], dfn[pr[j]], dfn[pr[j]] + sz[pr[j]] - 1, 0, 1, 0};
            Q[++ctq] = {0, dfn[pl[j]] + sz[pl[j]], dfn[pr[j]], dfn[pr[j]] + sz[pr[j]] - 1, 0, -1, 0};
        }
        for (int j : v2[i]) {
            // cout << j << ' ' << qrl[j] << ' ' << qrr[j] << '\n';
            Q[++ctq] = {1, dfn[qrl[j]], 0, 0, dfn[qrr[j]], 0, j};
        }
        sort(Q + 1, Q + ctq + 1);
        for (int i = 1; i <= ctq; i++) {
            if (!Q[i].tp) B.mdf(Q[i].l, Q[i].r, Q[i].w);
            else ans[Q[i].id] += B.qry(Q[i].y);
        }
        for (int i = 1; i <= ctq; i++) {
            if (!Q[i].tp) B.mdf(Q[i].l, Q[i].r, -Q[i].w);
        }
        for (int i = 0; i <= tot; i++) {
            dfn[i] = sz[i] = 0;
        }
        for (int i = 1; i <= ctc; i++) {
            ch[ndc[i].first][ndc[i].second] = 0;
        }
        ctq = tot = tim = ctc = 0;
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}