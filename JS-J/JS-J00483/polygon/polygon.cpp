#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, a[5005];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> n;
    sort(a, a + n);
    if(n == 3)
    {
        int sum = a[0] + a[1] + a[2];
        if(sum > 2 * a[2])
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}
