#include <bits/stdc++.h>
using namespace std;
struct yessw
{
    int pos,z,dz,dy;
}a[100005],b[100005],c[100005];
int apt(yessw x,yessw y)
{
    return x.z > y.z || (x.z == y.z) &&;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        bool au = 1,bu = 1,cu = 1;
        int n,mansx = 0;
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i].z >> b[i].z >> c[i].z;
            a[i].pos = b[i].pos = c[i].pos = i;
            a[i].dz = b[i],a[i].dy = c[i];
            if (a[i].z)
                au = 0;
            if (b[i].z)
                bu = 0;
            if (c[i].z)
                cu = 0;
            mansx += max(a[i].z,max(b[i].z,c[i].z));
        }
        if (au + bu + cu == 1)
        {
            if (bu)
            {
                for (int i = 1;i <= n;i++)
                {
                    swap(a[i],b[i]);
                }
            }
            else if (cu)
            {
                for (int i = 1;i <= n;i++)
                {
                    swap(a[i],c[i]);
                }
            }
            sort(a + 1,a + n + 1,apt);
            int ans = 0;
            for (int i = 1;i <= n / 2;i++)
            {
                ans += a[i].x;
            }
            cout << ans << '\n';
        }
        else
        {
            cout << mansx << '\n';
        }
    }
    return 0;
}
