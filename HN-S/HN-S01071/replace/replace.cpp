#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000005, maxm = 200005;
int n, m;
int son[maxn][26], fail[maxn];
int dep[maxn], p[maxn], cnt;
int q[maxn], st, ed;
struct qry {int d, id;};
vector<qry> d[maxn];
struct node {int y, nxt;} a[maxn];
int hd[maxn], tot;
int ans[maxm];
struct BIT {
    int sum[maxn];
    int lowbit(int x) {return x & -x;}
    void update(int x, int v) {for (; x <= 5e6; x += lowbit(x)) sum[x] += v;}
    int query(int x) {int res = 0; for (; x; x -= lowbit(x)) res += sum[x]; return res;}
} T;
string merge(string a, string b) {
    string s = "";
    for (int i = 0; i < a.size(); i++) {s += a[i]; s += b[i];}
    return s;
}
void run(string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (!son[u][c]) son[u][c] = ++cnt;
        dep[son[u][c]] = dep[u] + 1; u = son[u][c];
    }
    p[u]++;
}
void build() {
    st = 1, ed = 0;
    for (int i = 0; i < 26; i++)
        if (son[0][i]) q[++ed] = son[0][i];
    while (st <= ed) {
        int u = q[st++];
        for (int i = 0; i < 26; i++)
            if (son[u][i]) fail[son[u][i]] = son[fail[u]][i], q[++ed] = son[u][i];
            else son[u][i] = son[fail[u]][i];
    }
}
void add(string s, int id, int l, int r) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a'; u = son[u][c];
        if (i % 2 && i >= r) d[u].push_back((qry){i - l + 1, id});
    }
}
void dfs(int x) {
    int tmp = p[x]; p[x] += p[fail[x]];
    if (tmp) T.update(dep[x], tmp);
    for (auto k : d[x]) ans[k.id] += p[x] - T.query(k.d - 1);
    for (int i = hd[x]; i; i = a[i].nxt) dfs(a[i].y);
    if (p[x]) T.update(dep[x], -tmp);
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s, t; cin >> s >> t;
        run(merge(s, t));
    }
    cerr << clock() * 1. / CLOCKS_PER_SEC << '\n';
    build();
    cerr << clock() * 1. / CLOCKS_PER_SEC << '\n';
    for (int i = 1; i <= m; i++) {
        string s, t; cin >> s >> t;
        int p = 0, q = s.size();
        for (int j = 0; j < s.size(); j++)
            if (s[j] != t[j]) {p = j * 2; break;}
        for (int j = s.size() - 1; j >= 0; j--)
            if (s[j] != t[j]) {q = j * 2 + 1; break;}
        add(merge(s, t), i, p, q);
    }
    cerr << clock() * 1. / CLOCKS_PER_SEC << '\n';
    for (int i = 1; i <= cnt; i++) {
        a[++tot] = (node){i, hd[fail[i]]}; hd[fail[i]] = tot;
    }
    dfs(0);
    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    cerr << clock() * 1. / CLOCKS_PER_SEC << '\n';
    return 0;
}