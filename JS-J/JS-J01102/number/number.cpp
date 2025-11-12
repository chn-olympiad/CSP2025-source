#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) t += s[i];
    }
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    cout << t;
    return 0;
}
