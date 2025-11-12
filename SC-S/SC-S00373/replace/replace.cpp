#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 2e5 + 9, M = 5e6 + 9, L = 5e6 + 1;

char s[M], t[M];

LL ans[N];

int n, m;

struct ACAM
{
    int fail[M], cnt, dep[M], dfn[M], en[M], idx, tr[M][29];
    bool tg[M];
    int fa[29][N], lst[M], tot, id[M], fid[N];
    vector < int > G[M];
    int ins(char* s)
    {
        int u = 0;
        for (int i = 0;s[i];++ i)
        {
            int c = s[i] - 'a';
            if (!tr[u][c])
                tr[u][c] = ++ cnt;
            dep[tr[u][c]] = dep[u] + 1;
            u = tr[u][c];
        }
        return u;
    }
    void dfs2(int u)
    {
        if (tg[u])
        {
            id[u] = ++ tot, fid[tot] = u;
            fa[0][tot] = lst[u];
            lst[u] = tot;
            for (int i = 1;i <= 20;++ i)
                fa[i][tot] = fa[i - 1][fa[i - 1][tot]];
        }
        dfn[u] = ++ idx;
        for (int v : G[u])
            lst[v] = lst[u], dfs2(v);
        en[u] = idx;
    }
    int find(int u, int x)
    {
        u = lst[u];
        for (int i = 20;i >= 0;-- i)
            if (dep[fid[fa[i][u]]] >= x)
                u = fa[i][u];
        while (dep[fid[u]] >= x)
            u = fa[0][u];
        return fid[u];
    }
    void bd()
    {
        queue < int > q;
        for (int i = 0;i < 26;++ i)
            if (tr[0][i])
                q.push(tr[0][i]);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0;i < 26;++ i)
                if (tr[u][i])
                    fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
                else
                    tr[u][i] = tr[fail[u]][i];
        }
        for (int i = 1;i <= cnt;++ i)
            G[fail[i]].push_back(i);
        dfs2(0);
    }
}A1, A2;

int p1[N], p2[N];

vector < array < int, 3 > > cg[M], qr[M];

struct bit
{
    int b[M];
    void add(int i, int x)
    {
        while (i <= L)
            b[i] += x, i += i & -i;
    }
    int ask(int i)
    {
        int res = 0;
        while (i)
            res += b[i], i -= i & -i;
        return res;
    }
    void add(int l, int r, int x)
    {
        add(l, x), add(r + 1, -x);
    }
    int ask(int l, int r)
    {
        return ask(r) - ask(l - 1);
    }
}b;

int Stt[39];

void write(LL x)
{
    if (!x)
        putchar('0');
    int top = 0;
    while (x)
        Stt[++ top] = x % 10, x /= 10;
    while (top)
        putchar(Stt[top --] + '0');
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;++ i)
    {
        scanf("%s%s", s, t);
        p1[i] = A1.ins(s), p2[i] = A2.ins(t), A1.tg[p1[i]] = 1, A2.tg[p2[i]] = 1;
    }
    A1.bd(), A2.bd();
    for (int i = 1;i <= n;++ i)
    {
        int l1 = A1.dfn[p1[i]], r1 = A1.en[p1[i]];
        int l2 = A2.dfn[p2[i]], r2 = A2.en[p2[i]];
        cg[l1].push_back({l2, r2, 1});
        cg[r1 + 1].push_back({l2, r2, -1});
    }
    for (int i = 1;i <= m;++ i)
    {
        scanf("%s%s", s, t);
        int len = strlen(s);
        int lcp = 0;
        while (t[lcp] == s[lcp])
            ++ lcp;
        int lcs = len - 1;
        while (s[lcs] == t[lcs])
            -- lcs;
        int id = i;
        for (int i = 0, u1 = 0, u2 = 0;i < len;++ i)
        {
            u1 = A1.tr[u1][s[i] - 'a'];
            u2 = A2.tr[u2][t[i] - 'a'];
            if (i >= lcs)
            {
                int x = A1.find(u1, i + 1 - lcp);
                qr[A1.dfn[u1]].push_back({A2.dfn[u2], id, 1});
                qr[A1.dfn[x]].push_back({A2.dfn[u2], id, -1});
            }
        }
    }
    for (int i = 1;i <= L;++ i)
    {
        for (auto it : cg[i])
        {
            int l = it[0], r = it[1], x = it[2];
            b.add(l, r, x);
        }
        for (auto it : qr[i])
        {
            int y = it[0], id = it[1], x = it[2];
            ans[id] += x * b.ask(y);
        }
    }
    for (int i = 1;i <= m;++ i)
        write(ans[i]), putchar('\n');
    fclose(stdin);
    fclose(stdout);

    return 0;
}