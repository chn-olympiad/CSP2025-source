#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    int n, m, l, r, a[1048580];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == m)
        {
            l = r = i;
            if (i == 1 || i == n)
            {
                cout << 2;
            }
            else
            {
                cout << 1;
            }
        }
    }
    return 0;
}
