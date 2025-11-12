#include <bits/stdc++.h>
using namespace std;


const int base = 31, mod = 1e9 + 7;
int hashs(string s)
{
    int sum = 0, base2 = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        sum = (sum + 1ll * base2 * (s[i] - 'a' + 1)) % mod;
        base2 *= base;
    }
    return sum;
}
string st[200005][2];
int hs[200005][2];
map<int, int> mp[200005][2];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> st[i][0] >> st[i][1];
        hs[i][0] = hashs(st[i][0]), hs[i][1] = hashs(st[i][1]);
    }
    for (int i = 1; i <= q; ++i)
    {
        string x, y;
        cin >> x >> y;
        if (x.size() != y.size())
        {
            cout << 0 << endl;
            continue;
        }
        int lft, rft;
        for (int j = 0; j < x.size(); ++j)
        {
            if (x[j] != y[j])
            {
                lft = j;
                break;
            }
        }
        for (int j = x.size(); j >= 0; --j)
        {
            if (x[j] != y[j])
            {
                rft = j;
                break;
            }
        }
        cout << 0 << endl;
    }
    return 0;
}