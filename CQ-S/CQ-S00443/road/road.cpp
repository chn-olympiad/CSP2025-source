#include<bits/stdc++.h>
using namespace std;
#define N 20005
#define M 2000005
#define int long long
bool vis[N];
int n,m,k,ans,cnt,c[N],d[N];
struct edge{int x,y,w,num;}a[M],b[M];
int find(int x){return d[x]==x?x:d[x]=find(d[x]);}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k,vis[0]=1,iota(d,d+n+1,0);
    for(int i=1;i<=m;i++)  cin>>a[i].x>>a[i].y>>a[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1,w;j<=n;j++)  cin>>w,b[++cnt]={n+i,j,w,i};
    }
    sort(a+1,a+m+1,[](edge a,edge b){return a.w<b.w;});
    for(int i=1,tot=0;i<=m&&tot<n-1;i++){
        int fx=find(a[i].x),fy=find(a[i].y);
        if(fx==fy)  continue;
        d[fx]=fy,tot++,ans+=a[i].w,b[++cnt]=a[i];
    }
    sort(b+1,b+cnt+1,[](edge a,edge b){return a.w<b.w;});
    for(int i=1;i<(1<<k);i++){
        int sum=0,now=0;iota(d,d+n+k+1,0);
        for(int j=1;j<=k;j++){
            vis[j]=(i>>(j-1)&1);
            if(vis[j])  now++,sum+=c[j];
        }
        for(int j=1,tot=0;j<=cnt&&tot<n+now-1;j++){
            if(!vis[b[j].num])  continue;
            int fx=find(b[j].x),fy=find(b[j].y);
            if(fx!=fy)  d[fx]=fy,tot++,sum+=b[j].w;
        }
        ans=min(ans,sum);
    }
    cout<<ans<<"\n";
}