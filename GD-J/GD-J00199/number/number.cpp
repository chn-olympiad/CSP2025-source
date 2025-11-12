#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main()
{
    if (1)
    {
        freopen("number.in", "r", stdin);
        freopen("number.out", "w", stdout);
    }
    string s, t;
    cin >> s;
    for (char ch : s)
    {
        if (isdigit(ch))
        {
            t += ch;
        }
    }
    stable_sort(t.begin(), t.end(), greater<char>());
    cout << t << '\n';
}