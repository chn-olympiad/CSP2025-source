 #include <bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
#define endl "\n"
#define print(x) cerr<<#x<<"="<<x<<"\n"
#define dbg() cerr<<"LINE "<<__LINE__<<"\n"
using namespace std;
const int inf=1e18;
int n,m,k,N,c[111],fa[1111111],sz[1111111];
bool flag[1111111];
struct Edge{
    int u,v,w,t;
};
bool cmp(Edge x,Edge y){
    if(x.w==y.w)return x.t<y.t;
    return x.w<y.w;
}
vector<Edge> e;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int rx=find(x),ry=find(y);
    if(sz[rx]>sz[ry])swap(rx,ry);
    sz[ry]+=sz[rx];
    fa[rx]=ry;
}
int cal(int mask){
    for(int i=1;i<=N;i++)fa[i]=i;
    int ret=0;
    for(int i=1;i<=k;i++){
        if(mask&(1<<i)){
            ret+=c[i];
        }
    }
    for(int i=0;i<e.size();i++){
        int u=e[i].u,v=e[i].v,w=e[i].w,t=e[i].t;
        if(t!=0)flag[i]=1;
        if((1&(mask>>t))==0&&t!=0)continue;
        if(find(u)!=find(v)){
            ret+=w;
            merge(u,v);
            if(mask==0){
                flag[i]=1;
            }
        }
    }
    return ret;
}
signed main(){
    //16:35 AC?
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    N=n+k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w,0});
    }
    for(int i=1;i<=N;i++){
        fa[i]=i;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            e.push_back({j,n+i,tmp,i});
        }
    }
    sort(e.begin(),e.end(),cmp);
    cal(0);
    vector<Edge> tmp;
    for(int i=0;i<e.size();i++){
        if(flag[i]){
            tmp.push_back(e[i]);
        }
    }
    e=tmp;
    //sort(e.begin(),e.end(),cmp);
    int ans=inf;
    for(int i=0;i<(1<<k);i++){
        ans=min(ans,cal(i*2));
    }
    cout<<ans;
    return 0;
}
