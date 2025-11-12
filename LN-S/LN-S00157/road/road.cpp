#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r,w;
}a[5000005];
int n,m,k;
int f[10005],b[10005];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        scanf("%d",&c);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&b[j]);
            if(b[j]==0)c=j;
        }
        for(int j=1;j<=n;j++)
        {
            if(j!=c)
            {
                m++;
                a[m].l=j;
                a[m].r=c;
                a[m].w=b[j];
            }
        }
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)
        f[i]=i;
    int num=0;
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int L=find(a[i].l),R=find(a[i].r);
        if(L!=R)
        {
            num++;
            ans+=a[i].w;
            f[R]=L;
        }
    }
    printf("%lld",ans);
    return 0;
}
