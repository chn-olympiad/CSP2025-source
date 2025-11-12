#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,mn=INT_MAX,dist[N];
struct edge{
    int to,val;
};
vector<edge>g[N];
map<int,vector<int>>old;
bool vis[N];
void dfs(int s){
    if(!old[s].empty()){
        for(int i=0;i<old[s].size();i++){
            if(dist[i]==-1)
                dfs(i);
            else{
                bool flag=true;
                int sum=0;
                for(int j=1;j<=n;j++){
                    if(dist[j]==-1){
                        flag=false;
                        break;
                    }else
                        sum+=dist[j];
                }
                if(flag){
                    mn=min(mn,sum);
                    return;
                }
            }
        }
    }else{
        for(auto node:g[s]){
            int to=node.to,val=node.val;
            if(dist[s]+val<dist[to]){
                dist[to]=dist[s]+val;
                dfs(to);
            }
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    while(m--){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int c;
        scanf("%lld",&c);
        for(int j=1;j<=n;j++){
            int x;
            scanf("%lld",&x);
            old[c].push_back(x);
        }
    }
    dfs(1);
    printf("%lld",mn);
    return 0;
}
