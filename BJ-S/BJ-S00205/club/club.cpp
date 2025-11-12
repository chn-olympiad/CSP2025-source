# include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
struct TSL
{
    int a, b, c;
    int maxn;
    int mxid;
    int mid;
    int mdid;
    int x;
}tsl[MAXN];

bool cmp(TSL xx, TSL yy)
{
    if (xx.x != yy.x)
        return xx.x < yy.x;
    return xx.maxn < yy.maxn;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(tsl, 0, sizeof(tsl));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> tsl[i].a >> tsl[i].b >> tsl[i].c;
            tsl[i].maxn = max(max(tsl[i].a, tsl[i].b), tsl[i].c);
            if (tsl[i].a == tsl[i].maxn)
            {
                tsl[i].mxid = 1;
                tsl[i].mid = max(tsl[i].b, tsl[i].c);
                if (tsl[i].mid == tsl[i].b)
                    tsl[i].mdid = tsl[i].b;
                else
                    tsl[i].mdid = tsl[i].c;
            }
            else if (tsl[i].b == tsl[i].maxn)
            {
                tsl[i].mxid = 2;
                tsl[i].mid = max(tsl[i].a, tsl[i].c);
                if (tsl[i].mid == tsl[i].a)
                    tsl[i].mdid = tsl[i].a;
                else
                    tsl[i].mdid = tsl[i].c;
            }
            else
            {
                tsl[i].mxid = 3;
                tsl[i].mid = max(tsl[i].a, tsl[i].b);
                if (tsl[i].mid == tsl[i].a)
                    tsl[i].mdid = tsl[i].a;
                else
                    tsl[i].mdid = tsl[i].b;
            }
            tsl[i].x = tsl[i].maxn - tsl[i].mid;
        }
        sort(tsl+1, tsl+n+1, cmp);
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += tsl[i].maxn;
            if (tsl[i].mxid == 1)
                cnta ++;
            else if (tsl[i].mxid == 2)
                cntb ++;
            else
                cntc ++;
        }
        int flag, ot;
        if (cnta > n/2)
            flag = 1, ot = cnta - n/2;
        if (cntb > n/2)
            flag = 2, ot = cntb - n/2;
        if (cntc > n/2)
            flag = 3, ot = cntc - n/2;
        for (int i = 1; i <= n; i++)
        {
            if (ot == 0)
                break;
            if (tsl[i].mxid == flag)
            {
                ot --;
                ans -= tsl[i].x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
