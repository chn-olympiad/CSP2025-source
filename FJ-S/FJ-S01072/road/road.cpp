#include<bits/stdc++.h>
using namespace std;
const int N=10016,M=1e6+6;
int f[N],n,val[N];
inline int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
struct node
{
    int u,v,w;
}bian[M],b[N],a[11][N];
void bing(vector<node> &x,node *y)
{
    vector<node> z;
    int zz=1;
    for(node xx:x)
    {
        while(zz<=n&&y[zz].w<xx.w) z.push_back(y[zz++]);
        z.push_back(xx);
    }
    swap(x,z);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>bian[i].u>>bian[i].v>>bian[i].w;
    sort(bian+1,bian+m+1,[&](node x,node y){return x.w<y.w;});
    for(int i=1;i<=n;i++) f[i]=i;
    int cnt=0;
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int u=bian[i].u,v=bian[i].v,w=bian[i].w;
        int x=find(u),y=find(v);
        if(x!=y)
        {
            f[x]=y,ans+=w,b[++cnt]={u,v,w};
        }
    }
    for(int i=1;i<=k;i++)
    {
        cin>>val[i];
        for(int j=1;j<=n;j++)
        {
            int xx;
            cin>>xx;
            a[i][j]={i+n,j,xx};
        }
        sort(a[i]+1,a[i]+n+1,[&](node x,node y){return x.w<y.w;});
    }
    for(int ii=1;ii<(1<<k);ii++)
    {
        long long js=0;
        vector<node> c;
        for(int i=1;i<=cnt;i++) c.push_back(b[i]);
        for(int i=1;i<=k;i++)
            if((ii>>i-1)&1)
                bing(c,a[i]),js+=val[i];
        for(int i=1;i<=n+k;i++) f[i]=i;
        for(node xx:c)
        {
            int u=xx.u,v=xx.v;
            int x=find(u),y=find(v);
            if(x!=y)
            {
                js+=xx.w,f[x]=y;
            }
            if(js>ans) break;
        }
        ans=min(ans,js);
    }
    cout<<ans;
    return 0;
}