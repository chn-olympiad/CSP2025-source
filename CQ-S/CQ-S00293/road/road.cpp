#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pr pair<int,int>
#define mk make_pair
#define lc x<<1
#define rc x<<1|1
#define N 105050
int n,m,k,f[N],sz[N],all;
ll ans=0x3f3f3f3f3f3f3f3fll;
struct node{
    int u,v,w;
    node(){
        u=v=w=0;
    }
    node(int _u,int _v,int _w){u=_u,v=_v,w=_w;}
    bool operator<(const node b)const {
        return w<b.w;
    }
}e[N*20];
vector<int>now,a[10],sta[10],tmp;
int c[N],tot;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return false;
    if(sz[x]>sz[y])swap(x,y);
    f[x]=y;sz[y]+=sz[x];
    return true;
}   
vector<int> merge(vector<int>&a,vector<int>&b){
    vector<int>now;
    int x=0,y=0;
    while(x<a.size()&&y<b.size()){
        if(e[a[x]].w<e[b[y]].w)now.emplace_back(a[x]),++x;
        else now.emplace_back(b[y]),++y;
    }
    while(x<a.size())now.emplace_back(a[x]),++x;
    while(y<b.size())now.emplace_back(b[y]),++y;
    return now;
}
bool cmp(int x,int y){return e[x].w<e[y].w;}
void dfs(int dep,ll s){
    if(dep==k){
        for(int i=0;i<n+k;++i)f[i]=i,sz[i]=1;tmp.clear();
        for(int i:now)if(merge(e[i].u,e[i].v)){
            s+=e[i].w;
            tmp.push_back(i);
        }
        now=tmp;
        ans=min(ans,s);
        return ;
    }
    dfs(dep+1,s);
    sta[dep]=now;
    now=merge(now,a[dep]);
    dfs(dep+1,s+c[dep]);
    now=sta[dep];
}
signed main(){
    clock_t st=clock();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0,u,v,w;i<m;++i){
        cin>>u>>v>>w;
        --u,--v;
        now.push_back(++tot);
        e[tot]=node(u,v,w);
    }    
    sort(now.begin(),now.end(),cmp);
    for(int i=0;i<k;++i){
        cin>>c[i];
        for(int j=0;j<n;++j){
            int w;cin>>w;
            a[i].emplace_back(++tot);
            e[tot]=node(i+n,j,w);
        }
        sort(a[i].begin(),a[i].end(),cmp);
    }    
    dfs(0,0);
    cout<<ans<<"\n";
    cerr<<fixed<<setprecision(10)<<(double)(clock()-st)/CLOCKS_PER_SEC<<"\n";
}