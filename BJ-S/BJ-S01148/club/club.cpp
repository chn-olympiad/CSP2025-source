#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 + 10;

struct stu
{
    int x, y, z;
    int mx, ix, mm, im, mn, in;
    void init()
    {
        if(x >= y && x >= z)
        {
            if(y >= z)
                mm = y, im = 2, in = 3, mn = z;
            else mm = z, im = 3, in = 2, mn = y;
            ix = 1, mx = x;
        }
        else if(y >= x && y >= z)
        {
            if(x >= z)
                mm = x, im = 1, in = 3, mn = z;
            else mm = z, im = 3, in = 1, mn = x;
            ix = 2, mx = y;
        }
        else
        {
            if(x >= y)
                mm = x, im = 1, in = 2, mn = y;
            else mm = y, im = 2, in = 1, mn = x;
            ix = 3, mx = z;
        }

    }
    bool operator < (const stu &a) const
    {
        return a.mx - a.mm < mx - mm;
    }
}a[N], b[N], c[N];
int T, n;
bool cmp(stu a, stu b)
{
    if(a.mx != b.mx)
        return a.mx > b.mx;
    else if(a.mm != b.mm)
        return a.mm > b.mm;
    return a.mn < b.mn;
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    for(int i = 1; i <= n; i++)
        a[i].init();
    priority_queue<stu> q[4];
    int cnt[4] = {};
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt[a[i].ix] < n / 2) ans += a[i].mx, cnt[a[i].ix]++, q[a[i].ix].push(a[i]);
        else if(a[i].mx >= q[a[i].ix].top().mx - q[a[i].ix].top().mm)
        {
            //cout << q[a[i].ix].top().mm << endl;
            //cout << q[a[i].ix].top().mx - q[a[i].ix].top().mm << endl;
            ans -= q[a[i].ix].top().mx - q[a[i].ix].top().mm;
            cnt[q[a[i].ix].top().im]++;
            ans += a[i].mx;
            q[a[i].ix].pop();
            q[a[i].ix].push(a[i]);
        }
        else ans += a[i].mm, cnt[a[i].im]++;
    }
    cout << ans << endl;
    return;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
