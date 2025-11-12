#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],ansl = 1,ansh,t;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
        cin >> a[i];
    int xr = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    for (int i = 1;i <= n * m;i++)
    {
        if (t == 0)
        {
            if (ansh == m)
                ansl++,t = 1;
            else
                ansh++;
        }
        else
        {
            if (ansh == 1)
                ansl++,t = 0;
            else
                ansh--;
        }
        if (a[i] == xr)
        {
            cout << ansl << " " << ansh;
            return 0;
        }
    }
    return 0;
}
