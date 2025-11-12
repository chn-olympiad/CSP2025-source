#include <bits/stdc++.h>
using namespace std;
int n, q;
struct node
{
    string s, t;
}a[200005], sut[200005];
//min
    map <string, vector <string>> mp;
void submin()
{
    for (int i = 1; i <= n; i ++)
    {
        mp[a[i].s].push_back(a[i].t);
    }
    for (int i = 1; i <= q; i ++)
    {
        int ans = 0;
        string s = sut[i].s, t = sut[i].t;
        s = " " + s;
        int lens = s.size() - 1, lent = t.size() - 1;
        for (int l = 1; l <= lens; l ++)
        {
            for (int r = l; r <= lens; r ++)
            {
                string head = s.substr(1, l - 1);
                string mid = s.substr(l, r - l + 1);
                string tail = s.substr(r + 1, lens - r);
                for (auto sss : mp[mid])
                {
                    if (head + sss + tail == t) ans ++;
                }
            }
        }
        cout << ans << "\n";
    }
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    int L1 = 0, L2 = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].s >> a[i].t;
    }
    for (int i = 1; i <= q; i ++)
    {
        cin >> sut[i].s >> sut[i].t;
    }
    submin();
    return 0;
}