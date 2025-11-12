#include <bits/stdc++.h>
using namespace std;
string s;
int x;
char c[1000006];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i ++)
        if (s[i] >= '0' && s[i] <= '9')
            c[x ++] = s[i];
    sort(c, c + x);
    for (int i = x - 1; i >= 0; i --)
        cout << c[i];
    return 0;
}
