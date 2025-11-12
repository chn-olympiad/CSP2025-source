#include <bits/stdc++.h>
#define int long long
using namespace std;

struct sc
{
    int a, b, c, m;
} d[100010];
int n;
int dp[100010][5];
int ps[100010][5];

int mn(sc a)
{
    return min(a.a, min(a.b, a.c));
}

bool cmp1(sc a, sc b)
{
    return a.a > b.a;
}

bool cmp2(sc a, sc b)
{
    return (a.a - a.b) > (b.a - b.b);
}

bool cmp3(sc a, sc b)
{
    return a.a - mn(a) > b.a - mn(a);
}
bool cmp4(sc a, sc b)
{

    return a.b - mn(a) > b.b - mn(a);
}
bool cmp5(sc a, sc b)
{

    return a.c - mn(a) > b.c - mn(a);
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        int fa = 1, fb = 1;
        int ma = 0, mb = 0, mc = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> d[i].a >> d[i].b >> d[i].c;
            if(d[i].c)
            {
                fa = fb = 0;
            }
            if(d[i].b)
            {
                fa = 0;
            }
            d[i].m = max(d[i].a, max(d[i].b, d[i].c));
            if(d[i].a == d[i].m) ma++;
            if(d[i].b == d[i].m) mb++;
            if(d[i].c == d[i].m) mc++;
        }
        if(fa)
        {
            sort(d + 1, d + n + 1, cmp1);
            int ts = 0;
            for(int i = 1; i <= n / 2; i++)
            {
                ts += d[i].a;
            }
            cout << ts << endl;
            continue;
        }
        else if(fb)
        {
            sort(d + 1, d + n + 1, cmp2);
            int ts = 0;
            for(int i = 1; i <= n / 2; i++)
            {
                ts += d[i].a;
            }
            for(int i = n / 2 + 1; i <= n; i++)
            {
                ts += d[i].b;
            }
            cout << ts << endl;
            continue;
        }
        int s = 0;/*
        for(int i = 1; i <= n; i++)
        {
            dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + d[i].a;
            ps[i][1] = ps[i - 1][1] + 1;
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + d[i].b;
            ps[i][2] = ps[i - 1][2] + 1;
            dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + d[i].c;
            ps[i][3] = ps[i - 1][3] + 1;
        }
        s = max(dp[n][1], max(dp[n][2], dp[n][3]));
        */
        if(n == 2)
        {
            s = max(d[1].a + d[2].b, max(d[1].a + d[2].c, max(d[1].b + d[2].c, max(d[1].b + d[2].a, max(d[1].b + d[2].c, d[1].c + d[2].b)))));
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                s += d[i].m;
            }
        }

        cout << s;
        cout << endl;
    }
    return 0;
}
