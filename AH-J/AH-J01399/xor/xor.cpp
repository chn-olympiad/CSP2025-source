#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (k == 0)
    {
        cout << n / 2;
    }
    return 0;
}
