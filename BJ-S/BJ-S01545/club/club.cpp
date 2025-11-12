#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t, n, a1, a2, a3;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int d = 0;
        for(int i = 1;i <= n;i++)
        {
            cin >> a1 >> a2 >> a3;
            d = max({a1, a2, a3});
        }
        int ans = 0;
        ans += d;
        cout << ans;
    }
}
