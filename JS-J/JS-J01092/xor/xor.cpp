#include<bits/stdc++.h>
using namespace std;

int a[5005];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, ans = 0;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++)
        ans += a[i];
    cout << ans << endl;
    return 0;
}
