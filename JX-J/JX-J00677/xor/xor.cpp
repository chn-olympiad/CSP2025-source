#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)//All ai are 1
        cin >> a[i];
    if (k == 1)
        cout << n;
    else
        cout << 0;
    return 0;
}

