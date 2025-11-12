#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define debug(x) cerr << #x << ' ' << x << '\n'
using LL = long long;
constexpr int MAXN = 5e6 + 5;
int n, q, U[MAXN], V[MAXN], LEN[MAXN];
bool bg;
namespace ACAM {
    int tot = 1, to[26][MAXN], fail[MAXN], dfncnt, L[MAXN], R[MAXN];
    vector<int> G[MAXN];
    inline int insert(const string &s) {
        int id = 1;
        for (char c : s) {
            int v = c - 'a';
            if (!to[v][id]) to[v][id] = ++tot;
            id = to[v][id];
        }
        return id;
    }
    inline void build() {
        queue<int> q; fail[1] = 1;
        for (int i = 0; i < 26; ++i) {
            if (to[i][1]) q.emplace(to[i][1]), fail[to[i][1]] = 1;
            else to[i][1] = 1;
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            G[fail[u]].emplace_back(u);
            for (int i = 0; i < 26; ++i) {
                int &v = to[i][u];
                if (v) fail[v] = to[i][fail[u]], q.emplace(v);
                else v = to[i][fail[u]];
            }
        }
    }
    void dfs(int u = 1) {
        L[u] = ++dfncnt;
        for (int v : G[u]) dfs(v);
        R[u] = dfncnt;
    }
}; using namespace ACAM;
struct node {
    int opt, x, y, z, val;
    inline bool operator < (const node &o) const { return x > o.x || (x == o.x && opt < o.opt); }
} p[MAXN << 1], tmp[MAXN << 1];
int m;
LL ans[MAXN];
namespace BIT {
    int c[MAXN], stk[MAXN], top;
    inline int lowbit(int x) { return x & -x; }
    inline void clear() {
        while (top) {
            for (int i = stk[top]; i <= tot; i += lowbit(i)) c[i] = 0;
            --top;
        }
    }
    inline void modify(int pos, int val) { stk[++top] = pos; for (int i = pos; i <= tot; i += lowbit(i)) c[i] += val; }
    inline int query(int pos) {
        int ret = 0;
        for (int i = pos; i; i -= lowbit(i)) ret += c[i];
        return ret;
    }
}; //namespace BIT
inline void msort(int l, int mid, int r) {
    int u = l, v = mid + 1, w = l;
    while (u <= mid && v <= r) {
        if (p[u].y < p[v].y) tmp[w++] = p[u++];
        else tmp[w++] = p[v++];
    }
    while (u <= mid) tmp[w++] = p[u++];
    while (v <= r) tmp[w++] = p[v++];
}
inline void divide(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    divide(l, mid), divide(mid + 1, r);
    bool f = false, g = false;
    for (int i = l; i <= mid; ++i) f |= (p[i].opt == 0);
    for (int i = mid + 1; i <= r; ++i) g |= (p[i].opt == 1);
    if (f && g) {
        int pos = l;
        for (int i = mid + 1; i <= r; ++i) {
            while (pos <= mid && p[pos].y <= p[i].y) {
                if (!p[pos].opt) BIT::modify(p[pos].z, p[pos].val);
                ++pos;
            }
            if (p[i].opt) ans[p[i].val] += BIT::query(p[i].z);
        }
        BIT::clear();
    }
    // merge(p + l, p + 1 + mid, p + 1 + mid, p + 1 + r, tmp + l, [&](node x, node y) { return x.y < y.y; });
    msort(l, mid, r);
    for (int i = l; i <= r; ++i) p[i] = tmp[i];
}
bool ed;
int main() {
    IOS;
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    // cerr << (&bg - &ed) / 1024.0 / 1024.0 << '\n';
    cin >> n >> q;
    string s1, s2;
    for (int i = 1; i <= n; ++i) {
        cin >> s1 >> s2;
        U[i] = insert(s1), V[i] = insert(s2), LEN[i] = s1.size();
    }
    build(), dfs();
    for (int i = 1; i <= n; ++i) {
        p[++m] = {0, LEN[i], L[U[i]], L[V[i]], 1};
        if (R[V[i]] < tot) p[++m] = {0, LEN[i], L[U[i]], R[V[i]] + 1, -1};
        if (R[U[i]] < tot) p[++m] = {0, LEN[i], R[U[i]] + 1, L[V[i]], -1};
        if (R[U[i]] < tot && R[V[i]] < tot) p[++m] = {0, LEN[i], R[U[i]] + 1, R[V[i]] + 1, 1};
        // cerr << LEN[i] << ' ' << L[U[i]] << ' ' << R[U[i]] << ' ' << L[V[i]] << ' ' << R[V[i]] << '\n';
    }
    for (int T = 1; T <= q; ++T) {
        cin >> s1 >> s2;
        if (s1.size() != s2.size()) {
            ans[T] = 0;
            continue;
        }
        int len = s1.size(), fst = 0, lst = len - 1;
        while (fst < len && s1[fst] == s2[fst]) ++fst;
        while (lst >= 0 && s1[lst] == s2[lst]) --lst;
        for (int u = 1, v = 1, i = 0; i < len; ++i) {
            u = to[s1[i] - 'a'][u], v = to[s2[i] - 'a'][v];
            // cerr << u << ' ' << v << '\n';
            if (i < lst) continue;
            if (u != 1 && v != 1) {
                // cerr << L[u] << ' ' << L[v] << ' ' << i - fst + 1 << '\n';
                p[++m] = {1, i - fst + 1, L[u], L[v], T};
            }
        }
    }
    sort(p + 1, p + 1 + m);
    // for (int i = 1; i <= m; ++i) cerr << p[i].opt << ' ' << p[i].x << ' ' << p[i].y << ' ' << p[i].z << ' ' << p[i].val << '\n';
    divide(1, m);
    // cerr << m << '\n';
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    return 0;
}