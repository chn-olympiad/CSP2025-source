#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[5005];
const int MOD = 998244353;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;
    for(int i = 1; i<=n;i++)
    {
        cin >> a[i];
    }
    int l = 1<< n, maxl, sum;
    for(int i = 7; i < l; i++)
    {
        sum= maxl = 0;
        if(__builtin_popcount(i)>=3)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i&(1<<j))
                {
                    sum += a[j + 1];
                    maxl = max(maxl, a[j + 1]);
                }
            }
            if(sum > 2*maxl)ans = (ans+ 1)%MOD;
        }
    }
    cout << ans;
    return 0;
}
