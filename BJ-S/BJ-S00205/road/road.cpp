# include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
const int MAXK = 10 + 7;
struct Node
{
    int u, v;
    int w;
}tsl[MAXN + MAXK];
int a[MAXK][MAXN];

bool cmp(Node x, Node y)
{
    return x.w < y.w;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tsl[i].u = u;
        tsl[i].v = v;
        tsl[i].w = w;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int w;
            cin >> w;
            tsl[i].u = n+i;
            if (j == 0)
                tsl[i].v = n+i;
            tsl[i].v = j;
            tsl[i].w = w;
        }
    }
    sort(tsl+1, tsl+m+1, cmp);
    long long ans = 0;
    for (int i = 1; i <= n-1; i++)
        ans += tsl[i].w;
    cout << ans << endl;
    return 0;
}
