#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
#define int long long

int n, m, k;
struct edge
{
    int u, v, w;
    bool operator<(const edge& T) const
    {
        return w < T.w;
    }
}Edge[MAXN];
int cnt = 0;
int c[10035], a[15][10035];
bool Ned[MAXN], Used[MAXN]; // 是否为必须联通,村子是否用过一次

/// @brief  最小生成树
int Fa[MAXN];
class MST
{
private:
    int Find(int i) { return Fa[i] == i ? Fa[i] : Fa[i] = Find(Fa[i]); }
public:
    int Kruskal()
    {
        for (int i = 1; i <= cnt; i ++)
            Fa[i] = i;

        sort(Edge + 1, Edge + cnt + 1);
        int res = 0, total = 0;
        set<int> node; // 检查放完没有
        for (int i = 1; i <= cnt; i ++)
        {
            if ((int)node.size() == n && total >= n - 1)
                break;
            
            int u = Edge[i].u, v = Edge[i].v;
            int fu = Find(u), fv = Find(v);

            if (fu == fv) continue;
            Fa[fu] = fv; 
            res += Edge[i].w;
            if (Ned[u]) node.insert(u);
            if (Ned[v]) node.insert(v);
            if (!Ned[u]) 
            {
                if (Used[u]) res -= c[u - n];
                Used[u] = true;
            }
            else if (!Ned[v]) 
            {
                if (Used[v]) res -= c[v - n];
                Used[v] = true;
            }

            total ++;
        }
        return res;
    }
};

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        cnt ++;
        cin >> Edge[cnt].u >> Edge[cnt].v >> Edge[cnt].w;
        Ned[Edge[cnt].v] = true; Ned[Edge[cnt].u] = true;
    }
    for (int i = 1; i <= k; i ++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j ++)
        {
            cin >> a[i][j];
            cnt ++;
            Edge[cnt].u = n + i, Edge[cnt].v = j, Edge[cnt].w = c[i] + a[i][j];
            Ned[Edge[cnt].u] = false;
        }
    }

    MST mst;
    int ans = mst.Kruskal();
    cout << ans << "\n";

    return 0;
}
/*
7583346800
5182974424
*/