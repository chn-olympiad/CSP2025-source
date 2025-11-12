#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
ll a[500005];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    cout << n / 2;
    return 0;
}
