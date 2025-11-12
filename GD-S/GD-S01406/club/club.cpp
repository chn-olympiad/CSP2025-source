#include <iostream>
#include <algorithm>
#define maxn 100005
#define maxn2 50005
using namespace std;

int t, n, n2, mx, m, ans, a[3][maxn], b[maxn], c[maxn], d[maxn], cnt[3];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    for(cin >> t; t--; )
    {
        cin >> n, n2 = n >> 1;
        ans = m = cnt[0] = cnt[1] = cnt[2] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < 3; j++)
                cin >> a[j][i];
            if(a[0][i] >= a[1][i] && a[0][i] >= a[2][i])
                cnt[0]++, ans += a[0][i], b[i] = 0, c[i] = min(a[0][i] - a[1][i], a[0][i] - a[2][i]);
            else if(a[1][i] >= a[0][i] && a[1][i] >= a[2][i])
                cnt[1]++, ans += a[1][i], b[i] = 1, c[i] = min(a[1][i] - a[0][i], a[1][i] - a[2][i]);
            else
                cnt[2]++, ans += a[2][i], b[i] = 2, c[i] = min(a[2][i] - a[0][i], a[2][i] - a[1][i]);
        }
        //cout << "debug:" << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << n2 << endl;
        if(cnt[0] > n2)
            mx = 0;
        else if(cnt[1] > n2)
            mx = 1;
        else if(cnt[2] > n2)
            mx = 2;
        else
        {
            cout /*<< "ans:"*/ << ans << endl;
            continue;
        }
        //cout << "debug:" << ans << endl;
        for(int i = 1; i <= n; i++)
        {
            if(b[i] == mx)
                d[++m] = c[i];
            //printf("debug:%d%schoose%d c%d\n", i, i == mx ? "(!)" : "", b[i], c[i]);
        }
        sort(d + 1, d + m + 1);
        for(int i = 1; i <= m - n2; i++)
            ans -= d[i];
        cout /*<< "ans:"*/ << ans << endl;
    }
    return 0;
}
