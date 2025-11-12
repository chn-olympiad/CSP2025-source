#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 2e4+10;
int n,m,k,res;
vector<pii> g[N];
int flag[N],d[N];
int c[N];
void prim(){
    memset(d,0x3f,sizeof(d));
    memset(flag,0,sizeof(flag));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    d[1] = 0;
    q.push({d[1],1});
    flag[1] = 1;
    while(q.size()){
        auto t = q.top(); q.pop();
        int u = t.second;
        cout<<"pop "<<u<<"\n";
        for(auto tt:g[u]){
            int v = tt.first;
            int w = tt.second;
            if(d[v]>d[u]){
                d[v] = d[u];
                if(!flag[v]){
                    flag[v] = 1;
                    cout<<"push "<<v<<"\n";
                    q.push({d[v],v});
                }
            }
        }
    }
}
signed main(){
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int u=n+1;u<=n+k;u++){
        cin>>c[u];
        for(int v = 1;v<=n;v++){
            int w;
            cin>>w;
            //g[u].push_back({v,w});
            //g[v].push_back({u,w});
        }
    }
    prim();
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
        res = max(d[i],res);
    }
    cout<<res<<"\n";

    return 0;
}
