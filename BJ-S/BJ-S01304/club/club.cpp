/*#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long
struct node
{
    int a, b, c;
};
int t;
int n;
node a[100005];
int dp[100005][4];
int va[100005][4][4];

bool cmp(node t1, node t2)
{
    if(t1.a != t2.a)
    {
        return t1.a > t2.a;
    }
    if(t1.b != t2.b)
    {
        return t1.b > t2.b;
    }
    return t1.c > t2.c;
}
signed main()
{
    freopen("club1.in", "r", stdin);
    //freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(va, 0, sizeof(va));
        scanf("%lld", &n);
        int maxv = n / 2;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
        }
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; i++)
        {
            //check whether 1 can follow
            int t1 = -1;
            int t2 = -1;
            if(t1 < a[i - 1].a && va[i - 1][1][1] < maxv)
            {
                t1 = a[i - 1].a;
                t2 = 1;
            }
            if(t1 < a[i - 1].b && va[i - 1][2][1] < maxv)
            {
                t1 = a[i - 1].b;
                t2 = 2;
            }
            if(t1 < a[i - 1].c && va[i - 1][3][1] < maxv)
            {
                t1 = a[i - 1].c;
                t2 = 3;
            }
            if((va[i - 1][t2][1] < maxv || t2 != 1))
            {
                if(dp[i - 1][1] > dp[i - 1][t2] + a[i].a)
                {
                    dp[i][1] = dp[i - 1][1];
                    va[i][1][1] = va[i - 1][1][1];
                    va[i][1][2] = va[i - 1][1][2];
                    va[i][1][3] = va[i - 1][1][3];
                }
                else
                {
                    dp[i][1] = dp[i - 1][t2] + a[i].a;
                    va[i][1][1] = va[i - 1][t2][1] + 1;
                    va[i][1][2] = va[i - 1][t2][2];
                    va[i][1][3] = va[i - 1][t2][3];
                }

            }
            //check whether 2 can follow
            t1 = -1;
            t2 = -1;
            if(t1 < a[i - 1].a && va[i - 1][1][2] < maxv)
            {
                t1 = a[i - 1].a;
                t2 = 1;
            }
            if(t1 < a[i - 1].b && va[i - 1][2][2] < maxv)
            {
                t1 = a[i - 1].b;
                t2 = 2;
            }
            if(t1 < a[i - 1].c && va[i - 1][3][2] < maxv)
            {
                t1 = a[i - 1].c;
                t2 = 3;
            }
            if((va[i - 1][t2][2] < maxv || t2 != 1))
            {
                if(dp[i - 1][2] > dp[i - 1][t2] + a[i].b)
                {
                    dp[i][2] = dp[i - 1][2];
                    va[i][2][1] = va[i - 1][2][1];
                    va[i][2][2] = va[i - 1][2][2];
                    va[i][2][3] = va[i - 1][2][3];
                }
                else
                {
                    dp[i][2] = dp[i - 1][t2] + a[i].b;
                    va[i][2][1] = va[i - 1][t2][1];
                    va[i][2][2] = va[i - 1][t2][2] + 1;
                    va[i][2][3] = va[i - 1][t2][3];
                }
            }

            //check whether 3 can follow
            t1 = -1;
            t2 = -1;
            if(t1 < a[i - 1].a && va[i - 1][1][3] < maxv)
            {
                t1 = a[i - 1].a;
                t2 = 1;
            }
            if(t1 < a[i - 1].b && va[i - 1][2][3] < maxv)
            {
                t1 = a[i - 1].b;
                t2 = 2;
            }
            if(t1 < a[i - 1].c && va[i - 1][3][3] < maxv)
            {
                t1 = a[i - 1].c;
                t2 = 3;
            }
            if((va[i - 1][t2][3] < maxv || t2 != 1))
            {
                if(dp[i - 1][3] > dp[i - 1][t2] + a[i].c)
                {
                    dp[i][3] = dp[i - 1][3];
                    va[i][3][1] = va[i - 1][3][1];
                    va[i][3][2] = va[i - 1][3][2];
                    va[i][3][3] = va[i - 1][3][3];
                }
                else
                {
                    dp[i][3] = dp[i - 1][t2] + a[i].c;
                    va[i][3][1] = va[i - 1][t2][1];
                    va[i][3][2] = va[i - 1][t2][2];
                    va[i][3][3] = va[i - 1][t2][3] + 1;
                }

            }
        }
        printf("%lld\n", max(max(dp[n][1], dp[n][2]), dp[n][3]));
    }
    return 0;
}*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long
struct node
{
    int a, b, c;
};
int t;
int n;
node a[100005];

bool cmp(node t1, node t2)
{
    if(t1.a != t2.a)
    {
        return t1.a > t2.a;
    }
    if(t1.b != t2.b)
    {
        return t1.b > t2.b;
    }
    return t1.c > t2.c;
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        int maxv = n / 2;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
        }
        sort(a + 1, a + n + 1, cmp);
        int ans = 0;
        for(int i = 1; i <= maxv; i++)
        {
            ans += a[i].a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
