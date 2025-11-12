#include <bits/stdc++.h>
#include <bits/extc++.h>
#define ll long long
using namespace std;
const int mod1 = 1e9 + 7, mod2 = 19260817, maxn = 2e5 + 5, bas1 = 13331, bas2 = 1331, maxm = 2.5e6 + 5, blk = 1000;
unordered_map<ll, int> id;
unordered_map<ll, vector<int>> L[maxn], R[maxn];
int hs1[maxm], pw1[maxm], cnt, n, q, hs2[maxm], pw2[maxm];
char mp1[maxm * 2], mp2[maxm * 2];
int gt1(int l, int r) { return (hs1[r] - 1ll * hs1[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1; }
int gt2(int l, int r) { return (hs2[r] - 1ll * hs2[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2; }
ll mkp1(ll x, ll y)
{
    return x * mod1 + y;
}
ll mkp2(ll x, ll y)
{
    return x * mod2 + y;
}
ll mkp(ll x, ll y)
{
    return (x % mod1 * mod1 + y);
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    pw1[0] = 1;
    for (int i = 1; i <= 2500000; i++)
        pw1[i] = 1ll * pw1[i - 1] * bas1 % mod1;
    pw2[0] = 1;
    for (int i = 1; i <= 2500000; i++)
        pw2[i] = 1ll * pw2[i - 1] * bas2 % mod2;
    for (int i = 1; i <= n; i++)
    {
        cin >> (mp1 + 1) >> (mp2 + 1);
        int x = strlen(mp1 + 1);
        int l = 1, r = x;
        while (l <= x)
            if (mp1[l] != mp2[l]) break;
            else l++;
        if (l == x + 1)
            continue;
        while (r >= 1)
            if (mp1[r] != mp2[r]) break;
            else r--;
        for (int j = 1; j <= x; j++)
            hs1[j] = (1ll * hs1[j - 1]  * bas1 + mp1[j]) % mod1;
        for (int j = 1; j <= x; j++)
            hs2[j] = (1ll * hs2[j - 1]  * bas2 + mp1[j]) % mod2;
        int xx1, yy1, xx2, yy2;
        if (l == 1) xx1 = 0;
        else xx1 = gt1(1, l - 1);
        if (r == x) yy1 = 0;
        else yy1 = gt1(r + 1, x);
        int zz1 = gt1(l, r);
        if (l == 1) xx2 = 0;
        else xx2 = gt2(1, l - 1);
        if (r == x) yy2 = 0;
        else yy2 = gt2(r + 1, x);
        int zz2 = gt2(l, r);
        for (int j = 1; j <= x; j++)
            hs1[j] = (1ll * hs1[j - 1]  * bas1 + mp2[j]) % mod1;
        for (int j = 1; j <= x; j++)
            hs2[j] = (1ll * hs2[j - 1]  * bas2 + mp2[j]) % mod2;
        int kk1 = gt1(l, r), kk2 = gt2(l, r);
        int &d = id[mkp(mkp1(zz1, kk1), mkp2(zz2, kk2))];
        if (!d) d = ++cnt;
        L[d][mkp(xx1, xx2)].emplace_back(i);
        R[d][mkp(yy1, yy2)].emplace_back(i);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> (mp1 + 1) >> (mp2 + 1);
        int n1 = strlen(mp1 + 1), n2 = strlen(mp2 + 1);
        if (n1 != n2) cout << "0\n";
        else
        {
            int x = n1;
            int l = 1, r = x;
            while (l <= x)
                if (mp1[l] != mp2[l]) break;
                else l++;
            while (r >= 1)
                if (mp1[r] != mp2[r]) break;
                else r--;
            for (int j = 1; j <= x; j++)
                hs1[j] = (1ll * hs1[j - 1]  * bas1 + mp1[j]) % mod1;
            for (int j = 1; j <= x; j++)
                hs2[j] = (1ll * hs2[j - 1]  * bas2 + mp1[j]) % mod2;
            vector<ll> v1, v2;
            v1.emplace_back(0), v2.emplace_back(0);
            for (int i = l - 1; i >= 1; i--)
                v1.emplace_back(mkp(gt1(i, l - 1), gt2(i, l - 1)));
            for (int i = r + 1; i <= x; i++)
                v2.emplace_back(mkp(gt1(r + 1, i), gt2(r + 1, i)));
            vector<int> v3, v4;
            int ans = 0, d11 = gt1(l, r), d12 = gt2(l, r);
            for (int j = 1; j <= x; j++)
                hs1[j] = (1ll * hs1[j - 1]  * bas1 + mp2[j]) % mod1;
            for (int j = 1; j <= x; j++)
                hs2[j] = (1ll * hs2[j - 1]  * bas2 + mp2[j]) % mod2;
            int d = id[mkp(mkp1(d11, gt1(l, r)), mkp2(d12, gt2(l, r)))];
            for (ll i : v1)
                if (L[d].count(i))
                    for (int j : L[d][i])
                        v3.emplace_back(j);
            for (ll i : v2)
                if (R[d].count(i))
                    for (int j : R[d][i])
                        v4.emplace_back(j);
            if (!v3.size() || !v4.size())
            {
                cout << 0 << '\n';
                continue;
            }
            sort(v3.begin(), v3.end());
            sort(v4.begin(), v4.end());
            vector<pair<int, int>> v5, v6;
            int sum = 1;
            for (int i = 1; i < v3.size(); i++)
            {
                if (v3[i] == v3[i - 1]) sum++;
                else v5.emplace_back(v3[i - 1], sum), sum = 1;
            }
            v5.emplace_back(v3.back(), sum);
            sum = 1;
            for (int i = 1; i < v4.size(); i++)
            {
                if (v4[i] == v4[i - 1]) sum++;
                else v6.emplace_back(v4[i - 1], sum), sum = 1;
            }
            v6.emplace_back(v4.back(), sum);
            for (int l = 0, r = 0; l < v5.size() && r < v6.size(); )
            {
                if (v5[l].first == v6[r].first)
                    ans += v5[l].second * v6[r].second, l++, r++;
                else if (v5[l].first < v6[r].first) l++;
                else r++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}