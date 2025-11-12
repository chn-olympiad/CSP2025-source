//Segtree AK IOI
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{ll v,w;};
vector<edge> g[1015];// 前n个正常点 后k个异常点
struct dot{ll u,w,lw;};
bool operator > (dot x,dot y){return x.lw<y.lw;}
bool operator < (dot x,dot y){return x.lw>y.lw;}
priority_queue<dot> pq;
vector<edge> t[1015];
ll vk[1015],dis[1015];
ll n,m,k;
ll cnt;
ll prim(ll s){
    memset(dis,-1,sizeof dis);
    pq.push({1,0,0});
    ll ans = 0;
    while(!pq.empty()){
        ll u = pq.top().u,w=pq.top().w,lw=pq.top().lw;
        pq.pop();
        if(dis[u]!=-1)continue;
        if(u>n&&(!((s>>(u-n-1))&1)))continue;
        ans+=lw;
        dis[u]=w;
        for(auto k:g[u]){
            ll v=k.v,nw=k.w;
            if(dis[v] != -1)continue;
            if(v>n&&(!((s>>(v-n-1))&1)))continue;
            pq.push({v,nw+w,nw});
        }
    }
    return ans;
}
//JP8 AK IOI
ll u,v,w;
ll tmp,minn=0x3f3f3f3f3f3f3f3f;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    } 
    for(int i = 1;i<=k;i++){
        cin>>vk[i];
        for(int j = 1;j<=n;j++){
            cin>>v;
            g[i+n].push_back({j,v});
            g[j].push_back({i+n,v});
        }
    }
    for(int i = (1<<k)-1;i>=0;i--){
        tmp=0;
        for(int j = 1;j<=k;j++){
            if(((i>>(j-1))&1)==1){
                tmp+=1ll*vk[j];
            }
        }
        tmp+=prim(i);
        minn=min(minn,tmp);
    }
    cout<<minn<<endl;
}
//LYLAKIOI AK IOI