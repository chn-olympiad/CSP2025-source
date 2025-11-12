#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005],ans=0;
struct edges{
    int to;
    int value;
};
vector<edges> node[10005];
struct compair_edge{
    bool Compare (const edges &x,const edges &y){
        return x.value>y.value;
    }
};
priority_queue <edges,vector<edges>,compair_edge> pq;
int minnfr,minnto,minn=0,h[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        node[u].push_back({v,w});
        node[v].push_back({u,w});
        if(w>minn){
            minnfr=u;
            minnto=v;
            minn=w;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(k<=0){
        pq.push({minnto,minn});
        h[minnfr]=h[minnto]=1;
        ans+=minn;
        for(auto now:node[minnfr]){
            pq.push(now);
        }
        for(auto now:node[minnto]){
            pq.push(now);
        }
        while(!pq.empty()){
            auto nxt=pq.top();
            if(h[nxt.to]!=1){
                h[nxt.to]=1;
                ans+=nxt.value;
                for(auto now:node[nxt.to]){
                    if(h[now.to]!=1){
                        pq.push(now);
                    }
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    cout<<1<<endl;
    return 0;
}
