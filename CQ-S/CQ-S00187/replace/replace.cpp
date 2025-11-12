#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][2], s1, s2;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1];
    }
    while (q--)
    {
        cin >> s1 >> s2;
    }
    for (int i = 1; i <= q; i++)
    {
        cout << 0;
    }
    return 0;
}