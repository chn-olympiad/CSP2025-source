// mikumiku wooh wooh

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned ui;
typedef unsigned long long ull;

const int MAXN = 200010, MAXL = 5500010;
const ll MOD = 998244853ll;
// seed = 233

int tt = 1;

int n, q;
string s[2][MAXN], t[2];
int m = 0;
ll hsh[MAXN];
ull hsh2[MAXN];
map<pair<ll, ull>, int> id;
int rc = 0, pre[MAXN], suf[MAXN];
int to[MAXL][26];
int c0[MAXL];
int tag[MAXN], idx = 0;
vector<int> ve[MAXL];

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[0][i] >> s[1][i];
        int p1 = -1, p2 = -1;
        int si = s[0][i].size();
        for (int j = 0; j < si; j++) if (s[0][i][j] != s[1][i][j]) {
            if (p1 == -1) p1 = j;
            p2 = j;
        }
        if (p2 == -1) continue;
        ll h1 = 0;
        ull h2 = 0;
        for (int j = p1; j <= p2; j++) {
            h1 *= 233, h1 %= MOD;
            h1 += s[0][i][j] - 'a' + 1, h1 = (h1 >= MOD? h1 - MOD: h1);
            h1 *= 233, h1 %= MOD;
            h1 += s[1][i][j] - 'a' + 1, h1 = (h1 >= MOD? h1 - MOD: h1);
            h2 *= 233ull, h2 += ull(s[0][i][j] - 'a' + 1);
            h2 *= 233ull, h2 += ull(s[1][i][j] - 'a' + 1);
        }
        if (!id[make_pair(h1, h2)]) id[make_pair(h1, h2)] = ++rc, pre[rc] = ++m, suf[rc] = ++m;
        int r = id[make_pair(h1, h2)];
        // cout << r << "\n";
        int u = pre[r];
        for (int j = p1 - 1; j >= 0; j--) u = to[u][s[0][i][j] - 'a']? to[u][s[0][i][j] - 'a']: to[u][s[0][i][j] - 'a'] = ++m;
        ve[u].push_back(i), c0[u] += (p2 + 1 == si);
        u = suf[r];
        for (int j = p2 + 1; j < si; j++) u = to[u][s[0][i][j] - 'a']? to[u][s[0][i][j] - 'a']: to[u][s[0][i][j] - 'a'] = ++m;
        ve[u].push_back(i), c0[u] += (p1 == 0);
    }
    while (q--)
    {
        idx++;
        cin >> t[0] >> t[1];
        int p1 = -1, p2 = -1;
        int si = t[0].size();
        if (si != t[1].size())
        {
            cout << "0\n";
            continue;
        }
        for (int j = 0; j < si; j++) if (t[0][j] != t[1][j]) {
            if (p1 == -1) p1 = j;
            p2 = j;
        }
        ll h1 = 0;
        ull h2 = 0;
        for (int j = p1; j <= p2; j++) {
            h1 *= 233, h1 %= MOD;
            h1 += t[0][j] - 'a' + 1, h1 = (h1 >= MOD? h1 - MOD: h1);
            h1 *= 233, h1 %= MOD;
            h1 += t[1][j] - 'a' + 1, h1 = (h1 >= MOD? h1 - MOD: h1);
            h2 *= 233ull, h2 += ull(t[0][j] - 'a' + 1);
            h2 *= 233ull, h2 += ull(t[1][j] - 'a' + 1);
        }
        int x = id[make_pair(h1, h2)];
        if (!x)
        {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        int u = pre[x];
        // cout << x << "\n";
        // cout << "debug: " << ve[u].size() << "\n"; 
        for (auto v: ve[u]) tag[v] = idx;
        for (int j = p1 - 1; j >= 0; j--) {
            u = to[u][t[0][j] - 'a'];
            if (!u) break;
            for (auto v: ve[u]) tag[v] = idx;
        }
        u = suf[x];
        for (auto v: ve[u]) if (tag[v] == idx) ans++;
        // cout << ans << "\n";
        // cout << p1 << " " << p2 << "\n";
        for (int j = p2 + 1; j < si; j++) {
            u = to[u][t[0][j] - 'a'];
            // cout << "now: " << u << ve[u].size() << "\n";
            if (!u) break;
            for (auto v: ve[u]) if (tag[v] == idx) ans++;
        }
        cout << ans << "\n";
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // scanf("%d", &tt);
    while (tt--) solve();    
    return 0;
}