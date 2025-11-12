#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[15][10005],dis[10015];
long long ans=LONG_LONG_MAX;
struct edge{int x,y,z;}e[1000005],d[110005];
bool flag[10015];
int fa[10015],tot;
int find(int x)
{
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>x>>y>>z,e[i]={x,y,z};
    sort(e+1,e+m+1,[](edge x,edge y){return x.z<y.z;});
    iota(fa+1,fa+n+1,1);
    for(int i=1;i<=m;i++)
    {
        if(find(e[i].x)==find(e[i].y))continue;
        fa[find(e[i].x)]=find(e[i].y);
        d[++tot]=e[i];
        if(tot==n-1)break;
    }
    for(int i=1;i<=k;i++)
        for(int j=0;j<=n;j++)
        {
            cin>>a[i][j];
            if(j)d[++tot]={j,n+i,a[i][j]};
        }
    sort(d+1,d+tot+1,[](edge x,edge y){return x.z<y.z;});
    for(int s=0;s<(1<<k);s++)
    {
        long long sum=0,cnt=0;
        for(int i=1;i<=k;i++)
            if(s&(1<<i-1))
                sum+=a[i][0];
        iota(fa+1,fa+n+k+1,1);
        int v=n+__builtin_popcount(s);
        for(int i=1;i<=tot;i++)
        {
            if(d[i].y>n&&!(s&1<<d[i].y-n-1))continue;
            if(find(d[i].x)==find(d[i].y))continue;
            fa[find(d[i].x)]=find(d[i].y);
            cnt++;
            sum+=d[i].z;
            if(cnt==v)break;
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
/*
g++ road.cpp -o road
road.exe

// freopen("road.in","r",stdin);
// freopen("road.out","w",stdout);
// freopen("road.in","r",stdin);
// freopen("road.out","w",stdout);
// freopen("road.in","r",stdin);
// freopen("road.out","w",stdout);
// freopen("road.in","r",stdin);
// freopen("road.out","w",stdout);
// freopen("road.in","r",stdin);
// freopen("road.out","w",stdout);

zmx ak ioi

luogu/atcoder/cf:zzwdsj
*/