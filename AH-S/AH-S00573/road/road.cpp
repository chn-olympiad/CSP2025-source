#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
struct node{
    ll u,v,w;
}a[1200005],b[1200005];
ll c[15][12005];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int fa[12005];
void init()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x)
{
    if(x==fa[x])
        return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    fa[y]=x;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
bool path[15];
ll mi=1e17;
ll mm,nn,kk;
void check()
{
    m=mm;
    n=nn;
    memcpy(a,b,sizeof(a));
    ll ans=0;
    for(int i=1;i<=k;i++)
        if(path[i])
        {
            n++;
            for(int j=1;j<=nn;j++)
            {
                a[++m].u=n;
                a[m].v=j;
                a[m].w=c[i][j];
            }
            ans+=c[i][0];
        }
    if(ans>=mi)
        return;
    init();
    sort(a+1,a+1+m,cmp);
    int cnt1=0;
    for(int i=1;i<=m;i++)
    {
        if(!same(a[i].u,a[i].v))
        {
            unite(a[i].u,a[i].v);
            ans+=a[i].w;
            cnt1++;
            if(ans>=mi)
                return;
        }
    }
    mi=min(mi,ans);
}
void dfs(int pos)
{
    if(pos>k)
    {
        check();
        return;
    }
    path[pos]=0;
    dfs(pos+1);
    path[pos]=1;
    dfs(pos+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        scanf("%lld %lld %lld",&a[i].u,&a[i].v,&a[i].w);
    //sort(a+1,a+1+m,cmp);
    memcpy(b,a,sizeof(b));
    mm=m;
    nn=n;
    kk=k;
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&c[i][0]);
        for(int j=1;j<=n;j++)
            scanf("%lld",&c[i][j]);
    }
    /*
    do
    {
        //check();
        int jjj=1;
        if(path[1]==0)
            path[1]=1;
        else
        {
            while(path[jjj]==1)
            {
                path[jjj]=0;
                jjj++;
            }
            path[jjj]=1;
        }

        cout<<"path[n+1]="<<path[n+1]<<"\n";
    }while(path[n+1]==1);
    */
    dfs(1);
    cout<<mi;
    return 0;
}
