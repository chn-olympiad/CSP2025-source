#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000010
ll n,m,k,u,v,w,cnt,fa[N],ans;
ll a[11][N];
struct road
{
    ll u,v,val;
}e[N],cpe[N];
template<typename T>inline void read(T &x)
{
    bool f=1;x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=!f;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=(f?x:-x);return;
}
template<typename T>inline void write(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
bool cmp(road x,road y)
{
    return x.val<y.val;
}
ll find(ll x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(ll x,ll y)
{
    x=find(x),y=find(y);
    if(x!=y) fa[x]=y;
}
void clarify()
{
    cnt=n-1;
    for(int i=1;i<=cnt;i++) e[i]=cpe[i];
    for(int i=1;i<=n+k;i++) fa[i]=i;
}
ll check()
{
    for(int i=2;i<=n;i++)
    {
        if(find(i)!=find(i-1)) return 0;
    }
    return 1;
}
ll kruskal()
{
    ll cost=0;
    sort(e+1,e+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(find(e[i].u)!=find(e[i].v))
        {
            merge(e[i].u,e[i].v);
            cost+=e[i].val;
            if(cost>ans) return 999999999999;
            if(check()) return cost;
        }
    }
    return cost;
}
void work(ll sta)
{
    clarify();
    ll cost=0;
    for(int i=0;i<k;i++)
    {
        if(sta>>i&1)
        {
            cost+=a[i+1][0];
            if(cost>ans) return;
            ll u=i+1+n;
            for(int j=1;j<=n;j++) e[++cnt]={u,j,a[i+1][j]};
        }
    }
    // cout<<cost<<endl;
    // for(int i=1;i<=cnt;i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].val<<endl;
    cost+=kruskal();
    ans=min(ans,cost);
}
int main()
{   
    // double T=clock();
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for(int i=1;i<=m;i++)
    {
        read(u),read(v),read(w);
        e[i]={u,v,w};
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++) read(a[i][j]);
    }
    ll cho=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(find(e[i].u)!=find(e[i].v))
        {
            merge(e[i].u,e[i].v);
            ans+=e[i].val;
            cho++;
            cpe[++cnt]=e[i];
            if(cho==n-1) break;
        }
    }
    // cout<<ans<<" "<<cho<<endl;
    // cout<<(1<<k)-1<<endl;
    for(int sta=0;sta<(1<<k);sta++) work(sta);
    write(ans);
    // cout<<endl;
    // cout<<(clock()-T)/CLOCKS_PER_SEC;
    return 0;
}