#include <bits/stdc++.h>
#define ll long long
using namespace std;
array<ll, 3> a[100005];
ll n, ans, cnt[3];
void solve()
{
    //
    memset(cnt, 0, sizeof cnt);
    ans = 0;
    //
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        array<pair<ll, ll>, 3> t;
        for (int j = 0; j < 3; j++)
        {
            cin >> t[j].first; t[j].second = j;
        }
        sort(t.begin(), t.end());
        ans += t[2].first;
        cnt[t[2].second]++;
        a[i] = {t[2].first, t[1].first, t[2].second};
    }
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] > n / 2)
        {
            // cout << ")" << i << '\n';
            vector<ll> v;
            for (int j = 1; j <= n; j++) if (a[j][2] == i) v.push_back(a[j][0] - a[j][1]);
            sort(v.begin(), v.end());
            // for (auto t : v) cout << t << ' ';
            for (int j = 0; j < cnt[i] - n / 2; j++) ans -= v[j];
            break ;
        }
    }
    cout << ans;
    //
    cout << '\n';
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}