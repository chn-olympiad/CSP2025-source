#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 3)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int maxn = max(a, max(b, c));
        if (a + b + c > maxn * 2)
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
