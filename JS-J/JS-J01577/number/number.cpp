#include <bits/stdc++.h>
#define int long long
using namespace std;

int t[15];

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) t[s[i] - '0']++;
    }
    for (int i = 9; i >= 0; i--)
    {
        if (t[i] > 0)
        {
            for (int j = 1; j <= t[i]; j++)
                cout << i;
        }
    }
    cout << '\n';
    return 0;
}