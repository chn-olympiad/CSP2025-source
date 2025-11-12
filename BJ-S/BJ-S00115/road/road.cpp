#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,w;
};
vector<node> g[10005];
long long vis[10005],f[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
        }
    }
    long long s=0;
    vis[1]=1;
    int cnt=1;
    while(cnt<n){
        cnt++;
        int minn=INT_MAX,minid=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                for(int j=0;j<g[i].size();j++){
                    node l=g[i][j];
                    if(l.w<minn&&vis[l.x]==0){
                        minid=l.x;
                        minn=l.w;
                    }
                }
            }
        }
        vis[minid]=1;
        s+=minn;
    }
    cout<<s;
    return 0;
}
