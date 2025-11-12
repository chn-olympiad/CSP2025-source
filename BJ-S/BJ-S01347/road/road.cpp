#include<bits/stdc++.h>
using namespace std;
#define N 11451
#define M 1145141
#define ll long long
struct edge{
    int u,v;
    ll w;
    bool operator < (edge y)const{
        return w>y.w;
    }
};
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int n,m,k;
edge e[M];
ll c[N];
ll a[14][N];
int fa[N],sz[N];
void init(){
    for(int i=1;i<=n+10;i++){
        fa[i]=i,sz[i]=1;
    }
}
int find(int x){
    if(fa[x]==x) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    fa[y]=x,sz[x]+=sz[y];
}
ll solve(int opt){
    priority_queue<edge>q;
    init();
    ll ans=0;
    int add=0,cnt=0,now=1;
    for(int i=1;i<=k;i++){
        if((opt>>(i-1)&1)){
            ans+=c[i];
            add++;
            for(int j=1;j<=n;j++){
                q.push({n+i,j,a[i][j]});
            }
        }
    }
    // cout<<ans<<endl;
    while(cnt<n+add-1){
        edge i;
        if(now>m){
            i=q.top();
            q.pop();
        }else if(q.empty()){
            i=e[now++];
        }else{
            if(q.top().w<e[now].w){
                i=q.top();
                q.pop();
            }else{
                i=e[now++];
            }
        }
        if(find(i.u)==find(i.v)) continue;
        merge(i.u,i.v);
        ans+=i.w;
        cnt++;
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    ll ans=1e18;
    for(int i=0;i<(1<<k);i++){
        ll tmp=solve(i);
        // cout<<i<<' '<<tmp<<endl;
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}