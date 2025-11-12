#include<bits/stdc++.h>
using namespace std;
struct Node{
    int u,v,w;
};
Node r[100000007];
int mp[10005][10005],f[10005],a[10005];
long long n,m,k,ans,id;
int find(int r)
{
    if(f[r]!=r)f[r]=find(f[r]);
    return f[r];
}
bool cmp(Node a,Node b)
{
    return a.w<b.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.ans","w",stdout);
    memset(mp,0x3f,sizeof(mp));
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        mp[u][v]=w;
        mp[v][u]=w;
       r[++id].u=u,r[id].v=v,r[id].w=w;
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        scanf("%d",&c);
        for(int j=1;j<=n;j++)
            scanf("%d",&a[j]);
        for(int j=1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(c+a[j]+a[k]<mp[j][k])
                    r[++id].u=j,r[id].v=k,r[id].w=c+a[j]+a[k];
    }
    sort(r+1,r+id+1,cmp);
    for(int i=1;i<=id;i++)
        if(find(r[i].u)!=find(r[i].v))
        {
            f[find(r[i].u)]=f[r[i].v];
            ans+=r[i].w;
        }
    printf("%lld",ans);
    return 0;
}
