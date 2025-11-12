#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool flag = true;
int n, q, it, ans, pos1, pos2;
string x, y, z, s1[200005], s2[200005];
vector<pair<int, int> > v[10000005];

int main()
{
    freopen("replace3.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (register int i = 1; i <= n; ++i)
    {
        cin >> s1[i] >> s2[i];
        if (flag)
        {
            for (register auto it: s1[i])
            {
                if (it != 'a' && it != 'b')
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (n <= 300 || !flag)
    {
        while (q--)
        {
            cin >> x >> y;
            ans = 0;
            for (register int i = 1; i <= n; ++i)
            {
                it = x.find(s1[i]);
                if (it != x.npos)
                {
                    x.replace(it, s1[i].size(), s2[i]);
                    ans += (x == y);
                    x.replace(it, s1[i].size(), s1[i]);
                }
            }
            cout << ans << "\n";
        }
        return 0;
    }
    if (flag)
    {
        for (register int i = 1; i <= n; ++i)
        {
            pos1 = s1[i].find('b');
            pos2 = s2[i].find('b');
            v[pos1 - pos2 + 5000000].push_back(make_pair(pos1, s1[i].size() - pos1 - 1));
        }
        while (q--)
        {
            cin >> x >> y;
            ans = 0;
            pos1 = x.find('b');
            pos2 = y.find('b');
            for (register auto it: v[pos1 - pos2 + 5000000])
            {
                ans += (pos1 >= it.first && x.size() - pos1 - 1 >= it.second);
            }
            cout << ans << "\n";
        }
        return 0;
    }
    return 0;
}
