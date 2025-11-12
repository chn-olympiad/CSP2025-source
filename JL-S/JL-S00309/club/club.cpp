#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 100005;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int a[N][5], sum[5], n;
void work()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=3;j++)
            cin >> a[i][j];
    LL ans = 0;
    sum[1] = sum[2] = sum[3] = 0;
    const int lim = n / 2;
    priority_queue<LL> q[5];
    for (int i=1;i<=n;i++)
    {
        a[i][0] = -inf;
        int mx = 0, mx2 = 0;
        for (int j=1;j<=3;j++)
            if (a[i][j] > a[i][mx])
                mx2 = mx, mx = j;
            else if (a[i][j] > a[i][mx2])
                mx2 = j;
        if (sum[mx] < lim)
        {
            ans += a[i][mx];
            q[mx].push({a[i][mx2] - a[i][mx]});
            sum[mx] ++;
            continue;
        }
        if (q[mx].top() + a[i][mx] - a[i][mx2] > 0)
        {
            ans += q[mx].top() + a[i][mx];
            q[mx].pop();
            q[mx].push({a[i][mx2] - a[i][mx]});
        }
        else
            ans += a[i][mx2];
    }
    cout << ans << '\n';
    // 14:40 finished
}
int main()
{
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--)
        work();
    return 0;
}