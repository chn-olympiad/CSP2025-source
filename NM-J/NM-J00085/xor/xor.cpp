#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int n1 = 0, n0 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            n0++;
        }
        else if (a[i] == 1)
        {
            n1++;
        }
    }
    if (n1 == n)
    {
        cout << n / 2;
        return 0;
    }
    if (n1 + n0 == n)
    {
        if (k == 0)
        {
            cout << n0 + n1 / 2;
        }
        else
        {
            cout << n1;
        }
        return 0;
    }
}