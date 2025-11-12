#include <iostream>
#include <queue>
#include <bitset>

using namespace std;
using ll = long long;

const int maxn = 1e5 + 100;
ll n, t, ans;
bitset<maxn> used;
ll s[maxn][3], c[maxn];
priority_queue<ll> q[3];
void solve()
{
    used.reset(), ans = 0;

    ll cnt[3] = {0, 0, 0};
    q[0] = q[1] = q[2] = priority_queue<ll>();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1] >> s[i][2];
        if (s[i][0] >= s[i][1] && s[i][0] >= s[i][2])
            c[i] = 0, q[0].push(max(s[i][1] - s[i][0], s[i][2] - s[i][0]));
        else if (s[i][1] >= s[i][2] && s[i][0] >= s[i][0])
            c[i] = 1, q[1].push(max(s[i][0] - s[i][1], s[i][2] - s[i][1]));
        else
            c[i] = 2, q[2].push(max(s[i][1] - s[i][2], s[i][0] - s[i][2]));
        ans += s[i][c[i]];
        cnt[c[i]]++;
    }
    if (cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2)
    {
        int p;
        for (int i = 0; i < 3; i++)
            if (cnt[i] > n / 2)
                p = i;
        while (cnt[p] > n / 2)
            ans += q[p].top(), q[p].pop(), cnt[p]--;
    }
    cout << ans << endl;

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}