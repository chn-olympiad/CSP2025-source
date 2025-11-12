#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    int ans = 0, zd = 0;
    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        ans += num;
        zd = max(num, zd);
    }
    if(n < 3)
    {
        cout << 0;
        return 0;
    }
    if(n == 3)
    {
        if(ans > zd * 2)
            cout << 1;
        else
            cout << 0;
    }
    else if(zd == 1)
    {
        int ans = n * (n - 1) * (n - 2) % 998244353;
        int sum = 3 * 2;
        cout << (ans / sum) % 998244353;
    }
    else
        cout << n;
    return 0;
}
