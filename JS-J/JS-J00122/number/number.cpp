#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> a(10, 0);

    char c;
    while (cin >> c)
    {
        if (c >= '0' && c <= '9')
            ++a[c - '0'];
    }

    for (int i = 9; i >= 0; --i)
    {
        for (int j = 1; j <= a[i]; ++j)
        {
            cout << i;
        }
    }
    cout << "\n";

    return 0;
}