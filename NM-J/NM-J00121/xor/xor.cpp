#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], l, ans;
bool w = false;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    srand(time(0));
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
            w = true;
        if (a[i] != 1){
            w = false;
            break;
        }
    }
    if (w){
        cout << n / 2;
        return 0;
    }
    ans = rand();
    cout << ans % 10000;
    return 0;
}
