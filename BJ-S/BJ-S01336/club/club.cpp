#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y, z, f;
} a[100010];

int b[100010];

void init()
{
    int n, ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, mx;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
        mx = max({a[i].x, a[i].y, a[i].z});
        ans += mx;
        if (mx == a[i].x)
        {
            a[i].f = 1;
            cnt1++;
        }
        else if (mx == a[i].y)
        {
            a[i].f = 2;
            cnt2++;
        }
        else
        {
            a[i].f = 3;
            cnt3++;
        }
    }
    mx = max({cnt1, cnt2, cnt3});
    if (mx <= n / 2)
    {
        cout << ans << endl;
        return;
    }
    int cur = 0;
    if (mx == cnt1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i].f == 1)
            {
                b[++cur] = a[i].x - max(a[i].y, a[i].z);
            }
        }
    }
    else if (mx == cnt2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i].f == 2)
            {
                b[++cur] = a[i].y - max(a[i].x, a[i].z);
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i].f == 3)
            {
                b[++cur] = a[i].z - max(a[i].x, a[i].y);
            }
        }
    }
    sort(b + 1, b + cur + 1);
    for (int i = 1; i <= mx - n / 2; i++)
    {
        ans -= b[i];
    }
    cout << ans << endl;
    return;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        init();
    }
    return 0;
}
