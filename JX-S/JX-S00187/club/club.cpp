#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 2e9;
int t, n, a[N][5], c[N], d[N], e[N], ans;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        memset(a, 0, sizeof a);
        memset(c, 0, sizeof c);
        memset(d, 0, sizeof d);
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            int maxid = 1, midid = 1;
            for(int j = 2; j <= 3; j++) maxid = (a[i][j] > a[i][maxid] ? j : maxid);
            c[i] = maxid;
            for(int j = 1; j <= 3; j++)
            {
                if(j == maxid) continue;
                if(a[i][j] > d[i]) d[i] = max(d[i], a[i][j]), midid = j;
            }
            d[i] = a[i][maxid] - d[i];
            e[i] = midid;
        }
        ans = 0;
        int cnt[5] = {0, 0, 0, 0, 0};
        for(int i = 1; i <= n; i++) ans += a[i][c[i]], cnt[c[i]]++;
        int maxn = max(max(cnt[1], cnt[2]), cnt[3]);
        int mxid = (cnt[1] == maxn ? 1 : (cnt[2] == maxn ? 2 : 3));
        if(maxn <= n / 2)
        {
            cout << ans << '\n';
            continue;
        }
        for(int i = 1; i <= n; i++) if(c[i] != mxid) d[i] = INF;
        sort(d + 1, d + n + 1);
        for(int i = 1; i <= maxn - n / 2; i++) ans -= d[i];
        cout << ans << '\n';
    }
    return 0;
}
