#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
typedef long long ll;
typedef pair<pair<int,int>,int> PII;
int n,m,k;
int mk[100],c[100],b[100];
struct node{
    int v,w;
};
vector<node> G[N];
int vis[N];
ll prim(){
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({{0,1},0});
    ll ans=0;
    while(!q.empty()){
        int u=q.top().first.second;
        int w=q.top().first.first;
        int xx=q.top().second;
        q.pop();
        if(vis[u]==1)continue;
        //cout<<u<<endl;
        vis[u]=1;
        if(u>n)b[u-n]=xx;
        if(xx>n)mk[xx-n]++;
        ans=ans+1ll*w;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].v;
            int w=G[u][i].w;
            if(vis[v]==0){
                q.push({{w,v},u});
            }
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if(k!=0){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int u=n+1;u<=n+k;u++){
        scanf("%d",&c[u-n]);
        for(int v=1;v<=n;v++){
            int w;
            scanf("%d",&w);
            G[u].push_back({v,w});
            G[v].push_back({u,w+c[u-n]});
        }
    }
    ll ans=prim();
    for(int i=1;i<=k;i++){
        if(mk[i]==0){
            ans=ans-1ll*c[i]-1ll*b[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}

