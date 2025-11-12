#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+25,maxm=1e6+5;

struct eg{
    int u,v;
    ll w;
}g[maxm],e[maxn],ek[15][maxn];

int n,m,k;
int us[15],st[15];

int cnt;

bool cmp(eg a,eg b){
    return a.w<b.w;
}

int ft[maxn],sz[maxn];
ll ans;
ll c[15];

int fd(int x){
    return ft[x]==x?x:ft[x]=fd(ft[x]);
}

void mg(int x,int y){
    x=fd(x),y=fd(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    ft[y]=x;
    sz[x]+=sz[y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        g[i]=eg{u,v,w};
    }
    sort(g+1,g+1+m,cmp);
    for(int i=1;i<=n;i++)ft[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++){
        if(fd(g[i].u)==fd(g[i].v))continue;
        e[++cnt]=g[i];
        ans+=g[i].w;
        mg(g[i].u,g[i].v);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>ek[i][j].w,ek[i][j].u=i+n,ek[i][j].v=j;
        sort(ek[i]+1,ek[i]+1+n,cmp);
    }
    for(int i=1;i<(1<<k);i++){
        ll s=0;
        int ck=0;
        for(int j=0;j<k;j++)
            if((i>>j)&1)us[++ck]=j+1,st[ck]=1,s+=c[j+1];
        for(int i=1;i<=n+k;i++)ft[i]=i,sz[i]=1;
        int ps=1;
        cnt=0;
        while(cnt<n+ck-1){
            int mu,mv;
            ll mw=1e10;
            for(int i=1;i<=ck;i++){
                while(st[i]<=n&&fd(ek[us[i]][st[i]].u)==fd(ek[us[i]][st[i]].v))st[i]++;
                if(st[i]<=n&&mw>ek[us[i]][st[i]].w)
                    mw=ek[us[i]][st[i]].w,mu=ek[us[i]][st[i]].u,mv=ek[us[i]][st[i]].v;
            }
            while(ps<n&&fd(e[ps].u)==fd(e[ps].v))ps++;
            if(ps<n&&e[ps].w<mw)mw=e[ps].w,mu=e[ps].u,mv=e[ps].v,ps++;
            cnt++;
            s+=mw;
            mg(mu,mv);
        }
        ans=min(ans,s);
    }
    cout<<ans;
    return 0;
}
