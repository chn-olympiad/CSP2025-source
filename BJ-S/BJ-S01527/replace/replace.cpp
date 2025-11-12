#include <iostream>
#include <cstring>
using namespace std;

int n, q, t[200005];
string s1[200005], s2[200005], t1, t2;
bool flag = 1;

bool chk(string s)
{
    int ca = 0, cb = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == 'a') ++ca;
        else if (s[i] == 'b') ++ cb;
    return (cb == 1) && (ca + cb == s.size());
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> s1[i] >> s2[i];
    for (int i = 1; i <= n; ++i) flag &= chk(s1[i]) && chk(s2[i]);
    if (flag)
    {
        for (int i = 1; i <= n; ++i)
        {
            int p1 = 0, p2 = 0;
            for (int j = 0; j < s1[i].size(); ++j)
                if (s1[i][j] == 'b')
                {
                    p1 = j;
                    break;
                }
            for (int j = 0; j < s2[i].size(); ++j)
                if (s2[i][j] == 'b')
                {
                    p2 = j;
                    break;
                }
            t[i] = p1 - p2;
        }
    }
    if (n <= 1000 && q <= 1000) flag = false;
    while (q--)
    {
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << "0\n";
            continue;
        }
        if (flag && chk(t1) && chk(t2))
        {
            int p1 = 0, p2 = 0;
            for (int i = 0; i < t1.size(); ++i)
                if (t1[i] == 'b')
                {
                    p1 = i;
                    break;
                }
            for (int i = 0; i < t2.size(); ++i)
                if (t2[i] == 'b')
                {
                    p2 = i;
                    break;
                }
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
                if (s1[i].size() <= t1.size() && t[i] == p1 - p2)
                    ++cnt;
            cout << cnt << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            string t3 = "", t4 = "";
            for (int j = 0; j + s1[i].size() - 1 < t1.size(); ++j)
            {
                if (t3 != t4) continue;
                bool f = true;
                for (int k = 0; k < s1[i].size(); ++k)
                    if (t1[j+k] != s1[i][k] || t2[j+k] != s2[i][k])
                    {
                        f = false;
                        break;
                    }
                for (int k = j + s1[i].size(); k < t1.size(); ++k)
                    if (t1[k] != t2[k])
                    {
                        f = false;
                        break;
                    }
                if (f) ++ans;
                t3 += t1[j];
                t4 += t2[j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
