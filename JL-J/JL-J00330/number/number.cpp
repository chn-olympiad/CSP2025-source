#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    string a[sizeof(s) + 1];
    int n = 1;
    for (int i = 0;i <= sizeof(s);i++)
    {
        a[i] = '0';
    }
    for (int i = 0;i < sizeof(s);i++)
    {
        if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
        {
            a[n] = s[i];
            n++;
        }
    }
    for (int i = 2;i <= n - 1;i++)
    {
        if (a[i - 1] < a[i])
        {
            string t = a[i];
            a[i] = a[i - 1];
            a[i - 1] = t;
        }
    }
    for (int i = 1;i <= n - 1;i++)
    {
        cout << a[i];
    }
    return 0;
}
