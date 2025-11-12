#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());
    for (auto t : s)
    {
        if (isdigit(t)) cout << t;
    }
    cout << '\n';
    return 0;
}
