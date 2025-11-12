#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
vector<pair<int,int>>e[N],dis(N);
bool vis[N];
int n,m,k;
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int c;
        scanf("%d",&c);
        for(int j=1;j<=n;j++){
            int w;
            scanf("%d",&w);
            e[j].push_back({n+i,w});
            e[n+i].push_back({j,w});
        }
    }
    int num=n,id=1,c=0;
    while(num>1){
        vis[id]=1;
        for(auto v:e[id]){
            dis.push_back({v.second,v.first});
        }
        sort(dis.begin(),dis.end());
        while(vis[id]==1){
            id=dis[0].second,c=dis[0].first;
            dis.erase(dis.begin());
        }
        cout<<num;
        num--;
        ans+=c;
    }
    cout<<ans/2;
    return 0;
}
