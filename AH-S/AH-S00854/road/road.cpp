#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e4+7,MAXM=2e6+7;
const long long oo=1e16;
int n,m,k,top[15];
long long c[15],ans=oo,tmp;
struct Edge{
    long long u,v,w;
}e[MAXM];
struct Extra{
    long long v,w;
}a[15][MAXN];
inline bool cmp1(Edge A,Edge B)
{
    return A.w==B.w?A.u<B.u:A.w<B.w;
}
inline bool cmp2(Extra A,Extra B)
{
    return A.w==B.w?A.v<B.v:A.w<B.w;
}
int fa[MAXN<<1];
inline void Init()
{
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=0;i<13;i++)top[i]=1;
}
inline int Find(int x)
{
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
inline void Merge(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x!=y)fa[y]=x;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);int K=1<<k;
    for(int i=1;i<=m;i++)scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1;i<=k;i++){
        scanf("%lld",c+i);
        for(int j=1;j<=n;j++)scanf("%lld",&a[i][j].w),a[i][j].v=j,tmp|=a[i][j].w;
        sort(a[i]+1,a[i]+1+n,cmp2);a[i][n+1].w=oo;
    }
    e[m+1].w=oo;
    sort(e+1,e+1+m,cmp1);
    for(int rp=0;rp<K;rp++)
    {
        long long sum=0,cnt=0;
        for(int i=1;i<=k;i++)if(rp&(1<<(i-1)))sum+=c[i],cnt++;
        if(sum>ans)continue;
        Init();
        //~ if(tmp&&rp){
            //~ for(int i=1;i<=k;i++)ans=min(ans,c[i]);
            //~ break;
        //~ }
        for(int i=1;i<n+cnt;i++)
        {
            while(top[0]<=m&&Find(e[top[0]].u)==Find(e[top[0]].v))top[0]++;
            int u=e[top[0]].u,v=e[top[0]].v,w=e[top[0]].w,p=0;
            for(int i=1;i<=k;i++)if(rp&(1<<(i-1))){
                while(top[i]<=n&&Find(a[i][top[i]].v)==Find(n+i))top[i]++;
                if(a[i][top[i]].w<w)u=n+i,v=a[i][top[i]].v,w=a[i][top[i]].w,p=i;
            }
            top[p]++,sum+=w;
            //~ if(!rp)printf("%lld\n",sum);
            if(sum>=ans)break;
            Merge(u,v);
        }
        ans=min(ans,sum);
    }
    printf("%lld",ans);
    return 0;
}
