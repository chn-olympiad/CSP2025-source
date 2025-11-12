#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0, xor_sum = 0;
    int l = 0, r = 0;
    while (l != n)
    {
        xor_sum ^= a[r];
        if (xor_sum == k)
        {
            cnt++;
            l = r + 1;
            r = l;
            xor_sum = 0;
        }
        else if (r == n)
        {
            l++;
            r = l;
            xor_sum = 0;
        }
        else
        {
            r++;
        }
    }
    cout << cnt;
    return 0;
}