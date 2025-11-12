#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace langfengya
{
    void Main();
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    langfengya::Main();
    return 0;
}

namespace langfengya
{
    int n, m, k;
    const int M = 1e7 + 10;
    const int N = 1e4 + 10;
    vector <pair<int, int> >e[N];
    int c[N];
    struct bian
    {
        int u, v, w;
        void read()
        {
            cin >> u >> v >> w;
        }
    }b[M], b2[1000010];
    int ans1 = 0;
    int a[20][N];
    int cur = 0;
    bool cmp(bian fir, bian sec)
    {
        return fir.w < sec.w;
    }
    void read()
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i++)
        {
            b2[i].read();
        }

        for (int i = 1; i <= k; i++)
        {
            cin >> c[i];
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        
    }
    int fa[N];
    int find(int x)
    {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            return 1;
        }
        return 0;
    }
    // pair<int, int> dfs(int u, int fa, int x)
    // {
    //     int minx = 1e18, id = 0;;
    //     for (int i = 0; i < e[u].size(); i++)
    //     {
    //         int v = e[u][i].first;
    //         if (v == fa) continue;
    //         pair<int, int>t = dfs(v, u, x);
    //         if (t.second < minx)
    //         {
    //             id = t.first;
    //         }
    //         minx = min(minx, dfs(v, u, x).second);
    //     }
    //     if (a[x][u] < minx)
    //     {
    //         id = x;
    //     }
    //     return {id, min(minx, a[x][u])};
    // }
    //int useful[N];
    void solve()
    {
        // for (int i = 1; i <= n; i++) fa[i] = i;
        // int cur = 0;
        // for (int i = 1; i <= m; i++)
        // {
        //     if (merge(b[i].u, b[i].v))
        //     {
        //         cur++;
        //         useful[cur] = i;
        //     }
        //     if (cur == n - 1) break;
        // }


        // for (int i = 1; i <= k; i++)
        // {
        //     for (int j = 0; j < e[k].size(); j++)
        //     {
        //         int v = e[k][j].first;
        //         count[i][v] = dfs(v, i, i);
        //     }
        // }
        

        int the_ans = 1e18;
        for (int i = 0; i < (1 << k); i++)
        {
            for (int i = 1; i <= n; i++) fa[i] = i;
            int ans = 0;
            cur = m;
            for (int j = 1; j <= m; j++)
            {
                b[j] = b2[j];
            }
            for (int j = 1; j <= k; j++)
            {
                if ((1 << (j - 1)) & i)
                {
                    ans += c[j];
                    for (int i1 = 1; i1 <= n; i1++)
                    {
                        for (int j1 = i1 + 1; j1 <= n; j1++)
                        {
                            b[++cur] = {i1, j1, a[j][i1] + a[j][j1]};
                        }
                    }
                }
            }
            sort (b + 1, b + cur + 1, cmp);
            for (int i = 1; i <= cur; i++)
            {
                if (merge(b[i].u, b[i].v))
                {
                    cur++;
                    ans += b[i].w;
                }
                if (cur == n - 1) break;
            }
            if (ans == 12) cout << i << endl;
            the_ans = min(the_ans, ans);
        }
        cout << the_ans << endl;
    }
    void Main()
    {
        read();
        solve();
    }
}