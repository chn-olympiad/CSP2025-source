#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    pair<int, int> p[3];
} a[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q[3];
void solve()
{
    for (int i = 0; i < 3; i++) while (!q[i].empty()) q[i].pop();
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++) cin >> a[i].p[j].first, a[i].p[j].second = j;
        sort(a[i].p, a[i].p + 3, greater<>());
        if (q[a[i].p[0].second].size() < n / 2)
        {
            q[a[i].p[0].second].emplace(a[i].p[0].first - a[i].p[1].first, i);
            ans += a[i].p[0].first;
        }
        else
        {
            auto tmp = q[a[i].p[0].second].top();
            int sm = a[i].p[0].first - a[i].p[1].first;
            if (sm > tmp.first)
            {
                q[a[i].p[0].second].pop();
                ans -= tmp.first;
                q[a[i].p[0].second].emplace(sm, i);
                ans += a[i].p[0].first;
            }
            else
                ans += a[i].p[1].first;
        }
    }
    cout << ans << '\n';
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}