#include <bits/stdc++.h>
using namespace std;
const int mxn=5e4+5;
int n,m,k,inq[mxn],vis[mxn],ac[mxn];
long long dis[mxn];
vector<pair<int,int> >V[mxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        V[u].push_back({v,w});
        V[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&ac[i+n]);
        for(int j=1;j<=n;j++){
            int c;
            scanf("%d",&c);
            V[i+n].push_back({j,c});
            V[j].push_back({i+n,c});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    queue<int>q;
    q.push(1);
    inq[1]=1;
    while(q.size()>0){
        int u=q.front();
        for(int i=0;i<V[u].size();i++){
            int v=V[u][i].first;
            if(v>n) dis[v]=min(dis[v],dis[u]+V[u][i].second+ac[v]);
            else dis[v]=min(dis[v],dis[u]+V[u][i].second);
            if(inq[v]==0){
                q.push(v);
                inq[v]=1;
            }
        }
        q.pop();
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dis[i]);
    }
    cout<<ans;
    return 0;
}
