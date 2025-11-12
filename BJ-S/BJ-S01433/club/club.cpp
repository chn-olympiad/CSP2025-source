#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
ll a[100005],b[100005],c[100005],d[100005],e[100005];
bool cmp(ll x,ll y)
{
    return x > y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll m = n / 2,cnta = 0,cntb = 0,cntc = 0,ans = 0,cur = 0,cntd = 0;
        for (ll i = 1;i <= n;i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if (a[i] == b[i] || a[i] == c[i] || b[i] == c[i]) ans += a[i],d[i] = 4;
            else if (a[i] > b[i] && a[i] > c[i]) d[i] = 1,cnta++,ans += a[i];
            else if (b[i] > a[i] && b[i] > c[i]) d[i] = 2,cntb++,ans += b[i];
            else d[i] = 3,cntc++,ans += c[i];
        }
        if (cnta > m)
        {
            for (ll i = 1;i <= n;i++)
            {
                if (d[i] == 1)
                {
                    e[++cur] = b[i] - a[i];
                    e[cur] = max(c[i] - a[i],e[cur]);
                }
            }
            sort(e + 1,e + cur + 1,cmp);
            cur = 0;
            while (cnta > m)
            {
                cur++;
                cnta--;
                ans += e[cur];
            }
        }
        if (cntb > m)
        {
            for (ll i = 1;i <= n;i++)
            {
                if (d[i] == 2)
                {
                    e[++cur] = a[i] - b[i];
                    e[cur] = max(c[i] - b[i],e[cur]);
                }
            }
            sort(e + 1,e + cur + 1,cmp);
            cur = 0;
            while (cntb > m)
            {
                cur++;
                cntb--;
                ans += e[cur];
            }
        }
        if (cntc > m)
        {
            for (ll i = 1;i <= n;i++)
            {
                if (d[i] == 3)
                {
                    e[++cur] = a[i] - c[i];
                    e[cur] = max(b[i] - c[i],e[cur]);
                }
            }
            sort(e + 1,e + cur + 1,cmp);
            cur = 0;
            while (cntc > m)
            {
                cur++;
                cntc--;
                ans += e[cur];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
