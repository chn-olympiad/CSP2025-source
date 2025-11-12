#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int fa[20005];
void he(int u,int v){fa[u]=v;}
int findfa(int x){
    if(x==fa[x]) return x;
    return (fa[x]=findfa(fa[x]));
}
void init(int x){for(int i=1;i<=x;i++) fa[x]=x;}
struct edge{int to,nex,w;}e[N<<1];
int head[N<<1],cnt;
void addedge(int u,int v,int w){
    e[++cnt].nex=head[u];
    e[cnt].w=w,e[cnt].to=v;
    head[u]=cnt;
}
bool cmp(edge a,edge b){return a.w<b.w;}
int Prim(int s){
    int ans=0;
    priority_queue<int,vector<int> > q;
    q.push(s);
    while(!q.empty()){
        int u=q.top(),t,mn=1e9+7,f=0; q.pop();
        ans+=e[head[u]].w;
        for(int i=head[u];i;i=e[i].nex){
            int v=e[i].to;
            int x=findfa(u),y=findfa(v);
            if(u==v||x==y) continue;
            if(mn>e[i].w) t=v,mn=e[i].w,f=1;
        }
        if(f) q.push(t);
    }
    return ans;
}
int n,m,k,a[10][10005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        addedge(u,v,w); addedge(u,v,w);
    }
    int ans=Prim(1);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            addedge(i+n,j,a[i][j]); addedge(j,i+n,a[i][j]);
        }
        int x=Prim(1);
        if(x<ans) ans=x;
    }
    cout<<ans;
	return 0;
}
