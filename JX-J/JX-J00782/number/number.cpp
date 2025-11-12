#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string S;
    cin >> S;
    string s = "";
    for (int i = 0; i <= S.length() - 1; i++)
    {
        if (S[i] > 47 && S[i] < 58)
        {
            s += S[i];
        }
    }
    int a[s.length()];
    for (int i = 0; i <= s.length() - 1; i++)
    {
        a[i] = s[i] - '0';
    }
    int g[s.length()];
    for (int j = 0; j < s.length(); j++)
    {
        g[s.length()] = 0;
        bool bei = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (j % 2 == 0)
            {
                g[i] = 0;
            }
            g[i] = a[i];
            g[i+1] = a[i+1];
            if (a[i] < a[i+1])
            {
                int t;
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (a[i] != g[i])
            {
                bei = 0;
                break;
            }
        }
        if (bei = 1)
        {
            break;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
