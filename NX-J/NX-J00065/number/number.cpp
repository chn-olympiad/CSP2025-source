#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x, int y)
{
    return x >= y;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int dx = 0;
    if (s.length() == 1) cout << s;
    else
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if ((s[i] >= '1' && s[i] <= '9') || s[i] == '0')
            {
                a[dx] = s[i] - '0';
                dx++;
            }
        }
        sort(a, a + dx, cmp);
        for (int i = 0; i < dx; ++i)
        {
            cout << a[i] << "";
        }
    }
    return 0;
}
