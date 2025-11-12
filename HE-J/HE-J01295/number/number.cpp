#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    string s;
    int n = 0, a[10005];
    cin >> s;
    for (int i = 1; i <= s.length(); i++)
    {
        if (s.length() >= '0' && s.length() <= '9')
        {
            a[i] = s.length();
            n++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i + 1] > a[i])
        {
            sort (a[i], a[i + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    return 0;
}

