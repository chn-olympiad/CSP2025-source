#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdio>
using namespace std;

int n, q;
map <string, string> s, t;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "out", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string a, b;
        cin >> a >> b;
        s[a] = b;
        t[b] = a;
    }
    while (q--)
    {
        int cnt = 0;
        string a, b;
        cin >> a >> b;
        int x = -1, y = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (x == -1 && a[i] == b[i]) continue;
            if (x != -1 && a[i] != b[i]) continue;
            if (x != -1)
            {
                y = i - 1;
                break;
            }
            x = i;
        }
        if (y == 0) y = a.size() - 1;
        for (int l = 0; l <= x; l++)
        {
            for (int r = y; r < a.size(); r++)
            {
                string c = a.substr(l, r - l + 1), d = b.substr(l, r - l + 1);
                if (s[c] == d) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
