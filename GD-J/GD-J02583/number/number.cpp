#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (const auto &i : s)
        if (isdigit(i))
            t += i;
    sort(t.begin(), t.end(), greater<char>());
    cout << t << '\n';
    return 0;
}