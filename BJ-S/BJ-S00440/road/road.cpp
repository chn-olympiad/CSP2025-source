#include<bits/stdc++.h>
using namespace std;
const long long M=2e6+5;
struct node
{
    long long u,v,w,id;
}a[M];
long long n,e,now,k,ans=1e18;
long long v[M],f[M],c[M],nows;
long long find(long long x)
{
    // cerr<<x<<endl;
    if(f[x]==0) return x;
    return f[x]=find(f[x]);
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
long long ks()
{
    long long s=0,y=0,i;
    for(i=1;i<=n+k;i++)
    {
        f[i]=0;
    }
    for(i=1;i<=e;i++)
    {
        if(v[a[i].id]==0)
        {
            continue;
        }
        long long fx=find(a[i].u),fy=find(a[i].v);
        if(fx==fy) continue;
        f[fx]=fy;
        y++;
        s+=a[i].w;
        if(y==n+now-1) return s;
    }
    return 1e18;
}
void cv(long long x)
{
    if(x==k+1)
    {
        // for(int i=1;i<=k;i++) nows+=(v[i]==1)*(c[i]);
        ans=min(ans,ks()+nows);
        // cerr<<ks()<<" "<<now<<" "<<nows<<"\n";
        return ;
    }
    v[x]=0;
    cv(x+1);
    now++;
    nows+=c[x];
    v[x]=1;
    cv(x+1);
    nows-=c[x];
    now--;
    v[x]=0;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    long long i,j,m,l,r,x,y,o,s=0,E;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>o;
        a[++e]={x,y,o,0};
    }
    for(i=1;i<=k;i++)
    {
        cin>>c[i];
        for(j=1;j<=n;j++)
        {
            cin>>x;
            a[++e]={n+i,j,x,i};
        }
    }
    // cerr<<n+k<<endl;
    sort(a+1,a+e+1,cmp);
    v[0]=1;
    // now=k;
    // for(i=1;i<=k;i++) v[i]=1;
    // cerr<<a[1].u<<" "<<a[1].v<<" "<<a[1].w<<" "<<a[1].id<<"\n";
    // cout<<ks()<<"\n";
    // return 0;
    cv(1);
    cout<<ans<<"\n";
    return 0;
}