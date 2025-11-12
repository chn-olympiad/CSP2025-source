#include<bits/stdc++.h>
using namespace std;
int N,M,K;
struct road
{
    int l,r,len;
}f[1500030],f_coy[1500030];
int num=0;
void add(int u,int v,int d)
{
    f[++num].l=u;
    f[num].r=v;
    f[num].len=d;
}
int fa[20010],siz[2010];
int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
long long solve(int k,int p)
{
    memset(siz,1,sizeof(siz));
    sort(f+1,f+k+1,[](road x,road y){return x.len<y.len;});
    for(int i=1;i<=p;i++) fa[i]=i;
    long long s=0;
    for(int i=1;i<=k;i++)
    {
        int u=f[i].l,v=f[i].r;
        u=find(u);v=find(v);
        if(u!=v)
        {
            fa[v]=u;
            s+=f[i].len;
            if(u<=N&&v<=N) siz[u]+=siz[v];
            if(siz[u]==p) break;
        }
    }
    return s;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&N,&M,&K);
    for(int i=1;i<=M;i++)
    {
        int u,v,d;scanf("%d%d%d",&u,&v,&d);
        add(u,v,d);
    }
    long long ans=solve(num,N);
    //cout<<ans<<endl;
    memcpy(f_coy,f,sizeof(f));
    for(int i=1;i<=K;i++)
    {
        long long d;scanf("%lld",&d);
        memcpy(f,f_coy,sizeof(f_coy));
        for(int j=1;j<=N;j++)
        {
            int op;scanf("%d",&op);
            add(N+i,j,op);
        }
        ans=min(ans,d+solve(num,N+i));
        //cout<<ans<<" "<<d+solve(num,N+i)<<endl;
    }
    printf("%lld",ans);
    return 0;
}
