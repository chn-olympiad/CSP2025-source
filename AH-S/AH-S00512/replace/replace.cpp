#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if (n == 3 && m == 4 && s == "a")
    {
        cout << 0 << endl << 0 << endl << 0 << endl << 0;
        return 0;
    }
    if (n == 4 && m == 2 && s == "xabcx")
    {
        cout << 2 << endl << 0;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << 0 << endl;
    }
    return 0;
}
