#include <bits/stdc++.h>
using namespace std;
int a[200005];
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, f = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!a[i]) f = 0;
    } 
    if (f)
    {
        cout << n / 2 << "\n";
        return 0;
    } 
    else
    {
        int ans = 0;
        if (k == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (!a[i]) ans++;
                else if (i != n && a[i] && a[i + 1]) ans++, i++;
            } 
        } 
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i]) ans++;
            } 
        } 
        cout << ans << "\n";
    } 
    return 0;
} 