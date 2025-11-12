#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
}eg[1000010],egg[1100010];
int n,m,k,c[20],a[20][10010],cnt,cnteg,fa[10020],depp[10020],fx,fy,cntn;
long long ans=LLONG_MAX,sum;
bool op[20];
bool cmp(const node&x,const node&y)
{
    return x.w<y.w;
}
int findfa(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=findfa(fa[x]);
}
void mst()
{
    cnt=n;
    cnteg=m;
    for(int i=1;i<=m;i++)
    {
        egg[i].u=eg[i].u;
        egg[i].v=eg[i].v;
        egg[i].w=eg[i].w;
    }
    sum=0;
    for(int i=1;i<=k;i++)
    {
        if(op[i])
        {
            cnt++;
            sum+=c[i];
            if(sum>=ans)return;
            for(int j=1;j<=n;j++)
            {
                cnteg++;
                egg[cnteg].u=cnt;
                egg[cnteg].v=j;
                egg[cnteg].w=a[i][j];
            }
            //cout<<i<<" "<<c[i]<<endl;
        }
    }
    //cout<<cnt<<" "<<cnteg<<" "<<sum<<endl;
    sort(egg+1,egg+cnteg+1,cmp);
    for(int i=1;i<=cnt;i++)fa[i]=i,depp[i]=1;
    cntn=0;
    for(int i=1;i<=cnteg;i++)
    {
        fx=findfa(egg[i].u);
        fy=findfa(egg[i].v);
        if(fx==fy)continue;
        cntn++;
        sum+=egg[i].w;
        if(sum>=ans)return;
        if(depp[fx]<depp[fy])fa[fx]=fy;
        else
        {
            fa[fy]=fx;
            if(depp[fx]==depp[fy])depp[fx]++;
        }
        if(cntn==cnt-1)break;
    }
    ans=min(ans,sum);
    //cout<<sum<<endl;
}
void dfs(int dep)
{
    if(dep>k)
    {
        mst();
        return;
    }
    op[dep]=0;
    dfs(dep+1);
    op[dep]=1;
    dfs(dep+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&eg[i].u,&eg[i].v,&eg[i].w);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
        //cout<<i<<" "<<c[i]<<endl;
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}
