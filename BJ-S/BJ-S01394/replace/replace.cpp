#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool fd(string s, int pos, string t)
{
    for (int i = pos; i <= pos + t.size() - 1; i ++)
        if (s[i] != t[i - pos]) return 0;
    return 1;
}
string s[N][3];
int siz[N];
void solve(int n, int T)
{
    while (T --)
    {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << "\n";
            continue;
        }
        vector<int> pos;
        int m = t1.size(), cnt = 0;
        for (int i = 0; i < m; i ++)
            if (t1[i] != t2[i])
                pos.push_back(i), cnt ++;
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (siz[i] < pos[cnt - 1] - pos[0] + 1)
                continue;
            for (int j = max(0, pos[cnt - 1] - siz[i] + 1); j <= min(m - 1, pos[0]); j ++)
            {
                if (j + siz[i] - 1 >= m) break;
                if (fd(t1, j, s[i][1]) && fd(t2, j, s[i][2]))
                    ans ++;
            }
        }
        cout << ans << "\n";
    }
}
struct node
{
    int l, z, r;
} a[N];
int getb(string S)
{
    for (int i = 0; i < S.size(); i ++)
        if (S[i] == 'b')
            return i;
}
vector<int> Z[N * 2];
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
    {
        cin >> s[i][1] >> s[i][2];
        siz[i] = s[i][1].size();
    }
    if ((n <= 1000 && T <= 1000) || T == 1)
    {
        solve(n, T);
        return 0;
    }
    for (int i = 1; i <= n; i ++)
    {
        int pos1 = getb(s[i][1]);
        int pos2 = getb(s[i][2]);
        a[i] = {min(pos1, pos2) - 1, pos2 - pos1, siz[i] - max(pos1, pos2)};
        Z[pos2 - pos1 + N].push_back(i);
    }
    while (T --)
    {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << "\n";
            continue;
        }
        int m = t1.size();
        int pos1 = getb(t1), pos2 = getb(t2);
        int L = min(pos1, pos2) - 1;
        int R = m - max(pos1, pos2);
        int ans = 0;
        for (auto pos : Z[pos2 - pos1 + N])
            if (a[pos].l <= L && a[pos].r <= R)
                ans ++;
        cout << ans << "\n";
    }

    return 0;
}