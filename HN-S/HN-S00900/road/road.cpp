#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e4+10,M=2e6+10;
int n,m,tot,k,res,ans,A,lazy;
int a[N],c[11][N],vis[N],vis_edge[M],b[11],fa[N];
struct node{
    int y,w;
};
struct edge{
    int x,y,z;
}e[M],e2[M];
vector<node> g[N],g2[N];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void kul(){
    int cnt=0;ans=0;
    for(int i=1;i<=m;i++) vis_edge[i]=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=e[i].x,y=e[i].y,val=e[i].z;
        int X=find(x),Y=find(y);
        if(X==Y) continue;
        else{
            cnt++;fa[Y]=X;
            vis_edge[i]=1;
            ans+=val;
        }
        if(cnt>=n+lazy-1) return;
    }
    return;
}
bool cmp(edge A,edge B){return A.z<B.z;}
void work(int sum){
    m=tot;lazy=0;
    for(int i=1;i<=tot;i++) e[i]=e2[i];
    for(int i=1;i<=k;i++)
        if(b[i]==1){
            lazy++;
            for(int j=1;j<=n;j++) e[++m]=(edge){i+n,j,c[i][j]};
        }
    sort(e+1,e+m+1,cmp);
    kul();
    res=min(res,sum+ans);
    return;
}
void dfs(int pos,int sum){
    if(sum>=res) return;
    if(pos==k+1){
        work(sum);
        return;
    }
    for(int i=0;i<=1;i++){
        b[pos]=i;
        dfs(pos+1,sum+i*a[pos]);
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        e[i].x=x;e[i].y=y;e[i].z=z;
    }
    sort(e+1,e+m+1,cmp);
    kul();
    res=ans;
    for(int i=1;i<=m;i++)
        if(vis_edge[i]==1) e2[++tot]=e[i];
    for(int i=1;i<=tot;i++) e[i]=e2[i];
    for(int i=1;i<=k;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++) cin>>c[i][j];
    }
    dfs(1,0);
    cout<<res<<"\n";
    return 0;
}