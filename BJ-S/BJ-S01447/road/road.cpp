#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
using ll=long long;
int n,m,k,c[15],ac[15][10005],fa[20005];
ll ans;
bool v[15];
struct eg{int u,v,w;};
vector<eg> a,b;
void init(int n){for(int i=1;i<=n;i++) fa[i]=i;}
int getfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
    x=getfa(x),y=getfa(y);
    fa[x]=y;
}
void dfs(int x){
    if(x>k){
        b=a;
        int cnt=n; ll sum=0;
        for(int i=1;i<=k;i++) if(v[i]){
            sum+=c[i],cnt++;
            for(int j=1;j<=n;j++) b.push_back({cnt,j,ac[i][j]});
        }
        if(sum>ans) return;
        init(cnt),sort(b.begin(),b.end(),[](eg a,eg b){return a.w<b.w;});
        for(eg u:b){
            if(getfa(u.u)!=getfa(u.v)) sum+=u.w,merge(u.u,u.v);
            if(sum>ans) return;
        }
        ans=sum;
        return;
    }
    v[x]=true,dfs(x+1);
    v[x]=false,dfs(x+1);
}
int main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        a.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>ac[i][j];
    }
    init(n),sort(a.begin(),a.end(),[](eg a,eg b){return a.w<b.w;});
    for(eg u:a) if(getfa(u.u)!=getfa(u.v)) ans+=u.w,merge(u.u,u.v);
    dfs(1);
    cout<<ans<<endl;
    return 0;
}