#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define il inline
#define se second
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
namespace Dinic
{
    struct Edge
    {
        int v, f, c, nxt;
    } e[N << 1];
    int h[N], ecnt = 1, cur[N];
    void add(int u, int v, int f, int c)
    {
        e[++ecnt] = {v, f, c, h[u]}, h[u] = ecnt;
        e[++ecnt] = {u, 0, -c, h[v]}, h[v] = ecnt;
    }
    int ans, s, t, dis[N], inq[N];
    bool spfa()
    {
        for (int i = s; i <= t; i++)
            dis[i] = INF, cur[i] = h[i];
        queue<int> q;
        q.push(s), dis[s] = 0, inq[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop(), inq[u] = 0;
            for (int i = h[u]; ~i; i = e[i].nxt)
            {
                int v = e[i].v;
                if (e[i].f > 0 && dis[v] > dis[u] + e[i].c)
                {
                    dis[v] = dis[u] + e[i].c;
                    if (!inq[v])
                        inq[v] = 1, q.push(v);
                }
            }
        }
        return dis[t] != INF;
    }
    int dfs(int u, int fl, int fe = -1)
    {
        if (u == t)
            return fl;
        int res = 0;
        for (int &i = cur[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (i != fe && e[i].f > 0 && dis[v] == dis[u] + e[i].c)
            {
                int x = dfs(v, min(fl, e[i].f), i ^ 1);
                res += x, fl -= x;
                e[i].f -= x, e[i ^ 1].f += x;
                ans += x * e[i].c;
                if (!fl)
                    break;
            }
        }
        return res;
    }
    int dinic()
    {
        int res = 0;
        while (spfa())
            res += dfs(s, INF);
        return res;
    }
    void clr() { memset(h, -1, sizeof h), ecnt = 1, ans = 0; }
}
using namespace Dinic;
int n, a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int chk = 1;
        cin >> n, clr(), s = 0, t = n + 4;
        for (int i = 1; i <= n; i++)
        {
            add(s, i, 1, 0);
            for (int j = 1, x; j <= 3; j++)
            {
                cin >> x, add(i, n + j, 1, -x);
                if (j == 1)
                    a[i] = x;
                else
                    chk &= (x == 0);
            }
        }
        if (chk)
        {
            sort(a + 1, a + n + 1, greater<int>());
            int ans = 0;
            for (int i = 1; i <= n / 2; i++)
                ans += a[i];
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= 3; i++)
            add(n + i, t, n / 2, 0);
        dinic();
        cout << -ans << endl;
    }
    return 0;
}