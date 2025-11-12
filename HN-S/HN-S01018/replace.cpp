#include <bits/stdc++.h>
#define N 200005
#define L 2500005
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmin(T &x, T y) {return (y < x) && (x = y, true);}
template <typename T> inline bool ckmax(T &x, T y) {return (x < y) && (x = y, true);}
int n, m, Lg, q[L], ed[N][2], rev[L], per[N], fa[L][22]; char s[L], t[L];
struct
{
    struct {int to, next;} e[L];
    int ch[L][26], fail[L], len[L], num, tot, head[L], tin[L], tout[L], tim;
    inline void add(int u, int v) {e[++ tot] = {v, head[u]}, head[u] = tot;}
    inline int insert()
    {
        int rt = 0, l = strlen(s + 1);
        for (int i = 1; i <= l; ++ i)
        {
            if (!ch[rt][s[i] - 'a']) ch[rt][s[i] - 'a'] = ++ num, len[num] = len[rt] + 1;
            rt = ch[rt][s[i] - 'a'];
        }
        return rt;
    }
    inline void get_fail()
    {
        int h = 1, t = 0;
        for (int i = 0; i < 26; ++ i)
            if (ch[0][i]) q[++ t] = ch[0][i];
        for (int u, i, v; h <= t; ++ h)
            for (u = q[h], add(fail[u], u), i = 0; i < 26; ++ i)
                if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q[++ t] = ch[u][i];
                else ch[u][i] = ch[fail[u]][i];
    }
    inline void dfs(int u)
    {
        tin[u] = ++ tim;
        for (int i = head[u], v; i; i = e[i].next) dfs(v = e[i].to);
        tout[u] = tim;
    }
} S[2];
int rt[L];
struct
{
#define ls(rt) tr[rt].ls
#define rs(rt) tr[rt].rs
#define k(rt) tr[rt].k
    int num = 0;
    struct {int ls, rs, k;} tr[N * 50];
    inline void update(int &u, int v, int l, int r, int p, int t)
    {
        // if (l == 1 && r == 12) cerr << p << ' ' << t << '\n';
        u = ++ num, tr[u] = tr[v], k(u) += t; if (l == r) return ;
        int mid = l + r >> 1;
        if (p <= mid) update(ls(u), ls(v), l, mid, p, t);
        else update(rs(u), rs(v), mid + 1, r, p, t);
    }
    // inline int query(int rt, int l, int r, int p)
    // {
    //     if (!rt) return 0;
    //     if (p >= r) return k(rt);
    //     int mid = l + r >> 1;
    //     if (p <= mid) return query(ls(rt), l, mid, p);
    //     else return k(ls(rt)) + query(rs(rt), mid + 1, r, p);
    // }
    inline int query(int rt, int l, int r, int p)
    {
        int res = 0, mid;
        while (true)
        {
            if (p >= r) return res + k(rt);
            if (!rt) return res;
            mid = l + r >> 1;
            if (p <= mid) r = mid, rt = ls(rt);
            else res += k(ls(rt)), l = mid + 1, rt = rs(rt);
        }
        return res;
    }
} tr;
inline int jump(int u, int k)
{
    if (S[0].len[u] < k) return u;
    for (int i = Lg; ~i; -- i)
        if (S[0].len[fa[u][i]] >= k) u = fa[u][i];
    return fa[u][0];
}
inline void solve()
{
    cin >> (s + 1) >> (t + 1);
    int len = strlen(s + 1), l = 0, r = 0;
    for (int i = 1; i <= len; ++ i)
        if (s[i] != t[i])
        {
            if (!l) l = i;
            r = i;
        }
    int u = 0, v = 0, ans = 0;
    for (int i = 1, x; i <= len; ++ i)
    {
        u = S[0].ch[u][s[i] - 'a'], v = S[1].ch[v][t[i] - 'a'];
        if (i >= r)
        {
            ans += tr.query(rt[u], 1, S[1].tim, S[1].tin[v]);
            ans -= tr.query(rt[jump(u, i - l + 1)], 1, S[1].tim, S[1].tin[v]);
        }
    }
    cout << ans << '\n';
}
signed main()
{
    file(replace);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> (s + 1), ed[i][0] = S[0].insert(), cin >> (s + 1), ed[i][1] = S[1].insert();
    S[0].get_fail(), S[1].get_fail(), S[0].dfs(0), S[1].dfs(0);
    iota(per + 1, per + n + 1, 1), sort(per + 1, per + n + 1, [](int x, int y) {return S[0].tin[ed[x][0]] < S[0].tin[ed[y][0]];});
    for (int i = 0; i <= S[0].num; ++ i) rev[S[0].tin[i]] = i, fa[i][0] = S[0].fail[i];
    for (int j = 1, i; 1 << j < S[0].num; ++ j)
        for (i = 1; i <= S[0].num; ++ i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    Lg = __lg(S[0].num);
    for (int i = 1, u, o, v, t = 1; i <= S[0].tim; ++ i)
    {
        u = rev[i];
        while (t <= n && ed[per[t]][0] == u)
        {
            tr.update(rt[u], rt[u], 1, S[1].tim, S[1].tin[ed[per[t]][1]], 1);
            if (S[1].tout[ed[per[t]][1]] < S[1].tim) tr.update(rt[u], rt[u], 1, S[1].tim, S[1].tout[ed[per[t]][1]] + 1, -1);
            ++ t;
        }
        for (o = S[0].head[u]; o; o = S[0].e[o].next) v = S[0].e[o].to, rt[v] = rt[u];
    }
    for (; m --;) solve();
    return 0;
}