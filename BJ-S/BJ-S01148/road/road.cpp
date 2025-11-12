#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;

vector<int> g[N];
struct edge
{
    long long u, v, w;
    bool operator < (const edge &a) const
    {
        return a.w > w;
    }
}e[M];
int f[N];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int a, int b)
{
    f[find(a)] = find(b);
}
int n, m, k;
int a[20][N];

int kruskal()
{
    sort(e + 1, e + m + 1);
    for(int i = 1; i <= m; i++)
        f[i] = i;
    long long cnt = n, ans = 0;
    for(int i = 1; i <= m; i++)
    {
        if(find(e[i].u) != find(e[i].v))
            merge(e[i].u, e[i].v), ans += e[i].w, cnt--;
        if(cnt == 1)
            return ans;
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        e[i] = {u, v, w};
    }
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j <= n; j++)
            cin >> a[i][j];
    }
    cout << kruskal();



    return 0;
}
