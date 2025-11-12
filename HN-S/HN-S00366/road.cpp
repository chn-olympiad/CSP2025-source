#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=1e4+5,INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,number;
ll ans;
int a[12][MAXN],vis[MAXN],c[MAXN];
struct node{
    int u,v,w,typ;
    bool operator<(const node &b) const{
        return w>b.w;
    }
}b[12][MAXN];
vector<node>vec[MAXN];
priority_queue<node>q,r[12];
bool cmp(node a,node b){return a.w<b.w;}//small->big
void add(int u,int v,int w){
    vec[u].push_back({u,v,w,0}),vec[v].push_back({v,u,w,0});
}
void init(){
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) r[i].push(b[i][j]);
    for(int i=1;i<=n;i++) sort(vec[i].begin(),vec[i].end(),cmp);
    // for(int i=1;i<=k;i++) cout<<r[i].top().w<<'\n';
}
void add0(int u){
    for(auto v:vec[u])
        if(!vis[v.v]) q.push(v);
}
void add1(int u){
    for(int i=1;i<=k;i++)
        while(r[i].size() && vis[r[i].top().v]) r[i].pop();
    int loc=0;ll mini=INF;
    for(int i=1;i<=k;i++) if(r[i].size() && mini>r[i].top().w+a[loc][u]) mini=r[i].top().w+a[loc][u],loc=i;
    if(loc) q.push((node){u,r[loc].top().v,r[loc].top().w+a[loc][u],1});
}
void solve(){
    vis[1]=1,number=1;
    add1(1),add0(1);
    while(number<n){
        while(q.size() && vis[q.top().v]) q.pop();
        node u=q.top();ans+=(ll)u.w,vis[u.v]=1,number++;
        // cout<<u.w<<"qwq\n";
        add0(u.v),add1(u.v);
        if(u.typ==1) add1(u.u);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,add(u,v,w);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j],b[i][j]=(node){0,j,a[i][j]+c[i],1};
    }
    init(),solve();
    cout<<ans<<'\n';
}