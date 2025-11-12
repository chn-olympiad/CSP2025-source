#include <bits/stdc++.h>

using namespace std;

struct lll
{
    int u,v,w;
};

int n,m,k,cnt;
lll G[50000010];
int f[10010];
long long ans;

int find(int x)
{
    if(x == f[x]) return x;
    return f[x] = find(f[x]);
}

int cmp(lll a, lll b)
{
    return a.w < b.w;
}

void Kruskal()
{
    int linenum = 0;
    for(int i = 1; i <= cnt; i++)
    {
        int u = find(G[i].u), v = find(G[i].v);
        if(u == v) continue;
        linenum += 1;
        ans += G[i].w;
        if(linenum == n - 1) break;
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        G[i] = {u,v,w};
    }

    cnt = m;
    for(int i = 1; i <= k; i++)
    {
        int p[10010];
        int c;
        cin >> c;
        for(int j = 1; j <= n; j++)
        {
            cin >> p[j];
            for(int l = 1; l <= j - 1; l++)
            {
                G[++cnt] = {j, l, p[j] + p[l] + c};
            }
        }
    }

    sort(G + 1, G + cnt + 1, cmp);
    Kruskal();

    cout << ans;

    return 0;
}
