#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    string a[s.size() + 5];
    int b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            a[++b] = s[i];
        }
    }
    sort(a + 1, a + b + 1);
    for (int i = b; i >= 1; i--)
    {
        cout << a[i];
    }
    return 0;
}
