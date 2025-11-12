#include <bits/stdc++.h>
using namespace std;
// #define int long long

int n, q, pi1[5000010], pi2[5000010], l[200010], r[200010], ans[200010];
string s, t;
string ss[200010], tt[200010], sss[200010], ttt[200010];

void insert()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> sss[i] >> ttt[i];
    for(int i = 1; i <= q; i++)
    {
        cin >> ss[i] >> tt[i];
        l[i] = -1, r[i] = 0;
        if(ss[i].size() != tt[i].size())
            continue;
        for(int j = 0; j < ss[i].size(); j++)
        {
            if(ss[i][j] != tt[i][j])
            {
                if(l[i] == -1)
                    l[i] = j;
                r[i] = j;
            }
        }
    }
}

int peis(int x, char c)
{
    if(s[x + 1] == c)
        return x + 1;
    return (x == 0 ? 0 : peis(pi1[x], c));
}

int peit(int x, char c)
{
    if(t[x + 1] == c)
        return x + 1;
    return (x == 0 ? 0 : peis(pi2[x], c));
}

void work()
{
    insert();
    for(int jjj = 1; jjj <= n; jjj++)
    {
        s = sss[jjj], t = ttt[jjj];
        int nn = s.size();
        s = " " + s;
        t = " " + t;
        for(int i = 2; i <= nn; i++)
            pi1[i] = peis(pi1[i - 1], s[i]);
        for(int i = 2; i <= nn; i++)
            pi2[i] = peit(pi2[i - 1], t[i]);
        for(int i = 1; i <= q; i++)
        {
            int p1 = 0, p2 = 0;
            if(ss[i].size() != tt[i].size())
                continue;
            for(int j = 0; j < ss[i].size(); j++)
            {
                while(s[p1 + 1] != ss[i][j] && p1 != 0)
                    p1 = pi1[p1];
                if(s[p1 + 1] == ss[i][j])
                    p1++;
                while(t[p2 + 1] != tt[i][j] && p2 != 0)
                    p2 = pi2[p2];
                if(t[p2 + 1] == tt[i][j])
                    p2++;
                // cout << jjj << " " << i << " " << j << " " << p1 << " " << p2 << '\n';
                if(p1 == nn && p2 == nn)
                {
                    if(j >= r[i] && j - nn + 1 <= l[i])
                    {
                        ans[i]++;
                        break;
                    }
                }
            }
        }
        // cout << jjj << '\n';
    }
    for(int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

signed main()
{
    freopen("replace.out", "w", stdout);
    freopen("replace.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}