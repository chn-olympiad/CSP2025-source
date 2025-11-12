#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXM=1e6+1e5+5,MAXN=1e4+15;
int N,M,K;
struct Edge
{
    int u,v,w;
    bool operator<(const Edge &j) const
    {
        return w<j.w;
    }
}e1[MAXM],e2[15][MAXN],e3[MAXM],e[MAXM];
int c[15],C=0;
LL ans=1e18;
int fa[MAXN];
int Find(int x)
{
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1;i<=M;i++)
    {
        scanf("%d %d %d",&e1[i].u,&e1[i].v,&e1[i].w);
    }
    sort(e1+1,e1+M+1);
    for(int i=1;i<=K;i++)
    {
        scanf("%d",&c[i]);
        if(c[i]) C=1;
        for(int j=1;j<=N;j++)
        {
            int w;
            scanf("%d",&w);
            e2[i][j]={N+i,j,w};
        }
        sort(e2[i]+1,e2[i]+N+1);
    }
   // puts("!!!");
    LL res=0;
    for(int st=0;st<(1<<K);st++)
    {
        if(st!=((1<<K)-1)&&C==0) continue;
  //      puts("hello");
        res=0;
        int t=0,n=N;
        for(int i=1;i<=K;i++)
        {
         //   puts(".");
            if(st&(1<<i-1)) 
            {   
                res+=c[i];
                n++;
               // puts("-");
                for(int j=1;j<=N;j++) e3[++t]=e2[i][j];
            }
        }
        sort(e3+1,e3+t+1);
      //  for(int i=1;i<=M+t;i++) printf("[%d%d%d]",e3[i].u,e3[i].v,e3[i].w);
        int p=1,q=1;
        if(t==0) q=0;
        for(int i=1;i<=M+t;i++)
        {
            if(e1[p].w<=e3[q].w&&p<=M||q>t) e[i]=e1[p],p++;
            else e[i]=e3[q],q++;
           // printf("[%d%d%d]\n",e[i].u,e[i].v,e[i].w);
        }
      //  printf("!!%d %d\n",st,M+t);
        for(int i=1;i<=N+K;i++) fa[i]=i;
        int cnt=0;
        for(int i=1;i<=M+t;i++)
        {
            int u=e[i].u,v=e[i].v,w=e[i].w;
            //printf("%d%d%d\n",u,v,w);
            u=Find(u),v=Find(v);
            if(u==v) continue;
         //   printf("%d%d%d\n",u,v,w);
            fa[u]=v;
            res+=w;
            cnt++;
            if(cnt==n-1) break;
        }
       // puts("yes");
      //  printf("ANS%d\n",res);
        ans=min(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}