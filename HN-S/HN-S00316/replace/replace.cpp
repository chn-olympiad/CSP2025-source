#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5, L = 5e6 + 5;
int n, q;
string s1[N], s2[N], t1, t2;

int nxt[L * 2];
vector<int> ans;

vector<int> kmp(string s, string t)
{
    ans.clear();
    int len1 = s.size(), len2 = t.size();
    t += '#' + s;
    // cout << t << '\n';
    for (int i = 1, j = 0; i < len1 + len2 + 1; i++)
    {
        // cout << i << '\n';
        while (j > 0 && t[i] != t[j]) j = nxt[j - 1];
        if (t[i] == t[j]) j++;
        nxt[i] = j;
        // cout << nxt[i] << '\n';
        if (nxt[i] == len2) ans.push_back(i - len2 * 2);
    }
    return ans;
}

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
    }
    while (q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            vector<int> tmp = kmp(t1, s1[i]);
            for (auto x : tmp)
            {
                if (t1.substr(0, x) + s2[i] + t1.substr(x + s1[i].size(), t1.size() - (x + s1[i].size()) + 1) == t2) cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}