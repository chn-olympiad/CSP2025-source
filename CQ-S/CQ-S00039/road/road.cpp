#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v;
    long long w;
};
vector<node>p[10011],p2[10011];
node a[1100001];
long long c[11],b[11][10001];
int fa[10011];
node tonode(int nu,int nv,int nw)
{
    node ret;
    ret.u=nu;
    ret.v=nv;
    ret.w=nw;
    return ret;
}
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void mer(int x,int y)
{
    fa[find(x)]=find(y);
}
bool cmp(node xx,node yy)
{
    return xx.w<yy.w;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        p[u].push_back(tonode(u,v,w));
        p[v].push_back(tonode(v,u,w));
        a[i]=tonode(u,v,w);
    }
    long long sum=0;
    for(int i=1;i<=k;i++)
    {
        fa[i+n]=i+n;
        cin>>c[i];
        sum+=c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>b[i][j];
            p[i+n].push_back(tonode(i+n,j,b[i][j]));
            p[j].push_back(tonode(j,i+n,b[i][j]));
            a[m+j+(i-1)*n]=tonode(i+n,j,b[i][j]);
        }
    }
    sort(a+1,a+m+k*n+1,cmp);
    for(int i=1;i<=m+k*n;i++)
    {
        int nu=a[i].u,nv=a[i].v,nw=a[i].w;
        if(find(nu)!=find(nv))
        {
            sum+=nw;
            p2[nu].push_back(tonode(nu,nv,nw));
            p2[nv].push_back(tonode(nv,nu,nw));
            mer(nu,nv);
            //cout<<nu<<" "<<nv<<" "<<nw<<endl;
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(p2[i+n].size()==1)
        {
            sum-=p2[i+n][0].w;
            sum-=c[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}
