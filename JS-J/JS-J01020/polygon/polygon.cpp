#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5;
ll n, a[N];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (max(a[1], max(a[2], a[3])) < a[1] + a[2] + a[3] - max(a[1], max(a[2], a[3]))) cout << 1;
    else cout << 0;
    return 0;
}
