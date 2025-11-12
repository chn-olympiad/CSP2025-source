#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int n, m, k, cnt;
int fa[N];
ll c[N], x;
bool vis[N];
struct node
{
    int u, v;
    ll w, c;
} e[N];

bool cmp(node A, node B)
{
    return A.w+A.c < B.w+B.c;
}

int findRt(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = findRt(fa[x]);
}

void merge(int x, int y)
{
    int fx = findRt(x);
    int fy = findRt(y);
    if (fx != fy) fa[fx] = fy;
}

ll K()
{
    for (int i = 1; i <= n+k; i++) fa[i] = i;

    ll sum = 0;
    ll num = 1;
    ll nu = 0;

    for (int i = 1; i <= cnt; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        ll w = e[i].w;

        if (findRt(u) == findRt(v)) continue;

        merge(u, v);

        if (u > n)
        {
            sum += c[u];
            if (vis[u]) nu++;
            vis[u] = 0;
            c[u] = 0;
        }
        if (v > n)
        {
            sum += c[v];
            if (vis[v]) nu++;
            vis[v] = 0;
            c[v] = 0;
        }

        num++;
        sum += w;

        // cout << u << " " << v << " " << sum << " " << num << " " << nu << endl;
        if (num-nu == n) return sum;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].c = 0;
    }

    cnt = m;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i+n];

        vis[i+n] = 1;

        int u = i+n;
        for (int v = 1; v <= n; v++)
        {
            cin >> x;

            cnt++;
            e[cnt].u = u;
            e[cnt].v = v;
            e[cnt].w = x;
            e[cnt].c = c[i+n];
        }
    }

    sort(e+1, e+cnt+1, cmp);

    // for (int i = 1; i <= cnt; i++)
    // {
    //     cout << e[i].vi << " ";
    //     cout << e[i].u << " ";
    //     cout << e[i].v << " ";
    //     cout << e[i].w << endl;
    // }

    ll ans = K();

    cout << ans;
    return 0;
}