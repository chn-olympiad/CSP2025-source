#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int t;
int n;
struct p { int x, y, z; } a[100005];
int pmax(p u) { return max({ u.x, u.y, u.z }); }
int pmax2(p u)
{
    int mx = pmax(u);
    if (mx == u.x) return max(u.y, u.z);
    if (mx == u.y) return max(u.x, u.z);
    return max(u.x, u.y);
}
bool cmp(p u, p v)
{
    if (pmax(u) - pmax2(u) < pmax(v) - pmax2(v)) return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
        vector<p> v[3];
        for (int i = 1; i <= n; i++)
        {
            int mx = pmax(a[i]);
            if (mx == a[i].x) v[0].push_back(a[i]);
            else if (mx == a[i].y) v[1].push_back(a[i]);
            else v[2].push_back(a[i]);
        }
        LL ans = 0;
        for (auto i : v[0]) ans += pmax(i);
        for (auto i : v[1]) ans += pmax(i);
        for (auto i : v[2]) ans += pmax(i);
        if (max({ v[0].size(), v[1].size(), v[2].size() }) * 2 > n)
        {
            vector<p> u;
            int mxs = max({ v[0].size(), v[1].size(), v[2].size() });
            if (mxs == v[0].size()) u = v[0];
            else if (mxs == v[1].size()) u = v[1];
            else u = v[2];
            sort(u.begin(), u.end(), cmp);
            for (int i = 0; u.size() - i > n / 2; i++) ans -= pmax(u[i]), ans += pmax2(u[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
