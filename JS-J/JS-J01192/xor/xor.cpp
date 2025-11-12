#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int a[500005];


int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    bool b = false, c = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1) b = true;
        if (a[i] > 1) c = true;
    }
    int ans = 0;
    if (b == false && k == 0) ans = n / 2;
    if (c == false && b == true)
    {
        if (k == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == a[i + 1]) ans++; i += 2;
                if (i > n) break;
            }
        }
        if (k == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] != a[i + 1]) ans++; i += 2;
                if (i > n) break;
            }
        }
    }
    cout << ans;
    return 0;
}
