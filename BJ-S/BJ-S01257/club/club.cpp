#include <bits/stdc++.h>

using namespace std;
#define ll long long
struct node
{
    int num;
    int id;
    int a,b,c;
    int maxn;
    int ab,ac,bc;
}dp[100005];

int T;
//int a[10000],b[10000],c[10000];
//int minab[10000],minac[10000],minbc[10000];
int a1,b1,c1;
int n,ab1,bc1;
bool f1,f2,f3;
bool cmp(node x,node y)
{
    if(x.maxn!=y.maxn) return x.maxn<y.maxn;
    else if(x.maxn == 1) return min(x.ab,x.ac)<min(y.ab,y.ac);
    else if(x.maxn == 2) return min(x.bc,x.ab)<min(y.bc,y.ab);
    else if(x.maxn == 3) return min(x.bc,x.ac)<min(y.bc,y.ac);
}
void fun()
{
    if(dp[1].maxn == 3) {bc1 = 1;return;}
    if(dp[1].maxn == 2) {ab1 = 1;}
    for(int i = 2;i<=n;i++)
    {
        if(dp[i-1].maxn == 1&&dp[i].maxn == 2) ab1 = i;
        if((dp[i-1].maxn == 2&&dp[i].maxn == 3)||(dp[i-1].maxn == 1&&dp[i].maxn == 3)) bc1 = i;
    }
    return ;
}
bool judge()
{
    return (a1<=n/2&&b1<=n/2&&c1<=n/2);
}
void judge2()
{
    if(a1>n/2) f1 = true;
    else if(b1>n/2) f2 = true;
    else if(c1>n/2) f3 = true;
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof dp);
        ab1 = 0,bc1 = 0,a1 = 0,b1 = 0,c1 = 0;f1 = 0,f2 = 0,f3 = 0;
        ll ans = 0;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            dp[i].a = x;dp[i].b = y;dp[i].c = z;
            dp[i].id = i;
            dp[i].ab = abs(x-y);dp[i].bc = abs(z-y);dp[i].ac = abs(x-z);
            if(dp[i].a == max(max(dp[i].a,dp[i].b),dp[i].c)) a1++,dp[i].maxn = 1,ans+=x;
            else if(dp[i].b == max(max(dp[i].a,dp[i].b),dp[i].c)) b1++,dp[i].maxn = 2,ans+=y;
            else c1++,dp[i].maxn = 3,ans+=z;
        }
        sort(dp+1,dp+1+n,cmp);
        fun();/*
        for(int i = 1;i<=n;i++) printf("%d ",dp[i].maxn);
        printf("\n");
        for(int i = 1;i<=n;i++) printf("%d ",dp[i].ab);
        printf("\n");
        for(int i = 1;i<=n;i++) printf("%d ",dp[i].bc);
        printf("\n");
        for(int i = 1;i<=n;i++) printf("%d ",dp[i].ac);
        printf("\n");
        printf("%d %d %d",a1,b1,c1);
        printf("\n");
        printf("%d %d",ab1,bc1);
        printf("\n");
        printf("%d ",ans);
*/
        if(judge()) {printf("%lld\n",ans);continue;}
        else
        {
            judge2();
            if(f1)
            {
                for(int i = 1;i<=a1-n/2;i++)
                {
                    ans-=min(dp[i].ab,dp[i].ac);
                    //printf("%d %d\n",min(dp[i].ab,dp[i].ac),ans);
                }
            }
            if(f2)
            {
                for(int i = ab1;i<=ab1+b1-n/2-1;i++)
                {
                    ans-=min(dp[i].bc,dp[i].ab);
                    //printf("%d ",ans);
                }
            }
            if(f3)
            {
                //printf("1");
                for(int i = bc1;i<=bc1+c1-n/2-1;i++)
                {
                    //printf("%d ",ans);
                    ans-=min(dp[i].ac,dp[i].bc);
                    //printf("%d ",ans);
                }
            }printf("%lld\n",ans);


        }

    }
    return 0;
}
