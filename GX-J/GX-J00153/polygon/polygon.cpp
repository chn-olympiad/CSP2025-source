#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    long long n;
    cin >> n;
    long long a[n + 5];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 2; i++)
    {
        int ans = 0;
        for (int j = i; j <= i + 2; j++)
        {
            ans += a[j];
        }
        int maxn = a[i + 2];
        if (ans > maxn * 2)
        {
            cnt++;
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int ans = 0;
        for (int j = i; j <= i + 3; j += i)
        {
            ans += a[j];
        }
        int maxn = a[i + 3];
        if (ans > maxn * 2)
        {
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = i; j <= i + 4; j++)
        {
            ans += a[j];
        }
        int maxn = a[i + 4];
        if (ans > maxn * 2)
        {
            cnt++;
        }
    }
    cout << cnt % 998244353 - 1;
    return 0;
}
