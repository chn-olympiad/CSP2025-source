#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <ctime>
#include <random>
#include <chrono>

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef unsigned int uint;

using namespace std;

const int MAXN = 2e5 + 10, MAXM = 5e6 + 10;
const char E = 'z' + 1;

const int B = 13331, mod = 1e9 + 9;
const int B2 = 426337, mod2 = 998244853;

int n, q, m, ans[MAXN];
string s1[MAXN], s2[MAXN], t1[MAXN], t2[MAXN];
string s3[MAXN], t3[MAXN];

map <array <ull, 4>, int> idx;
vector <int> vec[MAXN], qry[MAXN];

int tr[MAXM][27], fail[MAXM], ed[MAXM], tot, rk[MAXM], clk;
inline void build()
{
    queue <int> q;
    clk = 0;
    for (int i = 0; i < 27; i++)
        if (tr[0][i]) q.push(tr[0][i]);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        rk[++clk] = u;
        for (int i = 0; i < 27; i++)
            if (tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
            else tr[u][i] = tr[fail[u]][i];
    }
    for (int i = 1; i <= clk; i++) ed[rk[i]] += ed[fail[rk[i]]];
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
        if (s1[i] == s2[i]) continue;
        int pre = 0, suf = s1[i].size() - 1;
        while (pre < s1[i].size() && s1[i][pre] == s2[i][pre]) pre++;
        while (suf >= 0 && s1[i][suf] == s2[i][suf]) suf--;
        s3[i] = s1[i].substr(0, pre) + E + s1[i].substr(suf + 1, s1[i].size() - suf - 1);
        ull h1 = 0, h2 = 0;
        for (int j = pre; j <= suf; j++) h1 = (h1 * B + s1[i][j]) % mod;
        for (int j = pre; j <= suf; j++) h2 = (h2 * B + s2[i][j]) % mod;
        ull h3 = 0, h4 = 0;
        for (int j = pre; j <= suf; j++) h3 = (h3 * B2 + s1[i][j]) % mod2;
        for (int j = pre; j <= suf; j++) h4 = (h4 * B2 + s2[i][j]) % mod2;
        auto cur = array <ull, 4>{h1, h2, h3, h4};
        if (idx.find(cur) == idx.end()) idx[cur] = ++m;
        vec[idx[cur]].push_back(i);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t1[i] >> t2[i];
        if (t1[i].size() != t2[i].size()) continue;
        int pre = 0, suf = t1[i].size() - 1;
        while (pre < t1[i].size() && t1[i][pre] == t2[i][pre]) pre++;
        while (suf >= 0 && t1[i][suf] == t2[i][suf]) suf--;
        t3[i] = t1[i].substr(0, pre) + E + t1[i].substr(suf + 1, t1[i].size() - suf - 1);
        ull h1 = 0, h2 = 0;
        for (int j = pre; j <= suf; j++) h1 = (h1 * B + t1[i][j]) % mod;
        for (int j = pre; j <= suf; j++) h2 = (h2 * B + t2[i][j]) % mod;
        ull h3 = 0, h4 = 0;
        for (int j = pre; j <= suf; j++) h3 = (h3 * B2 + t1[i][j]) % mod2;
        for (int j = pre; j <= suf; j++) h4 = (h4 * B2 + t2[i][j]) % mod2;
        auto cur = array <ull, 4>{h1, h2, h3, h4};
        if (idx.find(cur) == idx.end()) continue;
        qry[idx[cur]].push_back(i);
    }
    for (int id = 1; id <= m; id++)
    {
        for (int i = 0; i <= tot; i++)
        {
            for (int j = 0; j < 27; j++) tr[i][j] = 0;
            fail[i] = ed[i] = 0;
        }
        tot = 0;
        for (auto k : vec[id])
        {
            int cur = 0;
            for (int i = 0; i < s3[k].size(); i++)
            {
                int c = s3[k][i] - 'a';
                if (!tr[cur][c]) tr[cur][c] = ++tot;
                cur = tr[cur][c];
            }
            ed[cur]++;
        }
        build();
        for (auto k : qry[id])
        {
            int cur = 0, sum = 0;
            for (int i = 0; i < t3[k].size(); i++)
            {
                int c = t3[k][i] - 'a';
                cur = tr[cur][c];
                sum += ed[cur];
            }
            ans[k] = sum;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}