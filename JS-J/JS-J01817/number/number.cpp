#include <bits/stdc++.h>
using namespace std;
int a[15];
signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    char c;
    while (cin >> c)
    {
        if (isdigit(c))
        {
            a[c - 48]++;
        } 
    } 
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            cout << i;
        } 
    } 
    cout << "\n";
    return 0;
} 