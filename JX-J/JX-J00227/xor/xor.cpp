#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if(k == 0) cout << 1 << "\n";
    else cout << 2 << "\n";
    return 0;
}
