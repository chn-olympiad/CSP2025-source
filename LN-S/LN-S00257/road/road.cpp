#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

struct Edge
{
    int u, v;
    ll w;

    bool operator<(Edge other)
    {
        return this->w < other.w;
    }
};

const int MAX_N = 10030, MAX_M = 3000001, C = 1024;
const ll INF = 0x7f7f7f7f7f7f7f7f;

Edge edges[MAX_M];
int n, m, k, u, v, ptr, s, cnt, rt[MAX_N][C];
ll w, ans = INF;

int get_rt(int cur);
ll mst();
void dfs(int cur, int bit, int c);

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        edges[++ptr] = { u, v, w };
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> w;
        edges[++ptr] = { n + k + i, n + i, w };
        for (int j = 1; j <= n; j++)
        {
            cin >> w;
            edges[++ptr] = { n + k + i, j, w };
        }
    }
    for (int i = 1; i <= n + 2 * k; i++)
    {
        for (int j = 0; j <= C - 1; j++)  { rt[i][j] = i; }
    }
    sort(edges + 1, edges + ptr + 1);
    if (k)
    {
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    else  { cout << mst() << endl; }

    return 0;
}

int get_rt(int cur)
{
    if (cur == rt[cur][s])  { return cur; }
    return rt[cur][s] = get_rt(rt[cur][s]);
}

ll mst()
{
    int c = 0;
    ll res = 0;

    for (int i = 1; i <= ptr; i++)
    {
        if (edges[i].u > n && ((1 << (edges[i].u - n - k - 1)) & s))  { continue; }

        int p = get_rt(edges[i].u), q = get_rt(edges[i].v);

        if (p == q)  { continue; }
        res += edges[i].w;
        if (res >= ans)  { return INF; }
        c++;
        if (c == (k - cnt) * 2 + n - 1)  { return res; }
        rt[p][s] = q;
    }

    return res;
}

void dfs(int cur, int bit, int c)
{
    if (cur == k)
    {
        s = bit;
        cnt = c;
        ans = min(ans, mst());
        return ;
    }
    dfs(cur + 1, bit | (1 << cur), c + 1);
    dfs(cur + 1, bit, c);
}
