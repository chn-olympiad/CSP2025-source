#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e6+10;
struct node
{
    int x,y,w;
}e[M];
bool cmp(node x,node y){return x.w<y.w;}
int n,m,k;
struct DSU
{
    int fa[N];
    void clear(){for(int i=1;i<=n+k;i++) fa[i]=i;}
    int find(int x)
    {
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){fa[find(x)]=find(y);}
}T;
int c[N];
int a[20][N];
int sort_[M];
struct edge
{
    pair<int,int> val;
    int nxt;
}b[M];
int head[M],tot;
void push(int w,int x,int y)
{
    b[++tot]={{x,y},head[w]};
    head[w]=tot;   
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        e[i]=(node){x,y,w};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1,x;j<=n;j++) cin>>a[i][j];
    }
    sort(e+1,e+1+m,cmp);
    int cnt=0;
    T.clear();
    for(int i=1;i<=m&&cnt<n-1;i++)
    {
        int x=T.find(e[i].x),y=T.find(e[i].y);
        if(x==y) continue;
        e[++cnt]=e[i],T.merge(x,y);
    }
    m=cnt,cnt=0;
    for(int i=1;i<=m;i++) sort_[++cnt]=e[i].w;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            sort_[++cnt]=a[i][j];
    sort(sort_+1,sort_+1+cnt),cnt=unique(sort_+1,sort_+1+cnt)-sort_-1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=lower_bound(sort_+1,sort_+1+cnt,a[i][j])-sort_;
    for(int i=1;i<=m;i++)
        e[i].w=lower_bound(sort_+1,sort_+1+cnt,e[i].w)-sort_;
    // return 0;
    long long ans=1e18;
    for(int s=0;s<(1<<k);s++)
    {
        tot=0;
        for(int i=1;i<=cnt;i++) head[i]=0;
        for(int i=1;i<=m;i++) push(e[i].w,e[i].x,e[i].y);
        int res=n;
        long long now=0;
        for(int i=1;i<=k;i++)
            if(s>>(i-1)&1)
            {
                res++,now+=c[i];
                for(int j=1;j<=n;j++) push(a[i][j],j,n+i);
            }
        T.clear();
        for(int i=1;i<=cnt&&now<ans&&res;i++)
            for(int j=head[i];j;j=b[j].nxt)
            {
                int x=T.find(b[j].val.first),y=T.find(b[j].val.second);
                if(x==y) continue;
                res--,now+=sort_[i],T.merge(x,y);
            }
        ans=min(ans,now);
    }
    cout<<ans;
    return 0;
}