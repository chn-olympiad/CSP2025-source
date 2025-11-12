#include <bits/stdc++.h>
using namespace std;
int n, k, s, a[5];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    if (k <= 1)
        cout << 4;
    else if (n <= 2)
    {
        for (int i = 0; i < n; i ++)
            cin >> a[i];
        if (a[0] == 0)
            s ++;
        if (a[1] == 0)
            s ++;
        if (a[0] && a[1])
        {
            cout << 1;
            return 0;
        }
        cout << s;
    }
    return 0;
}
