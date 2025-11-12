#include<bits/stdc++.h>
#define N 10015
#define M 1000005
#define K 15
using namespace std;
struct node
{
    int u,v,w;
}E[M],G[M];
int n,m,k,c[K],a[K][N],fa[N],cnt;
long long ans;
bool use[M];
bool cmp(node i,node j)
{
    return i.w<j.w;
}
int find(int f)
{
    if(fa[f]==f) return f;
    return fa[f]=find(fa[f]);
}
long long work()
{
    sort(E+1,E+1+cnt,cmp);
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    long long ret=0;
    for(int i=1;i<=cnt;i++)
    {
        int q=find(E[i].u),p=find(E[i].v);
        if(q==p) continue;
        fa[q]=p;
        ret+=E[i].w;
        if(ret>ans) return ans;
    }
    return ret;
}
void dfs(int dep)
{
    if(dep>k)
    {
        long long nw=0;
        cnt=n-1;
        for(int i=1;i<=n-1;i++)
            E[i]=G[i];
        for(int i=1;i<=k;i++)
            if(use[i])
            {
                nw+=c[i];
                for(int j=1;j<=n;j++)
                {
                    node tmp;
                    tmp.u=n+i,tmp.v=j,tmp.w=a[i][j];
                    E[++cnt]=tmp;
                }
            }
        nw+=work();
        if(nw<ans) ans=nw;
        return ;
    }
    use[dep]=0;
    dfs(dep+1);
    use[dep]=1;
    dfs(dep+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
    sort(E+1,E+1+m,cmp);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int q=find(E[i].u),p=find(E[i].v);
        if(q==p) continue;
        use[i]=1;
        fa[q]=p;
        ans+=E[i].w;
    }
    for(int i=1;i<=m;i++)
        if(use[i])
            G[++cnt]=E[i];
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}