#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e4+500;
struct DSU{
    int fa[N];
    void init(int n){for(int i=1;i<=n;i++) fa[i]=i;}
    int find(int x){return fa[x]=(fa[x]!=x?find(fa[x]):x);}
    bool merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return 0;
        return fa[x]=y,1;
    }
}dsu;
int n,m,ans,k,c[N],f[N];
struct node{int x,y,v;};
bool cmp(node a,node b){return a.v<b.v;}
vector<node> e;
void kelusikaer(){
    vector<node> g;
    dsu.init(n);
    for(node i:e){
        if(dsu.merge(i.x,i.y)){
            g.push_back(i);
            ans+=i.v;
        }
    }
    swap(g,e);
}
int solve(){
    dsu.init(n+k);
    int ans=0;
    for(node i:e){
        if(!f[i.x]||!f[i.y]) continue;
        if(dsu.merge(i.x,i.y)){
            ans+=i.v;
        }
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        e.push_back({x,y,z});
    }
    sort(e.begin(),e.end(),cmp);
    kelusikaer();
    for(int i=n+1,x;i<=n+k;i++){
        cin>>c[i-n];
        for(int j=1;j<=n;j++){
            cin>>x;
            e.push_back({i,j,x});
        }
    }
    sort(e.begin(),e.end(),cmp);
    for(int i=1;i<=n;i++) f[i]=1;
    for(int i=1;i<(1<<k);i++){
        int s=0;
        for(int j=1;j<=k;j++){
            f[j+n]=((i>>(j-1))&1);
            if(((i>>(j-1))&1)) s+=c[j];
        }
        ans=min(ans,solve()+s);
    }
    cout<<ans<<'\n';
    return 0;
}