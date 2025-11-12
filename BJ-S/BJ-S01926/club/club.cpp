#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
using namespace std;
int a[100010][3], pos[100010];
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        vi v[3];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            pos[i] = 0;
            for (int j = 0; j < 3; j++) if (a[i][j] > a[i][pos[i]]) pos[i] = j;
            ans += a[i][pos[i]];
            int w = 0;
            for (int j = 0; j < 3; j++) if (j != pos[i]) w = max(w, a[i][j]);
            v[pos[i]].pb(w - a[i][pos[i]]);
        }
        for (int i = 0; i < 3; i++)
        {
            sort(v[i].begin(), v[i].end());
            for (int j = n / 2; j < v[i].size(); j++) ans += v[i][j];
        }
        cout << ans << '\n';
    }
    return 0;
}