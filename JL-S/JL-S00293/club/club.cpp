#include<bits/stdc++.h>

using namespace std;

struct node
{
    int f,s,t;
} a[100005];
int t,n;
long long dp[100005][3],ans;
int cnt[100005][3];

bool cmp(node a,node b)
{
    return a.f > b.f;
}

void A()
{
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n/2;i++)
    {
        ans += a[i].f;
    }
    printf("%lld",ans);
}
/*
int check(int id)
{
    int tx = dp[id][0];
    int ty = dp[id][1];
    int tz = dp[id][2];
    if(tx > ty && tx > tz)return cnt[id][0];
    if(ty > tx && ty > tz)return cnt[id][1];
    if(tz > tx && tz > ty)return cnt[id][2];
}
*/
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        //memset(dp,0,sizeof(dp));
        //memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].f,&a[i].s,&a[i].t);
            /*
            dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + cnt[i-1][0] < n / 2 ? a[i][0] : 0;
            cnt[i][0] = check(i-1) + (cnt[i-1][0] < n / 2);
            dp[i][1] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + cnt[i-1][1] < n / 2 ? a[i][1] : 0;
            cnt[i][1] = check(i-1) + (cnt[i-1][1] < n / 2);
            dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + cnt[i-1][2] < n / 2 ? a[i][2] : 0;
            cnt[i][2] = check(i-1) + (cnt[i-1][2] < n / 2);
            printf("%lld %lld %lld\n",dp[i][0],dp[i][1],dp[i][2]);
            */
        }
        //printf("%lld\n",max({dp[n][0],dp[n][1],dp[n][2]}));
        if(a[1].s == 0 && a[1].t == 0)
        {
            A();
        }
    }

    return 0;
}
/*
*/
