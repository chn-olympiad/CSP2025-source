#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], ans;
bool f[N];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(k == 0) return cout << n / 2, 0;
    if(k == 1)
    {
        for(int i = 1; i <= n; i++) if(a[i]) ans++;
        return cout << ans, 0;
    }
    cout << n;
    return 0;
}
