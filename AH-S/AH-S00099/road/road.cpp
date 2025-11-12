/*

       2025.11.1

 * Happy Zenith Noises *

*/
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int>P;
typedef long long ll;
const int MAXN=110005;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,cnt;ll ans=inf;
struct node{
    int x,y,z;
}a[MAXN*10],b[MAXN],c[MAXN],p[MAXN],g[15][MAXN];
vector<node>t[1<<10];
struct node2{
    int fa[MAXN];
    void init(){for(int i=1;i<=n+k;i++)fa[i]=i;}
    int gt(int x){return ((fa[x]==x)?x:fa[x]=gt(fa[x]));}
    int merge(int x,int y){x=gt(x),y=gt(y);if(x==y)return 0;fa[x]=y;return 1;}
}tr;
bool cmp(node x,node y){
    return x.z<y.z;
}
bool vis[MAXN];
int d[15],fs[15][MAXN];
void dfs(int x,int tmp,ll cst,int mask){
    if(x==k+1){
        ll s=cst;
        tr.init();
        int tl=1,tr=1,cnt=0;
        while(tl<=tmp||tr<n){
            if(tr==n||tl<=tmp&&c[tl].z<b[tr].z)p[++cnt]=c[tl++];
            else p[++cnt]=b[tr++];
        }
        for(int i=1;i<=cnt;i++)if(::tr.merge(p[i].x,p[i].y))s+=p[i].z;
        ans=min(ans,s);
        return ;
    }
    dfs(x+1,tmp,cst,mask);
    if(t[mask].size()==0){
        t[mask].pb(node{0,0,0});
        for(int i=1;i<=tmp;i++)t[mask].pb(c[i]);
    }
    //for(int i=1;i<=tmp;i++)t[i]=c[i];
    int tl=1,tr=1,cnt=0;
    while(tl<=tmp||tr<=n){
        if(tr==n+1||tl<=tmp&&t[mask][tl].z<g[x][tr].z)c[++cnt]=t[mask][tl++];
        else c[++cnt]=g[x][tr++];
    }
    dfs(x+1,tmp+n,cst+d[x],mask+(1<<x-1));
    for(int i=1;i<=tmp;i++)c[i]=t[mask][i];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
    sort(a+1,a+1+m,cmp);tr.init();
    for(int i=1;i<=m;i++)if(tr.merge(a[i].x,a[i].y))vis[i]=1;
    for(int i=1;i<=m;i++)if(vis[i])b[++cnt]=a[i];
    for(int i=1;i<=k;i++){
        cin>>d[i];
        for(int j=1;j<=n;j++)cin>>fs[i][j],g[i][j]=node{n+i,j,fs[i][j]};
        sort(g[i]+1,g[i]+1+n,cmp);
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}

