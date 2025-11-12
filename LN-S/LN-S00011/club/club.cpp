#include <bits/stdc++.h>
using namespace std;

int t, n;

struct node
{
    bool flag = false;
    int x, y, z;
}a[1000010];

bool compFun1(node x, node y)
{
    return x.x > y.x;
}

bool compFun2(node x, node y)
{
    return x.y > y.y;
}

bool compFun3(node x, node y)
{
    return x.z > y.z;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].x >> a[i].y >> a[i].z;
        sort(a + 1, a + n + 1, compFun1);
        for (int i = 1; i <= n / 2; i++)
            if (a[i].x > a[i].y && a[i].x > a[i].z && !a[i].flag)
                ans += a[i].x, a[i].flag = true;
        sort(a + 1, a + n + 1, compFun2);
        for (int i = 1; i <= n / 2; i++)
            if (a[i].y > a[i].x && a[i].y > a[i].z && !a[i].flag)
                ans += a[i].y, a[i].flag = true;
        sort(a + 1, a + n + 1, compFun3);
        for (int i = 1; i <= n / 2; i++)
            if (a[i].z > a[i].x && a[i].z > a[i].y && !a[i].flag)
                ans += a[i].z, a[i].flag = true;
        cout << ans << endl;
    }
    return 0;
}
