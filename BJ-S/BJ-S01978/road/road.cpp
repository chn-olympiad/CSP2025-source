#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 1e6 + 7, K = 17;
struct node
{
    long long x, y, z;
}a[M + N * K];
int f[N];
int n, m, k, cnt = 0;
bool cmp(node n1, node n2)
{
    return n1.z < n2.z;
}
int find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = find(f[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cnt++;
        cin >> a[cnt].x >> a[cnt].y >> a[cnt].z;
    }
    int t;
    for (int i = 1; i <= k; i++)
    {
        cin >> t;
        cnt++;
        cin >> a[cnt].x >> a[cnt].y >> a[cnt].z;
    }
    sort(a, a+1+cnt, cmp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    long long ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (find(a[i].x) != find(a[i].y))
        {
            f[a[i].x] = a[i].y;
            ans += a[i].z;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
