#include <bits/stdc++.h>
using namespace std;

struct Side
{
    int id, num;
    bool operator < (const Side b) const
    {
        return num > b.num;
    }
};

priority_queue <Side> q, EMP;
vector <int> a[10020], w[10020];
int c[15], n, m, k, last;
long long ans = 0;
bool vis[1100010];

void solve(int x)
{
    vis[x] = true, last--;
    for (int i = 0; i < a[x].size(); i++)
    {
        q.push(Side{a[x][i], w[x][i]});
    }
    while (last > 0)
    {
        x = q.top().id;
        if (vis[x])
        {
            q.pop();
            continue;
        }
        vis[x] = true;
        last--;
        ans += q.top().num;
        q.pop();
        for (int i = 0; i < a[x].size(); i++)
        {
            if (!vis[a[x][i]])
            {
                q.push(Side{a[x][i], w[x][i]});
            }
        }
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(y);
        w[x].push_back(z);
        a[y].push_back(x);
        w[y].push_back(z);
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
        {
            int z;
            scanf("%d", &z);
            a[i + n].push_back(j);
            w[i + n].push_back(z);
            a[j].push_back(i + n);
            w[j].push_back(z);
        }
    }
    last = n + k;
    solve(1);
    cout << ans << endl;
    return 0;
}


