#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s, t;
    cin >> s;
    for (char ch : move(s))
        if (isdigit(ch))
            t += ch;
    sort(begin(t), end(t), greater<>());
    cout << t;
    return 0;
}
