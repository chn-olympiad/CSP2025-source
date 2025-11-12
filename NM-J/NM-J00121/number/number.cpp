#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int m = s.size();
    for (int i = 0; i < m; ++i)
    {
        if (s[i] > '9')
        {
            s.erase(i, 1);
            i--;
        }
    }
    m = s.size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            if (s[i] < s[j])
            {
                swap(s[i], s[j]);
            }
        }
    }
    cout << s;
    return 0;
}
