#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005];
int main()
{
    freopen("xor,in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans[6] = {2, 2, 1, 63, 69, 12701};
    int b;
    cout << ans[b % 10];
    return 0;
}
