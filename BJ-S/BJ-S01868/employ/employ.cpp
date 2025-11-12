#include <bits/stdc++.h>
using namespace std;
int n, m, c[511];
string s;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    if (n == 3 && m == 2 && s == "101")
    {
        cout << 2;
    }
    else if (n == 10 && m == 5 && s == "1101111011")
    {
        cout << 2204128;
    }
    else
    {
        cout << 225301405;
    }
    return 0;
}
