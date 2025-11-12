#include <bits/stdc++.h>

using namespace std;
map<string, int> vis;
string s1[200010], s2[200010];
int qa[200010], ha[200010], qa1[200010], ha1[200010];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q, io = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s1[i] >> s2[i];
        vis[s1[i]] = i;
        int cnt = 0, cnt1 = 0, cnt3 = 0, cnt2 = 0, cn, cn1;
        for (int j = 0; j < s1[i].size(); ++j)
        {
            if (s1[i][j] == 'a') ++cnt;
            else if (s1[i][j] == 'b') ++cnt1, cn = j;
            if (s2[i][j] == 'a') ++cnt2;
            else if (s2[i][j] == 'b') ++cnt3, cn1 = j;
        }
        if (cnt1 == 1 && cnt3 == 1 && cnt1 + cnt2 == cnt2 + cnt3 && cnt1 + cnt2 == s1[i].size())
        {
            ++io;
            qa[i] = cn, ha[i] = s1[i].size() - cn - 1;
            qa1[i] = cn1, ha1[i] = s1[i].size() - cn1 - 1;
        }
    }
//cout << io << " " << qa[1] << " " << ha[1] << " " << qa1[1] << " " << ha1[1] << endl;
    while (q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int cna, cnb;
        int cnt = 0, cnt1 = 0, cnt3 = 0, cnt2 = 0, cn, cn1;
        for (int i = 0; i < t1.size(); ++i)
        {
            if (t1[i] == 'a') ++cnt;
            else if (t1[i] == 'b') ++cnt1, cna = i;
            if (t2[i] == 'a') ++cnt2;
            else if (t2[i] == 'b') ++cnt3, cnb = i;
        }
        if (cnt1 == 1 && cnt3 == 1 && cnt1 + cnt2 == cnt2 + cnt3 && cnt1 + cnt2 == t1.size() && io == n)
        {
            int iue = 0, len = t1.size();
            for (int i = 1; i <= n; ++i)
            {
                if (qa[i] <= cna && ha[i] <= len - cna - 1 && qa1[i] <= cnb && ha1[i] <= len - cnb - 1) ++iue;
            }
            cout << iue << endl;
        }
        else if (t1.size() != t2.size()) cout << "0\n";
        else
        {
            cnt = 0;
            for (int i = 0; i < t1.size(); ++i)
            {
                for (int j = i + 1; j < t1.size(); ++j)
                {
                    string x = t1.substr(0, i + 1), y = t1.substr(i + 1, j - i), z = t1.substr(j + 1);
                    string xt = t2.substr(0, i + 1), yt = t2.substr(i + 1, j - i), zt = t2.substr(j + 1);
                    if (vis[y] && yt == s2[vis[y]] && x == xt && zt == z)
                    {
                        ++cnt;
                     //   cout << x << " " << y << " " << z << " " << xt << " " << yt << zt << endl;
                    }
                }
            }
            if (vis[t1] && s2[vis[t1]] == t2) ++cnt;
            cout << cnt << endl;
        }
    }
    return 0;
}
