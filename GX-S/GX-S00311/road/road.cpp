#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct ed{
    int to;
    ll w;
};
const int N=10050;
vector<ed> gra[N];
int n,m,k;
bool vis[N];
ll dis[N],c[15][N];

ll Prim(int sum){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> > q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    q.push({0,1});
    while(!q.empty()){
        pair<ll,int> ele=q.top();
        q.pop();
        ll nw=ele.first;
        int u=ele.second;
        if(vis[u]){
            continue;
        }
        vis[u]=1;

        for(auto x:gra[u]){
            int v=x.to;
            ll w=x.w;
            if(vis[v]) continue;
            if(w<dis[v]){
                dis[v]=w;
                q.push({w,v});
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=sum;i++){
        ans+=dis[i];
    }
    return ans;
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        gra[u].push_back({v,w});
        gra[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i][0]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&c[i][j]);
        }
    }
    ll ans=Prim(n);

    if(k<=5){
        for(int i=1;i<=(1<<k)-1;i++){
            ll xans=0,cnt=0;
            for(int j=0;j<=k;j++){
                if(i&(1<<j)){
                    cnt++;
                    xans+=c[j+1][0];
                    int u=n+cnt;
                    for(int v=1;v<=n;v++){
                        ll w=c[j+1][v];
                        gra[u].push_back({v,w});
                        gra[v].push_back({u,w});
                    }
                }
            }
            xans+=Prim(n+cnt);
            ans=min(ans,xans);
            for(int j=0;j<=k;j++){
                if(i&(1<<j)){
                    int u=n+cnt;
                    for(int v=1;v<=n;v++){
                        gra[u].pop_back();
                        gra[v].pop_back();
                    }
                    cnt--;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
