#include <bits/stdc++.h>
using namespace std;
int m = -INT_MAX;
bool cmp (int a, int b)
{
    return a < b;
}
int main()
{
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    vector <pair <string, string>> s;
    vector <string> ss, sss;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> ss[i] >> sss[i];
    }
    while (q--)
    {
        for (int i = 0; i < n; i++)
        {
            int len = s.size();
            if (len > m)
            {
                m = ken;
            }
        }
        string y = s[q].head ();
        if (y == ss[m].substr (1, 3))
        {
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
