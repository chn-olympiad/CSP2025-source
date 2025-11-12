#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=5e6+7;
int head[N],n,m,k,cnt,fa[N],ans,c[11];
bool vis[11];
struct edge{
    int u,v,w;
}e[M];
/*
void build_edge(int s,int ee,int y)
{
    e[++cnt].nxt=head[s];
    head[s]=cnt;
    e[cnt].to=ee;
    e[cnt].c=y;
}
*/
int find_fa(int x)
{
    if(fa[x]!=x) return fa[x]=find_fa(fa[x]);
    return x;
}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        //build_edge(u,v,w);
    }
    cnt=m;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=m;j++)
        {
            int a;
            scanf("%d",&a);
            e[++cnt].u=m+i;
            e[cnt].v=j;
            e[cnt].w=a+c[i];
        }
    }
    sort(e+1,e+1+cnt,cmp);
    for(int i=1;i<=m;i++)
    {
        if(find_fa(e[i].u)!=find_fa(e[i].v))
        {
            if(e[i].u>n)
            {
                if(vis[e[i].u]==0)
                {
                    vis[e[i].u]=1;
                }
                else
                {
                    ans-=c[e[i].u-n];
                }
            }
            if(e[i].v>n)
            {
                if(vis[e[i].v]==0)vis[e[i].v]=1;
                else ans-=c[e[i].v-n];
            }
            //cout<<fa[e[i].u]<<" "<<fa[e[i].v]<<" ";
            fa[find_fa(e[i].u)]=find_fa(e[i].v);
            ans+=e[i].w;
            //cout<<fa[e[i].u]<<" "<<fa[e[i].v]<<" ";
            //cout<<ans<<endl;
        }
    }
    printf("%d",ans);
    return 0;
}

