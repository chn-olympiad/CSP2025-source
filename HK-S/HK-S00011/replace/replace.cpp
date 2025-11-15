#include <bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

const int MAXN = 2e5 + 7, p = 37;
string s[MAXN][2], t[MAXN][2], tmp[MAXN];
int sz[MAXN];

pair<int, int> get(string u, string v)
{
    int siz = u.size(), st = 0, ed = 0;
    for (int j = 0; j < siz; j++)
        if (u[j] != v[j]) {
            st = j;
            break;
        }
    for (int j = siz - 1; j >= 0; j--)
        if (u[j] != v[j]) {
            ed = j;
            break;
        }
    return make_pair(st, ed);
}

map<pair<string, string>, vector<pair<string, string>>> mp;

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1], sz[i] = s[i][0].size();
    for (int i = 1; i <= q; i++) cin >> t[i][0] >> t[i][1];
    for (int i = 1; i <= n; i++) {
        if (s[i][0] == s[i][1])
            continue;
        pair<int, int> seg = get(s[i][0], s[i][1]);
        // int val = 0;
        // for (int j = seg.first; j <= seg.second; j++)
        //     val = p * p * val + p * (s[i][0][j] - 'a') + (s[i][1][j] - 'a');
        string dam, lam;
        for (int j = seg.first; j <= seg.second; j++)
            dam += s[i][0][j], lam += s[i][1][j];
        string l, r;
        for (int j = seg.first - 1; j >= 0; j--) l += s[i][0][j];
        for (int j = seg.second + 1; j < sz[i]; j++) r += s[i][0][j];
        mp[make_pair(dam, lam)].push_back(make_pair(l, r));
    }
    for (int i = 1; i <= q; i++) {
        // int val = 0;
        pair<int, int> seg = get(t[i][0], t[i][1]);
        // for (int j = seg.first; j <= seg.second; j++)
        //     val = p * p * val + p * (t[i][0][j] - 'a') + (t[i][1][j] - 'a');
        string dam, lam;
        for (int j = seg.first; j <= seg.second; j++)
            dam += t[i][0][j], lam += t[i][1][j];
        string l, r;
        for (int j = seg.first - 1; j >= 0; j--) l += t[i][0][j];
        for (int j = seg.second + 1; j < sz[i]; j++) r += t[i][0][j];
        int cnt = 0;
        for (pair<string, string> j : mp[make_pair(dam, lam)]) {
            string ls = j.first, rs = j.second;
            if (l.size() < ls.size() || r.size() < rs.size()) continue;
            bool flag = true;
            for (int k = 0; k < ls.size(); k++)
                if (l[k] != ls[k]) {
                    flag = false;
                    break;
                }
            if (!flag) continue;
            for (int k = 0; k < rs.size(); k++)
                if (r[k] != rs[k]) {
                    flag = false;
                    break;
                }
            if (flag) cnt++;
        }
        cout << cnt << '\n';
        // if (i == 104) debug(cnt);
    }
}
