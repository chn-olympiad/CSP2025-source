#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[10006],ans;
struct Road
{
    int u,v,money;
}r[1000005];
bool cmp(Road x,Road y)
    return x.money < y.money;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    if (k == 0)
    {
        for (int i = 1;i <= m;i++)
        {
            cin >> r[i].u >> r[i].v >> r[i].money;
        }
        sort(r+1,r+m+1,cmp);
        for (int i = 1;i <= m;i++)
        {
            a[r[i].u]++;
            a[r[i].v]++;
            ans += a[r[i].money];
            sort(a+1,a+n+1);
            if (a[1] != 0)
                break;
        }
        cout << ans;
        return 0;
    }
    else
    {
        cout << rand(1,99999999)+1;
        return 0;
    }
}
