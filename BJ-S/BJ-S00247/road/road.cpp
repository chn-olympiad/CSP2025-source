#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN=1e4+10+10;
struct road{
    int v;
    int w;
    bool friend operator < (road x,road y){
        return x.w>y.w;
    }
};
vector<vector<road> >mp(MAXN);
priority_queue<road>q;

bool vis[MAXN];

int main(){//pianfen
    freopen("road3.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0;
    cin>>n>>m>>k;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }

    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        ans+=c;
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            mp[n+i].push_back({j,a});
            mp[j].push_back({n+i,a});
        }
    }

    q.push({1,0});
    while(!q.empty()){
        road t=q.top();
        q.pop();
        if(vis[t.v])continue;
        vis[t.v]=true;
        ans+=t.w;
        for(int i=0;i<mp[t.v].size();i++){
            q.push(mp[t.v][i]);
        }
    }

    cout<<ans;

    return 0;
}
