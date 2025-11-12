#include <bits/stdc++.h>
using namespace std;
int n, cnt, a[15];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out". "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 3) {
        if (n < 3) {
            cout << 0 << endl;
            return 0;
        }
        int maxn = INT_MIN, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            if (a[i] > maxn) maxn = a[i];
        }
        if (sum > maxn * 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
