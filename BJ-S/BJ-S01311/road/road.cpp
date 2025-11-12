#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
const int N=1e4+40,M=3e6;
int n,m,k,tot,f[N],p;
ll a[15][N];
ll ans=1e18;
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
bool vis[N],fl=1,vist[M];
struct qwq{
    int u,v;ll w; int id;
}edge1[M];
bool cmp(qwq a,qwq b) {return a.w<b.w;}
void dfs(int x){
    if(x==k+1) {
        ll cnt=0,tot=m;
        rep(i,1,k) {
            if(vis[i]){
                cnt+=a[i][0];
                if(cnt>ans) return ;
            }
            rep(j,1,n){
                ++tot;
                if(!vis[i]) vist[tot]=1;
                else vist[tot]=0;
            }

        }
        if(cnt>ans) return ;
        rep(i,1,p) f[i]=i;
        rep(i,1,tot) {
            if(vist[edge1[i].id]) continue;
            int x=edge1[i].u,y=edge1[i].v;
            ll w=edge1[i].w;
            int xx=find(x),yy=find(y);
            if(xx==yy) continue;
            f[xx]=yy;
            cnt+=w;
            if(cnt>ans) return ;
        }
        ans=min(ans,cnt);
        return ;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k; p=n;
    rep(i,1,m) {
        int u,v;ll w;
        cin>>u>>v>>w;
        edge1[++tot]=(qwq){u,v,w,tot};
    }
    rep(i,1,k) rep(j,0,n) cin>>a[i][j];
    rep(i,1,k) if(a[i][0]) fl=0;
    if(fl) {
        ll cnt=0; tot=m;
        rep(i,1,k) {
            cnt+=a[i][0]; ++p;
            rep(j,1,n)
                edge1[++tot]=(qwq){p,j,a[i][j]};
        }
        sort(edge1+1,edge1+1+tot,cmp);
        rep(i,1,p) f[i]=i;
        rep(i,1,tot) {
            int x=edge1[i].u,y=edge1[i].v;
            int xx=find(x),yy=find(y);
            if(xx==yy) continue;
            f[xx]=yy;
            cnt+=edge1[i].w;
        }
        cout<<cnt;
        return 0;
    }
    rep(i,1,m) vist[i]=0; p=n;
    rep(i,1,k) {
        ++p;
        rep(j,1,n) edge1[++tot]=(qwq){p,j,a[i][j],tot};
    }
    sort(edge1+1,edge1+1+tot,cmp);
    dfs(1);
    cout<<ans;
    return 0;
}
