#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e4 + 5, MAXK = 15;
int n, m, k, ans = LLONG_MAX, c1, c2, c3, c[MAXK], a[MAXK][MAXN], fa[MAXN];
struct rd {int s, e, w;};
vector<rd> r, rb;
bool ct[MAXK];
bool cmp(rd a, rd b) {return a.w < b.w;}
int fd(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = fd(fa[x]);
}
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> c1 >> c2 >> c3;
        r.push_back((rd){c1, c2, c3});
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < pow(2, k); i++)
    {
        memset(ct, 0, sizeof(ct));
        rb = r;
        int sum = 0;
        for (int j = 1; j <= k; j++) if (i & (1 << (j - 1)))
        {
            ct[j] = 1;
            sum += c[j];
            for (int l = 1; l <= n; l++) rb.push_back((rd){j + n, l, a[j][l]});
        }
        for (int i = 1; i <= n + k; i++) fa[i] = i;
        sort(rb.begin(), rb.end(), cmp);
        for (auto &j : rb)
            if (fd(j.s) != fd(j.e)) fa[fd(j.s)] = j.e, sum += j.w;
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}