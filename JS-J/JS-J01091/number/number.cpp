#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, sa = "";
    cin >> s;

    int n = 0;
    for (int i = 0; i < s.size(); i++)
        if (isdigit(s[i])) a[++n] = s[i] - '0';

    sort(a + 1, a + n + 1);

    if (a[n] == 0) cout << "0\n";
    else
    {
        for (int i = n; i >= 1; i--)
            cout << a[i];
        cout << "\n";
    }
    return 0;
}
