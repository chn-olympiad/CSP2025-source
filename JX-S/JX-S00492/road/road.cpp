#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=2147483647,sum=0;
struct Node{
    int v;
    int w;
};
vector<Node> G[2000006];
int vis[500000];
void dfs(int u,int mum){
    if(mum==n){
        if(ans>sum){
            ans=sum;
 //           cout<<ans<<" ";
        }
        return;
    }
     for(int i=0;i<G[u].size();i++){
        Node tmp=G[u][i];
        if(vis[tmp.v]==0){
           vis[tmp.v]==1;
           cout<<sum<<" ";
           sum=sum+tmp.w;
           dfs(tmp.v,mum+1);
           vis[tmp.v]==0;
           sum=sum-tmp.w;
        }

     }

}
int main(){
 //   freopen("road.in","r",stdin);
 //   freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    vis[1]=1;
    dfs(1,1);
return 0;
}
