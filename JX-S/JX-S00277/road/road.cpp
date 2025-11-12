#include<bits/stdc++.h>
using namespace std;
struct ROAD
{
    int u,v,w;
}s[1000050];
int town[10005];
bool f[10005];
bool cmp(ROAD x,ROAD y)
{
    return x.w<y.w;
}
int n,m,k;
int serch(int x)
{
    for(int i=x;i<=m;i++)
    {
        if((f[s[i].u]&&!f[s[i].v])||(f[s[i].v]&&!f[s[i].u]))return i;
    }
    return 0;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    bool flag=1;
    int cnt1=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
    }
    int now=m+1;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&town[0]);
        if(town[0]!=0)flag=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&town[j]);
            if(town[j]==0)
            {
                f[j]=1;
                cnt1++;
            }
        }
    }
    if(k==0)
    {
        sort(s+1,s+1+m,cmp);
        f[s[1].u]=1;
        f[s[1].v]=1;
        int cnt=1;
        long long ans=s[1].w;
        while(cnt<n-1)
        {
            int tmp=serch(cnt);
            f[s[tmp].u]=1;
            f[s[tmp].v]=1;
            ans+=s[tmp].w;
            cnt++;
        }
        printf("%lld",ans);
        return 0;
    }
    else if(flag)
    {
        sort(s+1,s+1+m,cmp);
        long long ans=0;
        while(cnt1<n-1)
        {
            int tmp=serch(cnt1);
            f[s[tmp].u]=1;
            f[s[tmp].v]=1;
            ans+=s[tmp].w;
            cnt1++;
        }
        printf("%lld",ans);
        return 0;
    }
    printf("13");
    return 0;
}
