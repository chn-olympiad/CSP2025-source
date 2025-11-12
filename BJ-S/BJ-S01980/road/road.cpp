#include<bits/stdc++.h>
#define ll long long
#define void inline void
using namespace std;
const int N=1e4+20,M=1e6+20;
int n,m,k;
struct edge{
    int u,v,w;
    bool operator<(const edge &rhs)const{
        return w<rhs.w;
    }
}edg[M],cst[N],nedg[N*15];
int cstcnt,edgcnt;
struct dsu{
    int fa[N],sz[N],cnt;
    ll ans;
    void clear(){
        ans=cnt=0;
        for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
    }
    int anc(int x){
        if(fa[x]==x)return x;
        return fa[x]=anc(fa[x]);
    }
    inline bool cnct(int x,int y,int w){
        x=anc(x),y=anc(y);
        if(x==y)return false;
        //cout<<"::"<<x<<" "<<y<<" "<<w<<'\n';
        if(sz[x]>sz[y])swap(x,y);
        fa[x]=y;sz[y]+=sz[x];
        ans+=w;
        cnt++;
        return true;
    }
}dsu;
ll anss=0;
int cost[N];
int a[12][N];
void solve(){
    sort(nedg+1,nedg+edgcnt+1);
    dsu.clear();
    for(int i=1;i<=edgcnt;i++)
        dsu.cnct(nedg[i].u,nedg[i].v,nedg[i].w);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>edg[i].u>>edg[i].v>>edg[i].w;
    sort(edg+1,edg+m+1);
    dsu.clear();
    for(int i=1;i<=m;i++){
        if(dsu.cnct(edg[i].u,edg[i].v,edg[i].w))
            cst[++cstcnt]=edg[i];
        if(dsu.cnt==n-1)
            break;
    }
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    anss=dsu.ans;
    for(int i=1;i<(1<<k);i++){
        edgcnt=0;
        for(int j=1;j<n;j++)nedg[++edgcnt]=cst[j];
        ll now=0;
        for(int j=1;j<=k;j++){
            if((i&(1<<(j-1)))==0)
                continue;
            now+=cost[j];
            for(int l=1;l<=n;l++)
                nedg[++edgcnt]={j+n,l,a[j][l]};
        }
        solve();
        //cout<<"~~"<<dsu.cnt<<'\n';
        //cout<<"!!"<<k<<" "<<now+dsu.ans<<'\n';
        anss=min(anss,now+dsu.ans);
    }
    cout<<anss;
    return 0;
}
