#include<cstdio>
#include<algorithm>
int t,n,ans,sum,acnt,bcnt,ccnt,a[100001],b[100001],c[100001];
void dfs(int step)
{
    if(step>n)
    {
        ans=std::max(ans,sum);
        return;
    }
    if(acnt<n/2)
    {
        acnt++;
        sum+=a[step];
        dfs(step+1);
        sum-=a[step];
        acnt--;
    }
    if(bcnt<n/2)
    {
        bcnt++;
        sum+=b[step];
        dfs(step+1);
        sum-=b[step];
        bcnt--;
    }
    if(ccnt<n/2)
    {
        ccnt++;
        sum+=c[step];
        dfs(step+1);
        sum-=c[step];
        ccnt--;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        acnt=0;
        bcnt=0;
        ccnt=0;
        sum=0;
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
        }
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
