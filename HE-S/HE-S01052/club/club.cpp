#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

using pii = pair <int, int>;

#define fi first
#define se second

priority_queue <pii> q;
int a[N][4], cnt[4], whmax[N], b[N << 1];

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        for (int i = 1; i <= 3; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= 3; j++) cin >> a[i][j];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int maxn = -1;
            for (int j = 1; j <= 3; j++)
            {
                if (a[i][j] > maxn) maxn = a[i][j], whmax[i] = j;
            }
            ans += maxn;
            ++cnt[whmax[i]];
        }
        int t = 0, tot = 0, c = 0;
        for (int i = 1; i <= 3; i++) if (cnt[i] > n / 2) t = i, tot = cnt[i] - n / 2;
        for (int i = 1; i <= n; i++)
        {
            if (whmax[i] != t) continue;
            int tmp = -0x3f3f3f3f;
            if (t == 1) tmp = a[i][2] - a[i][1], tmp = max(tmp, a[i][3] - a[i][1]);
            if (t == 2) tmp = a[i][1] - a[i][2], tmp = max(tmp, a[i][3] - a[i][2]);
            if (t == 3) tmp = a[i][2] - a[i][3], tmp = max(tmp, a[i][1] - a[i][3]);
            b[++c] = tmp;
        }
        sort(b + 1, b + 1 + c);
        for (int i = c; i >= c - tot + 1; i--)
        {
            ans += b[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
