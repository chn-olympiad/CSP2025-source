#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+55;
const int M=1e6+55;
struct Node
{
    int u,v,w;
}p[M];
int c[15];
int fa[N];
int a[15][N];
int u[M],v[M],w[M];
vector<pair<int,int> > G[N];
int findRT(int x)
{
    if(fa[x]==x) return fa[x];
    return fa[x]=findRT(fa[x]);
}
void merge(int x,int y)
{
    int fx=findRT(x);
    int fy=findRT(y);
    fa[fx]=fy;
}
bool cmp(Node x,Node y)
{
    return x.w<y.w;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        G[u[i]].push_back(make_pair(v[i],w[i]));
        G[v[i]].push_back(make_pair(u[i],w[i]));
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans=0;
    for(int i=1;i<=m;i++) p[i]=Node{u[i],v[i],w[i]};
    sort(p+1,p+m+1,cmp);
    int cnt=0;
    int M=0;
    for(int i=1;i<=m;i++)
    {
        int U=p[i].u,V=p[i].v;
        if(findRT(U)!=findRT(V))
        {
            merge(U,V);
            cnt++;
            ans+=p[i].w;
            M++;
            u[M]=U,v[M]=V,w[M]=p[i].w;
        }
        if(cnt==n-1) break;
    }
    for(int i=1;i<=M;i++) p[i]=Node{u[i],v[i],w[i]};
    m=M;
    for(int P=0;P<(1<<k);P++)
    {
        M=m;
        int sum=0;
        int ccnt=n;
        for(int i=1;i<=M;i++) p[i]=Node{u[i],v[i],w[i]};
        for(int j=1;j<=k;j++)
        {
            if((P>>(j-1))&1)
            {
                sum+=c[j];
                ccnt++;
                for(int x=1;x<=n;x++) p[++M]=Node{ccnt,x,a[j][x]};
            }
        }
        for(int i=1;i<=n+ccnt;i++) fa[i]=i;
        sort(p+1,p+M+1,cmp);
        int Cnt=0;
        for(int i=1;i<=M;i++)
        {
            int U=p[i].u,V=p[i].v;
            if(findRT(U)!=findRT(V))
            {
                merge(U,V);
                Cnt++;
                sum+=p[i].w;
            }
            if(Cnt==n+ccnt-1) break;
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
