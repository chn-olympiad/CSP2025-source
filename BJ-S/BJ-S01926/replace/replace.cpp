#include <bits/stdc++.h>
// #define int long long
#define vi vector<int>
#define pb push_back
using namespace std;
string merge(string s1, string s2)
{
    string s = "";
    for (int i = 0; i < s1.size(); i++) s.pb(s1[i]), s.pb(s2[i]);
    return s;
}
int now, t[5000010][30], fail[5000010], len[5000010], cnt[5000010], f[5000010][25];
vi v[5000010];
void ins(string s)
{
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int y = s[i] - 'a';
        if (!t[x][y]) t[x][y] = ++now;
        x = t[x][y];
        len[x] = i + 1;
    }
    cnt[x]++;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 26; i++) if (t[0][i]) q.push(t[0][i]);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (t[x][i])
            {
                fail[t[x][i]] = t[fail[x]][i];
                q.push(t[x][i]);
            }
            else t[x][i] = t[fail[x]][i];
        }
    }
}
int lg(int x)
{
    if (x == 0) return -1;
    return __lg(x);
}
void dfs(int x)
{
    cnt[x] += cnt[fail[x]], f[x][0] = fail[x];
    for (int i = 1; i <= lg(len[x]); i++) f[x][i] = f[f[x][i - 1]][i - 1];
    for (auto i : v[x]) dfs(i);
}
signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2) continue;
        ins(merge(s1, s2));
    }
    get_fail();
    for (int i = 1; i <= now; i++) v[fail[i]].pb(i);
    dfs(0);
    while (q--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int l = 1e9, r = -1e9;
        for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) l = min(l, i), r = max(r, i);
        string s = merge(s1, s2);
        int x = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            x = t[x][s[i] - 'a'];
            if ((i & 1) && i >= 2 * r + 1)
            {
                if (len[x] < i - 2 * l + 1) continue;
                int y = x;
                for (int j = lg(len[x]); j >= 0; j--) if (len[f[y][j]] >= i - 2 * l + 1) y = f[y][j];
                ans += cnt[x] - cnt[f[y][0]];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}