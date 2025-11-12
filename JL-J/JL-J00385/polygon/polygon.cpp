#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[5005], s[5005];
ll n, ans, maxn;
const ll MOD = 998244353;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    for (int i = 3; i <= n; i++)
    {
        for (int l = 1; l <= n-i+1; l++)
        {
            maxn = -1e9;
            int r = l + i - 1;
            for (int j = l; j <= r; j++)
            {
                maxn = max(maxn, a[j]);
            }
            if (s[r] - s[l-1] > maxn * 2)
            {
                ans = (ans + 1) % MOD;
            }
        }
    }
    cout << ans+a[2]*2;
    return 0;
}
