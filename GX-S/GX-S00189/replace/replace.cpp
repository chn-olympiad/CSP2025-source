#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[20010][3];
string t[20010][3];
//int border1[5000010], border2[5000010];
//int cnt[200010];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i][1] >> s[i][2];
    }
    for (int j = 1; j <= q; ++j)
    {
        cin >> t[j][1] >> t[j][2];
    }
    for (int i = 1; i <= q; ++i)
    {
        /*
        int szs = s[i][1].size();
        int j = 0;
        for (int ind = 1; ind < szs; ++ind)
        {
            while (j > 0 && s[i][1][j] != s[i][1][ind])
            {
                j = border1[j];
            }
            if (s[i][1][j] == s[i][1][ind])
            {
                ++j;
            }
            border1[ind] = j;
        }
        j = 0;
        for (int ind = 1; ind < szs; ++ind)
        {
            while (j > 0 && s[i][2][j] != s[i][2][ind])
            {
                j = border2[j];
            }
            if (s[i][2][j] == s[i][2][ind])
            {
                ++j;
            }
            border2[ind] = j;
        }
        for (int k = 1; k <= q; ++k)
        {

        }*/
        int lt1 = t[i][1].size(), lt2 = t[i][2].size();
        if (lt1 != lt2)
        {
            cout << 0 << '\n';
            continue;
        }
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            int ls = s[j][1].size();
            for (int ind = 0; ind <= lt1 - ls; ++ind)
            {
                if (t[i][1].substr(ind, ls) == s[j][1] && t[i][2].substr(ind, ls) == s[j][2] && t[i][1].substr(0, ind) == t[i][2].substr(0, ind) && t[i][1].substr(ind + ls) == t[i][2].substr(ind + ls))
                {
                    ++cnt;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
