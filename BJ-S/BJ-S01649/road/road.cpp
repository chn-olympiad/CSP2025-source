#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
using namespace std;
struct edge{
    int u,v,w,id;
    bool operator<(edge x)const{
        return w<x.w;
    }
};
int n,m,k;
struct node{
    int c;
    int a[10005];
}S[15];
vector<edge> G;
bool C[15];
bool vis[20005];
int kur(int n){
    memset(vis,0,sizeof(vis));
    int cnt=0,ans=0;
    for(auto i:G){
        if(C[i.id]==0||(vis[i.u]&&vis[i.v])) continue;
        cnt++;
        ans+=i.w;
        vis[i.u]=vis[i.v]=1;
        if(cnt==n-1){
            return ans;
        }
    }
    return 1e18;
}
int ans=1e18;
void dfs(int d){
    if(d>k){
        int cost=0;
        int len=n;
        for(int i=1;i<=k;i++){
            if(C[i]){
                cost+=S[i].c;
                len++;
            }
        }
        if(cost>=ans) return;
        cost+=kur(len);
        ans=min(ans,cost);
        return;
    }
    for(int i=0;i<2;i++){
        C[d]=i;
        dfs(d+1);
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G.pb({u,v,w,0});
    }
    if(k==0){
        C[0]=1;
        sort(G.begin(),G.end());
        cout<<kur(n)<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++){
        cin>>S[i].c;
        for(int j=1;j<=n;j++){
            cin>>S[i].a[j];
            G.pb({n+i,j,S[i].a[j],i});
        }
    }
    sort(G.begin(),G.end());
    C[0]=1;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}