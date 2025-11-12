#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp ^= a[i];
        if (tmp == k)
        {
            ans++;
            tmp = 0;

        }
    }
    cout << ans << endl;
    return 0;
}
