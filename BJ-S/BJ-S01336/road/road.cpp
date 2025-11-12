#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y, z;
} a[1000010];

int f[10010];

bool cmp(node x, node y)
{
    return x.z < y.z;
}

int find(int x)
{
    if (f[x] == x)
    {
        return x;
    }
    return f[x] = find(f[x]);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int fx = find(a[i].x), fy = find(a[i].y);
        if (fx != fy)
        {
            ans += a[i].z;
            f[fx] = fy;
        }
    }
    cout << ans << endl;
    return 0;
}
