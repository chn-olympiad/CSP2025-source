#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
struct node{
    ll v;
    ll w;
};
vector<node>g[10005];
ll c[11][100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    ll u,v,w,ans=0;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        ans+=w;
    }
    for(int i=1;i<=k;i++){
       for(int j=1;j<=n+1;j++){
            cin>>c[i][j];
       }
    }
    cout<<ans;
    return 0;
}
//考察知识点：最小生成树