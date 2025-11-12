#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int NR = 1e3 + 5;

struct node
{
    int v, w;
};

int n, m, k;
long long ans = 1e17;
vector<node> a[NR * 3];
int cnt[NR];

struct qnode
{
    int x, st, cnt;
};

bool operator < (const qnode& a, const qnode& b)
{
    return a.cnt > b.cnt;
}

bool vis[NR * 2];
void dfs(int x, int num, long long cnt)
{
    if (x <= n)
        num ++;
    if (num == n)
    {
        ans = min(ans, cnt);
        return;
    }

    for (auto it = a[x].begin();it != a[x].end();it ++)
    {
        if (!vis[it->v])
        {
            vis[it->v] = 1;
            dfs(it->v, num, cnt + it->w);
            vis[it->v] = 0;
        }
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    int u, v, w;
    for (int i = 1;i <= m;i ++)
    {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    for (int i = 1;i <= k;i ++)
    {
        cin >> u;
        for (int j = 1;j <= n;j ++)
        {
            cin >> w;
            if (j == i)
                u += w;
            a[i + NR].push_back({j, w});
            a[j].push_back({i + NR * 2, w});
        }
        a[i].push_back({i + NR, u});
        a[i + NR * 2].push_back({i, u});
    }

    memset(vis, sizeof(vis), 0);

    vis[1] = 1;
    dfs(1, 0, 0);

    cout << ans;
    return 0;
}
