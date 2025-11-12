#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, a[MAXN][3], b[MAXN];
vector<pair<int, pair<int, int> > > p;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        int ans = 0, cnt[3] = {0, 0, 0};
        for (int i = 1; i <= n; i++)
        {
            int mx = max(a[i][0], max(a[i][1], a[i][2]));
            ans += mx;
            if (a[i][0] == mx)
                cnt[0]++, b[i] = 0;
            else if (a[i][1] == mx)
                cnt[1]++, b[i] = 1;
            else
                cnt[2]++, b[i] = 2;
        }
        if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
        {
            cout << ans << '\n';
            continue;
        }
        int pos;
        if (cnt[0] > n / 2)
            pos = 0;
        else if (cnt[1] > n / 2)
            pos = 1;
        else
            pos = 2;
        int nd = cnt[pos] - n / 2;
        p.clear();
        for (int i = 1; i <= n; i++)
        {
            if (pos == 0 && b[i] == 0)
            {
                int mx = max(a[i][1], a[i][2]);
                p.push_back({a[i][0] - mx, {i, (a[i][1] == mx ? 1 : 2)}});
            }
            if (pos == 1 && b[i] == 1)
            {
                int mx = max(a[i][0], a[i][2]);
                p.push_back({a[i][1] - mx, {i, (a[i][0] == mx ? 0 : 2)}});
            }
            if (pos == 2 && b[i] == 2)
            {
                int mx = max(a[i][0], a[i][1]);
                p.push_back({a[i][2] - mx, {i, (a[i][0] == mx ? 0 : 1)}});
            }
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < nd; i++)
        {
            cnt[pos]--;
            cnt[p[i].second.second]++;
            ans -= p[i].first;
            b[p[i].second.first] = p[i].second.second;
        }
        if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
        {
            cout << ans << '\n';
            continue;
        }
        int pos0;
        if (cnt[0] > n / 2)
            pos0 = 0;
        else if (cnt[1] > n / 2)
            pos0 = 1;
        else
            pos0 = 2;
        int nd0 = cnt[pos0] - n / 2;
        int tmp[3] = {0, 0, 0};
        tmp[pos] = 1;
        tmp[pos0] = 1;
        int pos1;
        if (tmp[0] == 0)
            pos1 = 0;
        else if (tmp[1] == 0)
            pos1 = 1;
        else
            pos1 = 2;
        p.clear();
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == pos0)
                p.push_back({a[i][pos0] - a[i][pos1], {0, 0}});
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < nd; i++)
            ans -= p[i].first;
        cout << ans << '\n';
    }
    return 0;
}
