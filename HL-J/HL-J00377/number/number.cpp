#include <bits/stdc++.h>
using namespace std;
int a[1005], n = 1;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[n] = s[i] - '0';
            n++;
        }
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 2; i--)
        cout << a[i];
    return 0;
}
