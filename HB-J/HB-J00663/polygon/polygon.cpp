#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 10;
int n;
int a[N];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(a[1] == 1 && a[n] == 1)
    {
        n = n - 2;
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                ans = ans + j;
            }
        }
        cout << ans;
        return 0;
    }
    if(a[1] + a[2] > a[3]) cout << 1;
    else cout << 0;
    return 0;
}
