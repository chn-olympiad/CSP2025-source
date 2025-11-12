#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define fi first
#define se second
#define Il inline
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef double db;
const int N=2e4,M=2e6,Inf=1e18;
const db eps=1e-9;

// bool P1;

int n,m,K,fa[N+5],a[15][N+5],in=0,ans=Inf,c[N+5];
pii mn[N+5];
struct Node{
    int x,y,w;
    Il bool operator <(const Node &s)const{
        return w<s.w;
    }
}ed[M+5];

Il int find(int p){
    return fa[p]^p?fa[p]=find(fa[p]):p;
}

Il bool check1(){
    for(int i=1;i<=K;i++){
        bool ok=1;
        if(c[i])return 0;
        for(int j=1;j<=n;j++){
            if(!a[i][j]){
                ok=0;
            }
        }
        if(ok)return 0;
    }
    return 1;
}

Il int solve(int z){
    int t=0;
    for(int i=1;i<=K;i++){
        if(z&(1<<(i-1))){
            t+=c[i];
        }
    }
    // cout<<"miao:"<<z<<' '<<t<<' '<<al<<'\n';
    for(int i=1;i<=n+K;i++){
        fa[i]=i;
    }
    for(int i=1;i<=in;i++){
        if(ed[i].x>n&&!(z&(1<<(ed[i].x-n-1))))continue;
        int fx=find(ed[i].x),fy=find(ed[i].y);
        if(fx==fy)continue;
        fa[fx]=fy,t+=ed[i].w;
    }
    return t;
}

// bool P2;

signed main(){
    // system("diff club5.ans club.out -Z");return 0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    cin>>n>>m>>K;
    for(int i=1;i<=n+K;i++){
        fa[i]=i;
    }
    for(int i=1;i<=n;i++){
        mn[i]={Inf,0};
    }
    for(int i=1;i<=m;i++){
        cin>>ed[i].x>>ed[i].y>>ed[i].w;
        if(ed[i].w<mn[ed[i].x].fi){
            mn[ed[i].x]={ed[i].w,ed[i].y};
        }
        if(ed[i].w<mn[ed[i].y].fi){
            mn[ed[i].y]={ed[i].w,ed[i].x};
        }
    }
    in=m;
    for(int i=1;i<=K;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j],ed[++in]={i+n,j,a[i][j]};
            // cout<<i<<' '<<j<<' '<<a[i][j]<<'\n';
        }
    }
    sort(ed+1,ed+in+1);
    if(check1()){
        cout<<solve((1<<K)-1);
        return 0;
    }
    for(int i=0;i<(1<<K);i++){
        ans=min(ans,solve(i));
    }
    cout<<ans;
    return 0;
}