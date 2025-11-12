#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, q;
map<pair<string, string>, int> mp2;
map<pair<string,string>, vector<pair<string, int> > > mp;
string a, b, s[maxn][2];
int main ()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i][0] >> s[i][1];
            string t = s[i][0];
            if (mp2[make_pair(s[i][0],s[i][1])]) continue;
            mp2[make_pair(s[i][0], s[i][1])] = 1;
            int l = 0, r = s[i][0].size();
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (s[i][0].substr(0, mid) == s[i][1].substr(0, mid)) l = mid;
                else r = mid - 1;
            }
            s[i][0] = s[i][0].substr(l);
            s[i][1] = s[i][1].substr(l);
            int t1 = l;
            l = 0;
            r = s[i][0].size();
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (s[i][0].substr(s[i][0].size() - mid) == s[i][1].substr(s[i][1].size() - mid)) l = mid;
                else r = mid - 1;
            }
            s[i][0] = s[i][0].substr(0, s[i][0].size() - l - 1);
            s[i][1] = s[i][1].substr(0, s[i][1].size() - l - 1);
            mp[make_pair(s[i][0], s[i][1])].push_back(make_pair(t, t1));
        }
        while (q--)
        {
            cin >> a >> b;
            string t1 = a;
            int l = 0, r = a.size();
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (a.substr(0, mid) == b.substr(0, mid)) l = mid;
                else r = mid - 1;
            }
            a = a.substr(l);
            b = b.substr(l);
            int t2 = l;
            l = 0;
            r = a.size();
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (a.substr(a.size() - mid) == b.substr(b.size() - mid)) l = mid;
                else r = mid - 1;
            }
            a = a.substr(0, a.size() - l - 1);
            b = b.substr(0, b.size() - l - 1);
            vector<pair<string, int> > v;
            v = mp[make_pair(a, b)];
            int ans = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (t2 >= v[i].second && t2 - v[i].second + v[i].first.size() -1  < t1.size() && v[i].first == t1.substr(t2 -v[i].second, v[i].first.size())) ans++;
            }cout << ans << endl;
        }
    return 0;
}
