#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
int cur;
struct node
{
    int u,v,w;
}e[2000005];
int c[15],cnt[15];
long long sum[15];
int fa[2000005];
int fi(int x)
{
    return fa[x]=fa[x]==x ? x : fi(fa[x]);
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i<=m+n*k; i++) fa[i]=i;
    for(int i = 1; i<=m; i++)
    {
        cur++;
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for(int i = 1; i<=k; i++)
    {
        scanf("%d",&c[i]);
        for(int j = 1; j<=n; j++)
        {
            cur++;
            int temp;
            scanf("%d",&temp);
            e[cur].u=n+i,e[cur].v=j,e[cur].w=temp+c[i];
        }
    }
    sort(e+1,e+cur+1,cmp);
    for(int i = 1; i<=cur; i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(fi(u)!=fi(v))
        {
            fa[fi(u)]=fi(v);
            ans+=w;
            if(u>n) cnt[u-n]++,sum[u-n]+=w;
        }
    }
    for(int i = 1; i<=k; i++)
    {
        if(cnt[i]==1) ans-=sum[i];
        if(cnt[i]>1) ans-=c[i]*(cnt[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}