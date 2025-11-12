
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int nr = 2e5 + 10;
const int sr = 5e6 + 10;
int n, q, L1;
string s1[nr], s2[nr];

namespace _subtaska
{
    const ll p = 998244353;
    const ll base = 137;
    ll pw[sr], iv[sr];
    vector<ll> hsh[2][nr];
    ll qpow(ll x, int k)
    {
        ll res = 1;
        while (k)
        {
            if (k & 1) res *= x, res %= p;
            x *= x, x %= p;
            k >>= 1;
        }
        return res;
    }
    ll Hash(int type, int k, int l, int r)
    {
        int lst = l == 0 ? 0 : hsh[type][k][l - 1];
        return (hsh[type][k][r] - lst) * iv[l] % p;
    }
    void init()
    {
        pw[0] = 1, iv[0] = 1;
        for (int i = 1; i < L1; i++) pw[i] = pw[i - 1] * base % p, iv[i] = qpow(pw[i], p - 2);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < s1[i].size(); j++)
            {
                int lst = j == 0 ? 0 : hsh[0][i][j - 1];
                hsh[0][i].push_back((lst + pw[j] * (s1[i][j] - 'a') % p) % p);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < s2[i].size(); j++)
            {
                int lst = j == 0 ? 0 : hsh[1][i][j - 1];
                hsh[1][i].push_back((lst + pw[j] * (s2[i][j] - 'a') % p) % p);
            }
        }
    }
    void solve()
    {
        init();
        for (int i = 1; i <= q; i++)
        {
            string t1, t2;
            cin >> t1 >> t2;
            if (t1.size() != t2.size())
            {
                cout << 0 << '\n';
                continue;
            }
            hsh[0][0].clear(), hsh[1][0].clear();
            for (int j = 0; j < t1.size(); j++)
            {
                int lst = j == 0 ? 0 : hsh[0][0][j - 1];
                hsh[0][0].push_back((lst + pw[j] * (t1[j] - 'a') % p) % p);
            }
            for (int j = 0; j < t2.size(); j++)
            {
                int lst = j == 0 ? 0 : hsh[1][0][j - 1];
                hsh[1][0].push_back((lst + pw[j] * (t2[j] - 'a') % p) % p);
            }
            int st = 1e9, ed = 0;
            for (int j = 0; j < t1.size(); j++) if (t1[j] != t2[j]) st = min(st, j), ed = max(ed, j);
            int len = ed - st + 1, cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                for (int k = 0; k + len - 1 < s1[j].size(); k++)
                {
                    if (Hash(0, j, k, k + len - 1) == Hash(0, 0, st, ed) && Hash(1, j, k, k + len - 1) == Hash(1, 0, st, ed))
                    {
                        int ST = st - k, ED = ST + s1[j].size() - 1;
                        if (ST < 0 || ED >= t2.size()) continue;
                        if (Hash(1, j, 0, s2[j].size() - 1) == Hash(1, 0, ST, ED)) cnt++;
                    }
                }
            }
            cout << cnt << '\n';
        }
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i], L1 += s1[i].size();
    if (L1 <= 2000 || q == 1) _subtaska::solve();
    return 0;
}
