#include <bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e6+9;
struct Node{
    int to,val;
};
vector<Node>g[N];
int c[N];
int co[15][N];
int n,m,k;
long long sum;
int vis[N];
typedef pair<int,int>pii;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>co[i][j];
        }
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;
    vis[1]=0;
    int s=1;
    for(auto it:g[1]){
        q.push({it.val,it.to});
    }while(q.size()&&s<n){
        while(vis[q.top().second])q.pop();
        int tmp=q.top().second;
        sum+=q.top().first;
        q.pop();
        vis[tmp]=1;
        s++;
        for(auto it:g[tmp]){
            if(vis[it.to])continue;
            q.push({it.val,it.to});
        }
    }cout<<sum;
    fclose(stdin);
    fclose(stdout);

return 0;
}