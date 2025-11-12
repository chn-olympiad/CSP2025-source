#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10000+10;
int fa[N];
struct node{
    int u,v,w;
}c[1000000*2];
int idx;
int n,m,k;
int ans,cnt;
bool cmp(node &a,node &b)
{
    return a.w<b.w;
}
void init()
{
    for(int i=1;i<=n+5;++i)fa[i]=i;
}
int find(int x)
{
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
}
/*void merge(int x,int y)
{
    x=find(x),y=find(y);
    if(x!=y)fa[x]=y;
}*/
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        c[i]={u,v,w};
    }
    idx=m;
    for(int i=1;i<=k;++i)
    {
        int x;
        scanf("%lld",&x);
        int a=n+i;
        for(int j=1;j<=n;++j)
        {
            int y;
            scanf("%lld",&y);
            c[++idx]={a,j,x+y};
        }
    }
    sort(c+1,c+1+idx,cmp);
    //for(int i=1;i<=idx;++i)
    //{
    //    cout<<c[i].u<<" "<<c[i].v<<" "<<c[i].w<<"\n";
    //}
    for(int i=1;i<=idx;++i)
    {
        int x=c[i].u,y=c[i].v,w=c[i].w;
        if(find(x)!=find(y))
        {
            fa[x]=y;
            ans+=w;
            cnt++;
        }
        if(cnt>=n/2+1)break;
    }
    cout<<ans;
    return 0;
}
