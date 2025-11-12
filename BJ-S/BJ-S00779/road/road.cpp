#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,k;
const int nr=1e4+20,mr=2e6+10,kr=15;
struct edge{
    int x,y,w;
}e[mr],e2[mr],e3[mr];
bool operator<(const edge &x,const edge &y){
    return x.w<y.w;
}
int c[kr],a[kr][nr],pos[kr];
int fa[nr],sz[nr];
void pre()
{
    for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
}
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(sz[fx]>sz[fy])swap(fx,fy);
    fa[fx]=fy,sz[fy]+=sz[fx];
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].w;
    bool flaga=1;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i])flaga=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)pos[i]=j;
        }
        if(!pos[i])flaga=0;
    }
    if(flaga)
    {
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++)
                if(j!=pos[i])e[++m]={pos[i],j,a[i][j]};
        sort(e+1,e+m+1);
        pre();
        int sum=0;
        for(int i=1;i<=m;i++)
            if(find(e[i].x)!=find(e[i].y))merge(e[i].x,e[i].y),sum+=e[i].w;
        cout<<sum<<'\n';
    }
    else
    {
        sort(e+1,e+m+1);
        int mm=m;
        int ans=9e18;
        for(int sta=0;sta<(1<<k);sta++)
        {
            int sum=0;
            int mmm=0;
            for(int i=1;i<=k;i++)
                if((sta>>i-1)&1)
                {
                    sum+=c[i];
                    for(int j=1;j<=n;j++)
                        e2[++mmm]={n+i,j,a[i][j]};
                }
            sort(e2+1,e2+mmm+1);
            m=0;
            int cur1=0,cur2=0;
            while(cur1<mm||cur2<mmm)
            {
                if(cur1==mm)e3[++m]=e2[++cur2];
                else if(cur2==mmm)e3[++m]=e[++cur1];
                else if(e[cur1+1]<e2[cur2+1])e3[++m]=e[++cur1];
                else e3[++m]=e2[++cur2];
            }
            pre();
            for(int i=1;i<=m;i++)
                if(find(e3[i].x)!=find(e3[i].y))merge(e3[i].x,e3[i].y),sum+=e3[i].w;
            ans=min(ans,sum);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
