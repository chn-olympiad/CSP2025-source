#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[5005], mod = 998244353;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans;
    if (n == 3) ans = (a[1] + a[2] > a[3]);
    if (n == 4) ans = (a[1] + a[2] > a[3]) + (a[1] + a[2] > a[4]) + (a[2] + a[3] > a[4]) + (a[1] + a[2] + a[3] > a[4]);
    if (n == 5) ans = (a[1] + a[2] > a[3]) + (a[1] + a[2] > a[4]) + (a[1] + a[2] > a[5]) + (a[1] + a[3] > a[4]) + (a[1] + a[3] > a[5]) + (a[1] + a[4] > a[5]) + (a[2] + a[3] > a[4]) + (a[2] + a[3] > a[5]) + (a[2] + a[4] > a[5]) + (a[3] + a[4] > a[5]) + (a[1] + a[2] + a[3] > a[4]) + (a[1] + a[2] + a[3] > a[5]) + (a[1] + a[2] + a[4] > a[5]) + (a[1] + a[3] + a[4] > a[5]) + (a[2] + a[3] + a[4] > a[5]) + (a[1] + a[2] + a[3] + a[4] > a[5]);
    cout << ans % mod;
    return 0;
}
