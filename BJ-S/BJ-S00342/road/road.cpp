#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fs first
#define sc second
using namespace std;
const int N=1e4+50,M=1e6+50;
int n,m,k;
struct node
{
    int u,v,w;
}e[M],p[M];
int fa[N],cnt,a[12][N],c[N];
void init(int x)
{
    For(i,1,x)
        fa[i]=i;
}
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int ans=0;
    cin>>n>>m>>k;
    For(i,1,m)
    {
        cin>>p[i].u>>p[i].v>>p[i].w;
    }
    init(n);
    sort(p+1,p+m+1,cmp);
    For(i,1,m)
    {
        int x=p[i].u,y=p[i].v;
        int fx=find(x),fy=find(y);
        if(fx==fy)continue;
        if(fx>fy)swap(fx,fy),swap(x,y);
        fa[fx]=fy;
        ans+=p[i].w;
        e[++cnt]=p[i];
    }
    // cout<<cnt<<endl;
    For(i,1,k)
    {
        cin>>c[i];
        For(j,1,n)cin>>a[i][j];
        // cout<<c[i]<<' ';
        // For(j,1,n)cout<<a[i][j]<<' ';
        // cout<<endl;
    }
    int pos=cnt;
    For(tot,1,(1<<k)-1)
    {
        cnt=pos;
        // cout<<cnt<<endl;
        For(i,1,cnt)p[i]=e[i];
        int now=tot,sum=0,awa=0;
        For(i,1,k)
        {
            if((now>>(i-1))&1)
            {
                awa++;
                // cout<<now<<' '<<i<<endl;
                sum+=c[i];
                For(j,1,n)
                {
                    p[++cnt]={i+n,j,a[i][j]};
                }
            }
        }
        // cout<<now<<' '<<sum<<endl;
        int che=0;
        init(n+k);
        sort(p+1,p+cnt+1,cmp);
        For(i,1,cnt)
        {
            int x=p[i].u,y=p[i].v;
            int fx=find(x),fy=find(y);
            if(fx==fy)continue;
            fa[fx]=fy;
            sum+=p[i].w;
            // cout<<now<<' '<<x<<' '<<y<<' '<<e[i].w<<' '<<sum<<endl;
            che++;
            if(che==awa+n)break;
        }
        // cout<<sum<<endl;
        if(ans>sum)ans=sum;
    }
    cout<<ans<<'\n';
    return 0;
}