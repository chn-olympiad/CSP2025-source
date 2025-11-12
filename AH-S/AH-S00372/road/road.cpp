#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0x3f3f3f3f,a[15][10005],c[15];
bool vis[10005];
struct Node{
    int v,w;
};
vector<Node> G[10005];
bool check(){
    for(int i=1;i<=n;i++) if(vis[i]==false) return false;
    return true;
}
void dfs(int i,int sum){
    if(check()){
        ans=min(ans,sum);
        return;
    }
    if(sum>ans) return ;
    for(int j=0;j<G[i].size();j++){
        Node t=G[i][j];
        vis[t.v]=true;
        sum+=t.w;
        dfs(t.v,sum);
        vis[t.v]=false;
        sum-=t.w;
    }

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
            int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    if(k!=0){
        bool ok=false;
        for(int i=1;i<=k;i++){
            bool f=false;
            cin>>c[i];
            if(c[i]==0) f=true;
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                if(a[i][j]!=0) f=false;
            }
            if(f==true) ok=true;
        }
        if(ok==true){
            cout<<0;
            return 0;
        }
    }
    else{
        vis[1]=true;
        dfs(1,0);
        cout<<ans;
    }
    return 0;
}
