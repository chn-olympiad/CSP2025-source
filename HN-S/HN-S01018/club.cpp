#include <bits/stdc++.h>
#define N 100005
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmin(T &x, T y) {return (y < x) && (x = y, true);}
template <typename T> inline bool ckmax(T &x, T y) {return (x < y) && (x = y, true);}
int T, n, a[N][3], b[3][N];
inline void solve()
{
    cin >> n;
    int ct[3] = {0, 0, 0}, ans = 0;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        ans += max({a[i][0], a[i][1], a[i][2]});
        if (a[i][0] == max({a[i][0], a[i][1], a[i][2]})) ++ ct[0], b[0][ct[0]] = a[i][0] - max(a[i][1], a[i][2]);
        else if (a[i][1] >= a[i][2]) ++ ct[1], b[1][ct[1]] = a[i][1] - max(a[i][0], a[i][2]);
        else ++ ct[2], b[2][ct[2]] = a[i][2] - max(a[i][0], a[i][1]);
    }
    if (max({ct[0], ct[1], ct[2]}) <= n >> 1) cout << ans << '\n';
    else
    {
        int t;
        if (ct[0] > n >> 1) t = 0;
        else if (ct[1] > n >> 1) t = 1;
        else t = 2;
        sort(b[t] + 1, b[t] + ct[t] + 1);
        for (int i = 1; i <= ct[t] - (n >> 1); ++ i) ans -= b[t][i];
        cout << ans << '\n';
    }
}
signed main()
{
    file(club);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (cin >> T; T --; solve());
    return 0;
}