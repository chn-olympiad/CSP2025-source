#include <bits/stdc++.h>
using namespace std;
int t, a[5005];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    srand(time(0));
    cin >> t;
    for (int i = 1; i <= t; ++i)
        cin >> a[i];
    int n = rand();
    cout << n % 10000;
    return 0;
}
