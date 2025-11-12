#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, T, p, tot, mx, mx_id, id;
ll sum[5], sm;
bool f[5], g[N];
pair<int, int> t[4];
struct node
{
    int s[5], mx = 0, id, mx_id = 0, cmx = 0, cmx_id = 0;
}a[N];
vector<int> v[5];
bool cmp1(node x, node y)//mx>
{
    if (x.mx == y.mx)
        return x.id < y.id;
    return x.mx > y.mx;
}
bool cmp2(node x, node y)
{
    if (x.cmx == y.cmx)
        return x.id < y.id;
    return x.cmx > y.cmx;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(sum, 0, sizeof(sum));
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= 3; i++)
            v[i].clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].s[1] >> a[i].s[2] >> a[i].s[3];
            t[1] = {1, a[i].s[1]}, t[2] = {2, a[i].s[2]}, t[3] = {3, a[i].s[3]};
            sort(t + 1, t + 4);
            a[i].mx = t[3].second, a[i].mx_id = t[3].first;
            a[i].cmx = t[2].second, a[i].cmx_id = t[2].first;
            a[i].id = i;
        }
        sort(a + 1, a + n + 1, cmp1);
        for (int i = 1; i <= n; i++)
        {
            p = a[i].mx_id;
            id = a[i].id;
            if (!f[p])
            {
                v[p].push_back(id);
                sum[p] += a[i].mx;
                g[id] = 1;
                if (v[p].size() * 2 >= n)
                    f[p] = 1;
                continue;
            }
        }
        sort(a + 1, a + n + 1, cmp2);
        for (int i = 1; i <= n; i++)
        {
            id = a[i].id;
            if (g[id] == 1)
                continue;
            p = a[i].cmx_id;
            v[p].push_back(id);
            sum[p] += a[i].cmx;
            g[id] = 1;
        }
        cout << sum[1] + sum[2] + sum[3] << "\n";
    }
    return 0;
}
