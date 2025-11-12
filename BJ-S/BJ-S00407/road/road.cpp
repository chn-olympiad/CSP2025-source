// T2 100p
//O(m log m + n2^kalpha(n))
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int SZ=1500,N=1e4+50;
struct edge{
    int u,v,w;
    bool operator<(const edge &rh) const{
        return w<rh.w;
    }
};
int n,m,k;
vector<edge> e[SZ],et[15],te,tmp,tmp2;
int fa[N],c[N],a[15][N];
int lb(int x){return x&(-x);}
int fd(int x){return (x==fa[x])?(x):(fa[x]=fd(fa[x]));}
bool mrg(int x,int y){
    x=fd(x),y=fd(y);
    if(x==y) return 0;
    fa[x]=y;return 1;
}
void init(){for(int i=1;i<=n+k;i++) fa[i]=i;}
void mst(const vector<edge> &eg){
    tmp.clear();tmp.shrink_to_fit();
    init();
    for(auto ed:eg){
        if(mrg(ed.u,ed.v)){
            tmp.push_back(ed);
        } 
    }
}
void merge(const vector<edge> &a,const vector<edge> &b){
    tmp.clear();tmp.shrink_to_fit();
    int it1=0,it2=0;
    while(it1<a.size()&&it2<b.size()){
        if(a[it1]<b[it2]) tmp.push_back(a[it1++]);
        else tmp.push_back(b[it2++]);
    }
    while(it1<a.size()) tmp.push_back(a[it1++]);
    while(it2<b.size()) tmp.push_back(b[it2++]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    int U=(1<<k)-1;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        te.push_back((edge){u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
        for(int j=1;j<=n;j++) et[i].push_back((edge){i+n,j,a[i][j]});
        sort(et[i].begin(),et[i].end());
    }
    sort(te.begin(),te.end());
    mst(te);e[0]=tmp;ll ans=0;
    for(auto ed:e[0]) ans+=ed.w;
    for(int i=1;i<=U;i++){
        int id=0;ll res=0;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){id=j;break;}
        }
        merge(et[id],e[i-lb(i)]);tmp2=tmp;
        //cout<<i<<endl;
        //for(auto ed:tmp2) cout<<ed.u<<' '<<ed.v<<' '<<ed.w<<endl;
        mst(tmp2);e[i]=tmp;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1) res+=c[j];
        }
        for(auto ed:e[i]) res+=ed.w;//cout<<ed.w<<' ';
        ans=min(ans,res);
    }cout<<ans<<endl;
    return 0;
} 