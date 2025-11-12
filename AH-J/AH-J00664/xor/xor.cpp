#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll l, r;
};
node v[500005];
ll m;
ll f[500005], maxn[500005];
unordered_map<ll, ll> mp;
ll a[500005];
ll n, k;
ll ef(ll l, ll r, ll x)
{
    ll mid;
    while (l <= r)
    {
        mid = (r - l) / 2 + l;
        if (v[mid].r < x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) a[i] ^= a[i + 1];
    mp[0] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (mp.count(a[i] ^ k))
        {
            v[++m] = {i, mp[a[i] ^ k] - 1};
            // cout << i << ' ' << mp[a[i] ^ k] - 1 << '\n';
        }
        mp[a[i]] = i;
    }
    sort(v + 1, v + m + 1, [](node a, node b){return a.r < b.r;});
    for (int i = 1; i <= m; i++)
    {
        ll t = ef(1, i - 1, v[i].l);
        f[i] = maxn[t] + 1;
        maxn[i] = max(maxn[i - 1], f[i]);
    }
    cout << maxn[m];
    cout << '\n';
    return 0;
}
