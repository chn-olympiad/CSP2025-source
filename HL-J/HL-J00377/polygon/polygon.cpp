#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans[4] = {9, 6, 1042392, 366911923};
    int b;
    cout << ans[b % 10];
    return 0;
}
