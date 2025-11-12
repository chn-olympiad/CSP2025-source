#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15;
const int M=1e6+5;
struct edge{
    int u;
    int v;
    int w;
    bool operator <(const edge &b) const{
        return w<b.w;
    }
};
vector<edge> e;
vector<edge> v;
vector<edge> p[15];
int pa[N],sz[N];
int c[15];
int get_fa(int x){
    if(x==pa[x]) return x;
    else return pa[x]=get_fa(pa[x]);
}
int ans=0;
int n,m,k,ksum,cnt,sum;
inline void init(){
    for(int i=1;i<=n+k;i++){
        sz[i]=1;
        pa[i]=i;
    }
}
int lx=0;
void dfs(int i){
    // cout<<v.size()<<"****\n";
    // cout<<(lx++)<<"****\n";
    auto tmp=v;
    if(i!=k) dfs(i+1);
    v=tmp;
    //use it
    ksum++;
    sum+=c[i];
    vector<edge> nwv;
    int szv=v.size();
    int szp=p[i].size();
    nwv.reserve(szv+szp);
    int iv=0,ip=0;
    vector<edge> q=p[i];
    while(iv<szv&&ip<szp){
        if(v[iv]<q[ip]){
            nwv.push_back(v[iv]);
            iv++;
        }else{
            nwv.push_back(q[ip]);
            ip++;
        }
    }
    while(iv<szv){
        nwv.push_back(v[iv]);
        iv++;
    }
    while(ip<szp){
        nwv.push_back(q[ip]);
        ip++;
    }
    init();
    v.clear();
    v.reserve(ksum-1);
    int cnt=0,res=0;
    for(auto i:nwv){
        // cout<<i.u<<" "<<i.v<<" "<<i.w<<"****\n";
        if(cnt==ksum-1) break;
        int uu=get_fa(i.u),vv=get_fa(i.v);
        if(uu==vv) continue;
        v.push_back(i);
        if(sz[uu]<sz[vv]) swap(uu,vv);
        pa[vv]=uu;
        sz[uu]+=sz[vv];
        cnt++;
        res+=i.w;
    }
    ans=min(ans,res+sum);
    // cout<<i<<" "<<res<<" "<<sum<<"****\n";
    if(i!=k) dfs(i+1);
    sum-=c[i];
    v=tmp;
    //not use it

}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    ksum=n;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            p[i].push_back({n+i,j,w});
        }
        sort(p[i].begin(),p[i].end());
    }
    int cnt=0;
    init();
    sort(e.begin(),e.end());
    for(auto i:e){
        if(cnt==n-1) break;
        int uu=get_fa(i.u),vv=get_fa(i.v);
        if(uu==vv) continue;
        v.push_back({i.u,i.v,i.w});
        ans+=i.w;
        if(sz[uu]<sz[vv]) swap(uu,vv);
        pa[vv]=uu;
        sz[uu]+=sz[vv];
        cnt++;
    }
    dfs(1);
    cout<<ans<<"\n";
}