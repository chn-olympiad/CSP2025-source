#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 100;
int n, m, k;
vector<pair<int, int> > g[N], e[N];
int c[15], a[15][N], tot;
long long ans = 0, dis[N];
bool is[N];
void MinTree()//
{
    for(int i = 1;i <= n + k;i++)
        dis[i] = 1e18, is[i] = false;
    dis[1] = 0;
    for(int i = 1;i <= tot;i++)
    {
        long long min1 = 1e18;
        int minid = -1;
        for(int u = 1;u <= n + k;u++)
            if(dis[u] <= min1 && is[u] == false)
                min1 = dis[u], minid = u;
        ans += dis[minid];
        //cout << "minid: " << minid << "  dis: " << dis[minid] << '\n';
        is[minid] = true;
        for(auto edge : g[minid])
        {
            int u = edge.first, w = edge.second;
            dis[u] = min(dis[u], (long long)w);
        }
        for(auto edge : e[minid])
        {
            int u = edge.first, w = edge.second;
            dis[u] = min(dis[u], (long long)w);
        }
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        for(int j = 1;j <= n;j++)
            cin >> a[i][j];
    }
    long long min1 = 1e18;
    for(int i = 0;i < (1 << k);i++)
    {
        ans = 0, tot = n;
        memset(e, 0, sizeof(e));
        // if(i == 1)
        //     cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n";
        for(int j = 1;j <= k;j++)
        {
            if((i & (1 << (j - 1) ) ) != 0 )
            {
                tot++;
                ans += c[j];
                for(int u = 1;u <= n;u++)
                    e[u].push_back(make_pair(j + n, a[j][u])), e[j + n].push_back(make_pair(u, a[j][u]));
            }
        }
        // for(int j = 1;j <= n + k;j++)
        //     cout << "j： " << j << "  size: " << e[j].size() << '\n';
        // cout << "tot: " << tot << '\n';
        // cout << "n + k: " << n + k << '\n';
        MinTree();
        // cout << "i: " << i << " " << "ans: " << ans << '\n';
        min1 = min(min1, ans);
        // if(i == 1)
        //     cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n";
    }
    cout << min1 << '\n';
    return 0;
}