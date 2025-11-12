#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct node
{
    int val, id;
    bool operator < (const node& x, const node& y) const
    {
        if (x.val != y.val) return x.val < y.val;
        return x.id < y.id;
    }
} a[5][N];

int n, cnt[5];
long long ans;

void sovle()
{
    cin >> n; ans = 0;
    for (int i = 1, a1, a2, a3; i <= n; ++i)
    {
        cin >> a1 >> a2 >> a3;
        ans += a1;
        a[2][i] = {a2 - a1, i};
        a[3][i] = {a3 - a1, i};
    }
    sort(a[2] + 1, a[2] + n + 1);
    for (int i = 1; i <= n / 2; ++i)
        ans += a[2][i];
    cout << ans << '\n';
    return;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
