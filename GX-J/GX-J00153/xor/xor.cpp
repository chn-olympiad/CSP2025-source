#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    long long a[n + 5];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long maxn = 0, minn = 999999;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > maxn)
        {
            maxn = a[i];
        }
        if (a[i] < minn && a[i] != 0)
        {
            minn = a[i];
        }
    }
    cout << maxn - minn;
    return 0;
}
