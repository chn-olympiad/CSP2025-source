#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x;
}
int ufs[11000];
void UFS_set(int k)
{
    int i;
    for(i=1;i<=k;i++)
        ufs[i]=i;
}
int fnd(int x)
{
    if(ufs[x]==x)
        return x;
    ufs[x]=fnd(ufs[x]);
    return ufs[x];
}
void merge(int u,int v)
{
    if(fnd(u)==fnd(v))
        return;
    ufs[fnd(v)]=fnd(u);
}
int n,m,k,cnt,pcnt;
long long ans,c[12],a[12][11000];
struct edge
{
    int u,v;
    long long w;
}e[1100000],ne[11000],shd[11000];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
long long kruskal(edge* e,int m,bool B)
{
    int u,v,i;
    long long w,ans=0;
    sort(e+1,e+m+1,cmp);
    UFS_set(n+k);
    for(i=1;i<=m;i++)
    {
        u=e[i].u;
        v=e[i].v;
        w=e[i].w;
        if(fnd(u)==fnd(v))
            continue;
        merge(u,v);
        ans+=w;
        if(B)
        {
            cnt++;
            ne[cnt]=e[i];
        }
    }
    return ans;
}
long long sum;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int S,i,j;
    n=read();
    m=read();
    k=read();
    for(i=1;i<=m;i++)
    {
        e[i].u=read();
        e[i].v=read();
        e[i].w=read();
    }
    ans=kruskal(e,m,1);
    for(i=1;i<=k;i++)
    {
        c[i]=read();
        for(j=1;j<=n;j++)
            a[i][j]=read();
    }
    for(S=1;S<(1<<k);S++)
    {
        sum=0;
        pcnt=cnt;
        for(i=1;i<=cnt;i++)
            shd[i]=ne[i];
        for(i=0;i<k;i++)
        {
            if((S>>i)&1)
            {
                sum+=c[i];
                for(j=1;j<=n;j++)
                {
                    pcnt++;
                    shd[pcnt]=(edge){n+i+1,j,a[i+1][j]};
                }
            }
        }
        sum+=kruskal(ne,pcnt,0);
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}
