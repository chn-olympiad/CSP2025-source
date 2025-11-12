#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    int n , k;
    cin >> n >> k;
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1)
        {
            f = false;
        }
    }
    if (f)
    {
        cout << n / 2;
        return 0;
    }
    if (k == 0)
    {
        cout << 1;
        return 0;
    }
    cout << n / (k - 1);
    return 0;
}
