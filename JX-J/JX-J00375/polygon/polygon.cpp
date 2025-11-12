#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005],ans = 0,maxx = -1;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        ans += a[i];
        if (a[i] > maxx) maxx = a[i];
    }
    if (2 * maxx <= ans) cout << 0;
    return 0;
}
