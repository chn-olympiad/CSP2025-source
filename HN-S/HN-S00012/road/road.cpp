#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn=2e6+17;
using ll=long long;
int n,m,k,c[13],W[13][10007];
ll f[13];
struct dsu{
    int fa[maxn];
    void init(int n){ for(int i=1;i<=n;i++) fa[i]=i; }
    int find(int x){  while(x!=fa[x]) x=fa[x]=fa[fa[x]]; return x;}
}s;
struct edge{
    int u,v,w;
    bool operator<(const edge &o)const{return w<o.w;}
}E[maxn];
vector<edge>e,tmp;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        E[i]={u,v,w};
    }
    sort(E+1,E+m+1); s.init(n);
    for(int i=1;i<=m;i++){
        int u=E[i].u,v=E[i].v,w=E[i].w;
        int fu=s.find(u),fv=s.find(v);
        if(fu!=fv){
            s.fa[fv]=fu;
            e.push_back({u,v,w});
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>W[i][j];
        } 
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<(1<<k);i++){
        ll sum=0; tmp=e;
        for(int j=1;j<=k;j++){
            if(i>>(j-1)&1){
                sum+=c[j];
                for(int l=1;l<=n;l++){
                    tmp.push_back({n+j,l,W[j][l]});
                }
            }
        }
        sort(tmp.begin(),tmp.end()); s.init(n+k);
        for(auto j:tmp){
            int u=j.u,v=j.v,w=j.w;
            int fu=s.find(u),fv=s.find(v);
            if(fu!=fv){
                s.fa[fv]=fu;
                sum+=w;
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}