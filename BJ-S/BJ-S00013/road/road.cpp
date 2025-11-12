#include <bits/stdc++.h>
using namespace std;
const int N=2e6;
struct edge{
    long long v,w;
    bool operator >(edge x)const {
        return v>x.v;
    }
};
int n,m,k;
int wi[N];
long long dp[N];
bool vis[N];
long long ans;
priority_queue<edge,vector<edge>,greater<edge>> g[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push({w,v});
        g[v].push({w,u});
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        for(int j=1;j<=n;j++) cin>>wi[j];
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                long long sum=wi[l]+wi[r];
                g[l].push({sum,r});
                g[r].push({sum,l});
            }
        }
    }
    for(int i=2;i<=n;i++) ans+=g[i].top().v;
    cout<<ans;
    return 0;
}