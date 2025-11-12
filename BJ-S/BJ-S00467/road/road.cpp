#include<bits/stdc++.h>
using namespace std;
int n,m,k,vis[100005],xc=0;
struct Node{
int next,cost;
};
vector<Node>a[100005];
void dfs(int x,int cct){
    vis[x]=1;int f=0;
    for(auto y:a[x]){

        if(!vis[y.next]){
            f=1;
            int g=1;
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    g=0;
                }
            }if(g)break;
            dfs(y.next,y.cost+cct);
        }
    }if(f==0){
        xc+=cct;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int c,cc;
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>cc;
            a[n+i].push_back({j,cc});

            a[j].push_back({n+i,c});
        }
    }dfs(1,0);

    cout<<xc;
    return 0;
}