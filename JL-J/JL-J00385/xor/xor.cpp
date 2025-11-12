#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll a[500005];
ll ans, cnt;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (auto i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 0;
    while (l <= n)
    {
        l++;
        cnt = a[l];
        for (int r = l+1; r <= n; r++)
        {
            if (cnt > k)
                continue;
            if (cnt == k)
            {
                ans++;
                l = r-1;
                continue;
            }
            cnt ^= a[r];
        }
    }
    cout << ans;
    return 0;
}
