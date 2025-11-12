#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+1145;
int ans,cntb,n,m,k,f[N],c[N],v[N],o[1025];
tuple<int,int,int>a[N],b[N],cxy[11][N],t[N];
int fd(int x)
{
    if(f[x]==x)return x;
    return f[x]=fd(f[x]);
}
queue<tuple<int,int,int>>p,q,hmx[1025];

int dfs()
{
    for(int i=1;i<=n;i++){f[i]=i;}
    while(q.size())q.pop();
    int cnt=0;
    while(p.size())
    {
        auto[x,y,z]=p.front();p.pop();
        int fy=fd(y),fz=fd(z);
        if(fy==fz)continue;
        cnt+=x;f[fy]=fz;q.push({x,y,z});
    }
    return cnt;
}

signed main()
{
    freopen("road2.in","r",stdin);
    freopen("road1.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        a[i]={z,x,y};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int x;cin>>x;
            cxy[i][j]={x,i+n,j};
        }
    }
    sort(a+1,a+1+m);int cnt=0;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        auto[x,y,z]=a[i];
        int fy=fd(y),fz=fd(z);
        if(fy==fz){v[i]=1;continue;}
        ans+=x;f[fy]=fz;
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;i++)
    {
        if(!v[i])hmx[0].push(a[i]);
    }
    for(int i=1;i<(1<<k);i++)
    {
        int u=0,v=0;
        for(int j=1;j<=k;j++)
        {
            if(i&(1<<(j-1))){u=j;v=(1<<(j-1));break;}
        }
        p=hmx[i-v];int cnt1=0;
        while(p.size())t[++cnt1]=p.front(),p.pop();
        for(int j=1;j<=n;j++)t[++cnt1]=cxy[u][j];
        sort(t+1,t+1+cnt1);//cout<<cnt1<<endl;
        for(int j=1;j<=cnt1;j++)p.push(t[j]);
        o[i]=o[i-v]+c[u];int h=dfs();hmx[i]=q;
        ans=min(ans,h+o[i]);
    }
    cout<<ans;
    return 0;
}
