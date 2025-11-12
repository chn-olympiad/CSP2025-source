#include<bits/stdc++.h>
using namespace std;
long long n, m, k, fa[20001], xi[11], bol = 0, ans = 0;
struct node
{
    long long x, y, z;
}a[2000001], b[2000001];
bool cmp(node c, node d)
{
    return c.z < d.z;
}
int f(int x)
{
    if(fa[x] == x)
    {
        return x;
    }
    else
    {
        return fa[x] = f(fa[x]);
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= n + k;i++)
    {
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++)
    {
        cin >> b[i].x >> b[i].y >> b[i].z;
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> xi[i];
        for(int j = 1;j <= n;j++)
        {
            int t;
            cin >> t;
            b[m + (i - 1) * n + j].x = j;
            b[m + (i - 1) * n + j].y = n + i;
            b[m + (i - 1) * n + j].z = t;
        }
        if(xi[i] != 0)
        {
            bol = 1;
        }
    }
    if(bol == 0)
    {
        sort(b + 1, b + m + k * n + 1, cmp);
        for(int i = 1;i <= m + n * k;i++)
        {
            //cout << b[i].x << " " << b[i].y << " " << b[i].z << endl;
            int xx = b[i].x, yy = b[i].y;
            if(f(xx) != f(yy))
            {
                fa[f(xx)] = f(yy);
                ans += b[i].z;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
