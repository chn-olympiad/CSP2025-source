#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
int n,m,k,I,f[N+10],c[15];
long long sum;
struct dot
{
    int u,v,w,b;
}a[100*N],d[10*N];
bool cmp(dot x,dot y)
{
    if((((1<<x.b)&I)==0)&&x.b!=-1)return 0;
    if((((1<<y.b)&I)==0)&&y.b!=-1)return 1;
    return x.w<y.w;
}
int fa(int x)
{
    if(f[x]==x)return x;
    return f[x]=fa(f[x]);
}
vector<dot>v[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
        a[i].b=-1;
        v[a[i].u].push_back({a[i].v,a[i].w});
    }
    sort(a+1,a+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)if(fa(a[i].u)!=fa(a[i].v))
    {
        f[fa(a[i].v)]=fa(a[i].u);
        sum+=a[i].w;
        d[++cnt]=a[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>d[i*n+j-1].w;
            d[i*n+j-1].u=i+n,d[i*n+j-1].v=j,d[i*n+j-1].b=i-1;
        }
    }
    bool flag=0;
    for(int i=1;i<=k;i++)if(c[i])flag=1;
    if(!flag)
    {
        I=(1<<k)-1;
        sort(d+1,d+k*n+n-1,cmp);
        long long x=0;
        for(int j=1;j<=n+k;j++)f[j]=j;
        for(int j=1;j<=k*n+n;j++)if(fa(d[j].u)!=fa(d[j].v))if((((1<<d[j].b)&I)!=0)||d[j].b==-1)
        {
            f[fa(d[j].v)]=fa(d[j].u);
            x+=d[j].w;
        }
        cout<<x;
        return 0;
    }
    for(I=1;I<(1<<k);I++)
    {

        sort(d+1,d+k*n+n-1,cmp);
        long long x=0;
        for(int j=1;j<=k;j++)if((1<<j-1)&I)x+=c[j];
        for(int j=1;j<=n+k;j++)f[j]=j;
        for(int j=1;j<=k*n+n;j++)if(fa(d[j].u)!=fa(d[j].v))if((((1<<d[j].b)&I)!=0)||d[j].b==-1)
        {
            f[fa(d[j].v)]=fa(d[j].u);
            x+=d[j].w;
        }
        sum=min(sum,x);
    }
    cout<<sum;
    return 0;
}
