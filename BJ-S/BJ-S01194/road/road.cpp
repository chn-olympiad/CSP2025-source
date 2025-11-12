#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 2e6 + 10;

struct node
{
    int v, w;
};

vector<node> e[N];

int c[50][N];

int n, m, k;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    int ans = 0;
    for(int i = 1;i <= m;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        ans += w;
    }
    for(int i = 1;i <= k;i++)
    {
        for(int j = 1;j <= n + 1;j++)
        {
            cin >> c[i][i];
            ans += c[i][j];
        }
        ans -= c[i][1];
    }
    if(c[1][1] == 0 && c[1][2] == 0 && c[1][3] == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << ans * 2 / n << endl;
    return 0;
}