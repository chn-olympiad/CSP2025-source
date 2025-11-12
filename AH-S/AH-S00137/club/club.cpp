#include <bits/stdc++.h>
using namespace std;

int n,T;

struct D
{
    int d1,d2,d3;
}a[100005];

bool cmp(D x,D y)
{
    return x.d1 > y.d1;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T--)
    {
        int ans = 0;
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
        }
        sort(a + 1,a + n + 1,cmp);
        for (int i = 1;i <= n / 2;i++)
        {
            ans += a[i].d1;
        }
        cout << ans << endl;
    }
    return 0;
}

