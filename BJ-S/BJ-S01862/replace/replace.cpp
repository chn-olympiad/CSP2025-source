#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l, i##KON = r; i <= i##KON; ++i)
#define per(i, l, r) for(int i = l, i##KON = r; i >= i##KON; --i)
using namespace std;
using ll = long long;
constexpr int N{3000005};
int n, q, a1[N], a2[N], ans[N];
struct node
{
    int x, id, c;
    node(int X = 0, int ID = 0, int C = 0) : x{X}, id{ID}, c{C}{}
};
vector<int> id[N];
vector<node> qs[N];
struct AC
{
    int t[N][26], f[22][N], tt, q[N], dep[N], dfn[N], ed[N], vc;
    vector<int> e[N];
    int ins(const string& s, int v, bool f = 1)
    {
        int u = 0;
        for(char c : s)
        {
            if(!t[u][c - 'a'])
                dep[t[u][c - 'a'] = ++tt] = dep[u] + 1;
            u = t[u][c - 'a'];
        }
        if(f)
            id[u].emplace_back(v);
        return u;
    }
    void dfs(int u)
    {
        dfn[u] = ++vc;
        for(int v : e[u])
            dfs(v);
        ed[u] = vc;
    }
    void build()
    {
        int l = 1, r = 1;
        rep(i, 0, 25) if(t[0][i])
            q[++r] = t[0][i];
        while(l < r)
        {
            int u = q[++l];
            rep(i, 0, 25)
            {
                if(t[u][i])
                    f[0][q[++r] = t[u][i]] = t[f[0][u]][i];
                else
                    t[u][i] = t[f[0][u]][i];
            }
        }
        rep(i, 1, 21) rep(j, 1, tt)
            f[i][j] = f[i - 1][f[i - 1][j]];
        rep(i, 1, tt)
            e[f[0][i]].emplace_back(i);
        dfs(0);
    }
    int qry(int u, int k) // first \in anc(u), dep < k
    {
        per(i, 21, 0) if(dep[f[i][u]] >= k)
            u = f[i][u];
        return f[0][u];
    }
} ac1, ac2;
int c[N];
void add(int x, int v)
{
    for(; x <= ac2.vc; x += x & -x)
        c[x] += v;
}
int sum(int x)
{
    int r = 0;
    for(; x; x &= x - 1)
        r += c[x];
    return r;
}
void efs(int u)
{
    for(int x : id[u])
    {
        int l = ac2.dfn[x], r = ac2.ed[x];
        add(l, 1);
        add(r + 1, -1);
    }
    for(node Q : qs[u])
    {
        int x = Q.x, id = Q.id, c = Q.c;
        ans[id] += sum(ac2.dfn[x]) * c;
    }
    for(int v : ac1.e[u])
        efs(v);
    for(int x : id[u])
    {
        int l = ac2.dfn[x], r = ac2.ed[x];
        add(l, -1);
        add(r + 1, 1);
    }
}
void solve()
{
    efs(0);
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep(i, 1, n)
    {
        string s1, s2;
        cin >> s1 >> s2;
        a2[i] = ac2.ins(s2, i, 0);
        a1[i] = ac1.ins(s1, a2[i]);
    }
    ac1.build();
    ac2.build();
    rep(Q, 1, q)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int m = t1.size(), l = 1, r = m, u1 = 0, u2 = 0; // cs qm wh hb / cs hb wh qm di yi ge bu pi pz wz vi
        t1 = ' ' + t1, t2 = ' ' + t2;
        for(; t1[l] == t2[l]; ++l);
        for(; t1[r] == t2[r]; --r);
        rep(i, 1, m)
        {
            u1 = ac1.t[u1][t1[i] - 'a'];
            u2 = ac2.t[u2][t2[i] - 'a'];
            if(i >= r && min(ac1.dep[u1], ac2.dep[u2]) >= i - l + 1)
            {
                int v1 = ac1.qry(u1, i - l + 1), v2 = ac2.qry(u2, i - l + 1);
                qs[v1].emplace_back(v2, Q, -1);
                qs[u1].emplace_back(u2, Q, 1);
            }
        }
    }
    solve();
    rep(i, 1, q)
        cout << ans[i] << '\n';
    return 0;
}
//freopen
