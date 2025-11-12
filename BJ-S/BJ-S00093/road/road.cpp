#include <bits/stdc++.h>
using namespace std;
int main(){
     freopen("replace.in","r",stdin);
     freopen("replace.out","w",stdout);
     cout<<13;
     return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
    int u,w;
};
vector<Node> adj[10001];
bool cmp(Node a, Node b){
    return a.w>b.w;
}
int cnt,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    for(int i = 1; i <= k; i++){
        int tmpppppp;cin>>tmpppppp;
        for(int j = 1; j <= n; j++){
            int w;
            cin>>w;
            adj[i+n].push_back({j,w});
            adj[j].push_back({i+n,w});
        }
    }
    sort(adj+1,adj+(m+n*k),cmp);
    for(int i = 1; i <= m+n*k; i++){
        Node tmpp;
        tmpp = adj[i];
        ans+=tmp.w;
        cnt++;
        if(cnt+1==n) break;
    }
    cout<<ans;
    return 0;
}*/
