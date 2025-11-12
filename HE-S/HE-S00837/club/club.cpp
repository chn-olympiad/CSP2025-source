#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],cnt1=1,cnt2=1,cnt3=1,ans;
void dfs(int now,int sum)
{
    if(now==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    if(cnt1<n/2)
    {
        cnt1++;
        dfs(now+1,sum+a[now][1]);
        cnt1--;
    }
    if(cnt2<n/2)
    {
        cnt2++;
        dfs(now+1,sum+a[now][2]);
        cnt2--;
    }
    if(cnt3<n/2)
    {
        cnt3++;
        dfs(now+1,sum+a[now][3]);
        cnt3--;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        bool flaga=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][2]!=0) flaga=0;
            if(a[i][3]!=0) flaga=0;
        }
        cnt1=0,cnt2=0,cnt3=0,ans=0;
        if(flaga)
        {
            for(int i=1;i<=n/2;i++) ans+=a[i][1];
            printf("%d\n",ans);
        }
        else
        {
            dfs(1,0);
            printf("%d\n",ans);
        }
    }

    return 0;
}

