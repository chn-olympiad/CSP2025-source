#include <bits/stdc++.h>
using namespace std;
long long n;
long long k, a[5000005], maxn = INT_MIN;
long long counti(int l, int ans)
{
    int now = a[l];
    for (int i = l + 1; i <= n; i ++)
    {
        if(now == k)
        {
            ans += 1;
            return counti(i, ans);
        }
        now ^= a[i];
    }
    if(now == k)
    {
        ans += 1;
    }
    return ans;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        maxn = max(maxn, counti(i, 0));
    }
    cout << maxn;
    return 0;
}
