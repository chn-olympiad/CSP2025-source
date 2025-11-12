#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    bool f = true;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1) f = false;
    }
    if (f)
    {
        if (k == 0) cout << n / 2;
        else cout << n;
    }
    return 0;
}
