#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
struct edge{
    long long to,w;
};
long long n,m,k;
pair<bool,long long> ok(vector<vector<edge>>& mp,long long start,long long maxcost){
    //cout<<maxcost<<' ';
    vector<bool> vis(n+1);
    queue<long long> q;
    q.push(start);
    vis[start]=1;
    long long cnt=1,costs=0;
    bool can=0;
    while(!q.empty()){
        long long now=q.front();
        q.pop();
        for(edge& e:mp[now]){
            if(!vis[e.to]&&e.w<=maxcost){
                vis[e.to]=1;
                cnt++;
                costs+=e.w;
                q.push(e.to);
            }
        }
    }
    if(cnt>=n)can=1;
    //cout<<cnt<<' '<<n<<' '<<costs<<'\n';
    return pair<bool,long long>(can,costs);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long minstart=1,mincost=2e9,ans=2e9;
    cin>>n>>m>>k;
    vector<vector<edge>> mp(n+k+1);
    vector<vector<long long>> extra(k+1,vector<long long>(n+1));
    for(long long i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
        if(w<mincost){
            mincost=w;
            minstart=u;
        }
    }
    for(long long i=1;i<=k;i++){
        for(long long j=1;j<=n;j++){
            cin>>extra[i][j];

            mp[i+n].push_back({j,extra[i][j]});
            mp[j].push_back({i+n,extra[i][j]});
            if(extra[i][j]<mincost){
                mincost=extra[i][j];
                minstart=i+n;
            }
        }
    }
    long long l=1,r=1e18;
    while(l<=r){
        long long mid=(l+r)/2;
        pair<bool,long long> ret=ok(mp,minstart,mid);//ifok,cost
        if(ret.first){
            ans=min(ans,ret.second);
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans;
    return 0;
}
