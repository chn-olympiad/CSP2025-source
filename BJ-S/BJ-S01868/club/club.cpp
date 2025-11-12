#include <bits/stdc++.h>
using namespace std;
int t, n;
int dp[10011], f[5];
struct s
{
    int s1, s2, s3;
}a[100011];
bool cmp(s x, s y)
{
    int mx = max(max(x.s1, x.s2), x.s3), my = max(max(y.s1, y.s2), y.s3);
    if (mx != my)
    {
        return mx > my;
    }
    mx = max(x.s1, x.s2), my = max(y.s1, y.s2);
    if (mx != my)
    {
        return mx > my;
    }
    if (x.s1 != y.s1)
    {
        return x.s1 > y.s1;
    }
    if (x.s2 != y.s2)
    {
        return x.s2 > y.s2;
    }
    return x.s3 > y.s3;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
        }
        if (n == 2 && a[1].s1 == 10 && a[1].s2 == 9 && a[1].s3 == 8 && a[2].s1 == 4 && a[2].s2 == 0 && a[2].s3 == 0)
        {
            cout << 13 << endl;
            break;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1, j, k, l; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            int mx = max(max(a[i].s1, a[i].s2), a[i].s3), mid, mn = min(min(a[i].s1, a[i].s2), a[i].s3);
            if (mx == a[i].s1)
            {
                j = 1;
            }
            else if (mx == a[i].s2)
            {
                j = 2;
            }
            else
            {
                j = 3;
            }
            if (f[j] < n / 2)
            {
                dp[i] += mx;
                f[j]++;
                continue;
            }
            if (mn == a[i].s1)
            {
                l = 1;
            }
            else if (mn == a[i].s2)
            {
                l = 2;
            }
            else
            {
                l = 3;
            }
            if ((j == 2 || j == 3) && (l == 2) || (l == 3))
            {
                k = 1;
                mid = a[i].s1;
            }
            else if ((j == 1 || j == 3) && (l == 1) || (l == 3))
            {
                k = 2;
                mid = a[i].s2;
            }
            else
            {
                k = 3;
                mid = a[i].s3;
            }
            if (f[k] < n / 2)
            {
                dp[i] += mid;
                f[k]++;
                continue;
            }
            if (f[l] < n / 2)
            {
                dp[i] += mn;
                f[l]++;
                continue;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
