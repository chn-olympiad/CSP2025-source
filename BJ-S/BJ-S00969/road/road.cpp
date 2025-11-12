#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Edge
{
    int id, w;
} e[1000010];

bool cmp(Edge A, Edge B)
{
    return A.w < B.w;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> e[i].w;
        e[i].id = 0;
    }
    sort(e + 1, e + n + 1, cmp);
    long long sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += e[i].w;
    }
    cout << sum << endl;
    return 0;
}
