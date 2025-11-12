#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 3001;

map<int, vector<pair<int, int> > > limb;
string t1, t2, ss1, ss2, s1[MAX_N], s2[MAX_N];
bool pre[MAX_N], suf[MAX_N];
int n, q, l[MAX_N];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    if (n <= 2000)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> s1[i] >> s2[i];
            l[i] = s1[i].length();
            s1[i] = s1[i];
            s2[i] = s2[i];
        }
        while (q --> 0)
        {
            int ll, ans = 0;

            cin >> t1 >> t2;
            ll = t1.length();
            t1 = '#' + t1;
            t2 = '#' + t2;
            pre[0] = true;
            suf[ll + 1] = true;
            for (int i = 1; i <= ll; i++)  { pre[i] = t1[i] == t2[i] && pre[i - 1]; }
            for (int i = ll; i >= 1; i--)  { suf[i] = t1[i] == t2[i] && suf[i + 1]; }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j + l[i] - 1 <= ll; j++)  { ans += t1.substr(j, l[i]) == s1[i] && t2.substr(j, l[i]) == s2[i] && pre[j - 1] && suf[j + l[i]]; }
            }
            cout << ans << endl;
        }
    }
    else
    {
        limb.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> ss1 >> ss2;

            int a, b;

            for (a = 0; ss1[a] != 'b'; a++);
            for (b = 0; ss2[b] != 'b'; b++);
            limb[a - b].emplace_back(a, ss1.size() - a);
        }
        for (auto &ele : limb)  { sort(ele.second.begin(), ele.second.end()); }
        while (q --> 0)
        {
            cin >> t1 >> t2;

            int a, b, ans = 0;

            for (a = 0; t1[a] != 'b'; a++);
            for (b = 0; t2[b] != 'b'; b++);
            for (auto ele : limb[a - b])
            {
                if (ele.first > a)  { break; }
                if (ele.second <= int(t1.size() - a))  { ans++; }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
