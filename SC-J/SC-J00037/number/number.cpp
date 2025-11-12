#include <bits/stdc++.h>
using namespace std;

string s;
int a[100100], d;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            a[d++] = s[i] - 48;
        }
    }
    sort(a, a + d);
    for (int i = d - 1; i >= 0; --i)
    {
        cout << a[i];
    }
    return 0;
}