#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+20,M=1e6+10,inf=1e17;
struct node
{
    int u,v,w;
}edge[M];
vector<node> addedge;
bitset<20> use;
bool cmp(node &x,node &y)
{
    return x.w<y.w;
}
int fa[N];
int find(int x)
{
    if(x==fa[x])
    {
        return x;
    }
    return fa[x]=find(fa[x]);
}
int c[N],a[N][N],sze[N];
void init()
{
    for(int i=1;i<=N;i++)
    {
        fa[i]=i;
        sze[i]=1;
    }
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(sze[fx]<sze[fy])
    {
        swap(fx,fy);
    }
    fa[fy]=fx;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
    }
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            addedge.push_back({i+n,j,a[i][j]});
        }
    }
    sort(addedge.begin(),addedge.end(),cmp);
    ll ans=inf;
    for(int base=0;base<1<<(k+1);base++)
    {
        ll cnt=0,sum=n-1;
        use.reset();
        for(int i=1;i<=k;i++)
        {
            if((base>>(i-1))&1)
            {
                cnt+=c[i];
                sum++;
                use[i]=1;
            }
        }
        if(cnt>ans) continue;
        init();
        for(int i=1,idxm=1,idxadd=0;i<=sum;i++)
        {
            while(idxm<=m)
            {
                auto [u,v,w]=edge[idxm];
                int fu=find(u);
                int fv=find(v);
                if(fu==fv) idxm++;
                else break;
            }
            while(idxadd<addedge.size())
            {
                auto [u,v,w]=addedge[idxadd];
                int fu=find(u);
                int fv=find(v);
                if(fu==fv||!use[u-n]) idxadd++;
                else break;
            }
            int tm=inf,tadd=inf;
            if(idxm<=m)
            {
                tm=edge[idxm].w;
            }
            if(idxadd<addedge.size())
            {
                tadd=addedge[idxadd].w;
            }
            if(tm<tadd)
            {
                auto [u,v,w]=edge[idxm++];
                merge(u,v);
                cnt+=w;
            }
            else
            {
                auto [u,v,w]=addedge[idxadd++];
                merge(u,v);
                cnt+=w;
            }
            if(cnt>ans)
            {
                break;
            }
        }
        ans=min(ans,cnt);
    }
    cout<<ans;
    return 0;
}