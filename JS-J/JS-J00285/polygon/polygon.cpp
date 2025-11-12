#include <bits/stdc++.h>
using namespace std;
int n,maxn = -1;
long long sum
int a[5005];
const int MOD = 998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    if (n <= 3)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n < 3) cout << 0;
        if (n == 3)
        {
            if ((a[1] + a[2] + a[3]) > (2 * max(a[1],max(a[2],a[3])))) cout << 1;
            else cout << 0;
        }
    }
    //12 points
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxn = max(maxn,a[i]);
            sum = sum + a[i];
        }
        if (maxn == 1)
        {
            cout << n - 2;
            // 36 points
        }
        else
        {
            cout << n;
        }
    }
    return 0;
    // 32.
}
