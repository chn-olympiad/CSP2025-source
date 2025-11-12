#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
inline void fre()
{
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    return ;
}
int n, m, a[100 + 5];
int ans, x, y, k = 0;
signed main()
{
    fre();
    scanf ("%lld%lld", &n, &m);
    for (rg int i = 1; i <= n * m; i++) scanf ("%lld", &a[i]);
    int f = a[1];
    sort(a + 1, a + (n * m) + 1);
    for (rg int i = (n * m); i >= 1; i--)
    {
        k++;
        if (a[i] == f){
            ans = k;
            break;
        }
    }
    f = ans + n - 1;
    y = f / n;
    ans -= (y - 1) * n;
    if (y % 2 == 0) x = n + 1 - ans;
    else x = ans;
    printf ("%lld %lld\n", y, x);
    return 0;
}
