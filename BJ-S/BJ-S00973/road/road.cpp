#include <bits/stdc++.h>
using namespace std;
struct road
{
    int l,r,o;
} a[10005];
int n,m,k,fa[10005];
int zhao(int x)
{
    return x = (fa[x] == x ? x : zhao(fa[x]));
}
bool cmp(road x,road y)
{
    return x.o < y.o;
}
bool ql = 1;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int aans = 0;
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[i].l = x;
        a[i].r = y;
        a[i].o = z;
        aans += z;
    }
    for (int i = 1;i <= m;i++)
    {
        int x;
        cin >> x;
        if (x)
            ql = 0;
        for (int j = 1;j <= n;j++)
        {
            int y;
            cin >> y;
            if (y)
                ql = 0;
        }
    }
    if (ql)
    {
        cout << 0;
    }
    else if (k == 0)
    {
        for (int i = 1;i <= n;i++)
        {
            fa[i] = i;
        }
        int ans = 0;
        sort(a + 1,a + n + 1,cmp);
        for (int i = 1;i <= n;i++)
        {
            if (zhao(a[i].l) != zhao(a[i].r));
            {
                ans += a[i].o;
                fa[a[i].l] = a[i].r;
            }
        }
        cout << ans;
    }
    else
    {
        cout << aans;
    }
    return 0;
}
