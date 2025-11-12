#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e4+10,M=1e6+10,K=15;
LL n,m,k,u,v,w,vk[K],dis[N],cost[N][K],nyg,isa,res;
bool vis[N];
struct Node{
    LL v,d;
    bool operator <(const Node &rhs) const{
        return d>rhs.d;
    }
};
vector<Node> g[N+K];
priority_queue<Node>pq;
void tryA(){
	cout<<0;
}
LL cacl(LL x,LL y){
	LL minn=0x3f3f3f3f3f3f3f3f;
	for(LL i=1;i<=k;i++)
		if(minn>cost[i][x]+cost[i][y]+vk[i]){
			nyg=i;
			minn=cost[i][x]+cost[i][y]+vk[i];
		}
	return minn;
}
LL prim(LL u){
    LL ans=0;
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    pq.push({1,0});
    vis[1]=true;
    dis[1]=0;
    while(!pq.empty()){
        u=pq.top().v;pq.pop();
        for(LL i=0;i<LL(g[u].size());i++){
			LL v=g[u][i].v;
            if(!vis[v]&&dis[u]+g[u][i].d<dis[v]){
				dis[v]=dis[u]+g[u][i].d;
				ans+=g[u][i].d;
				pq.push({v,dis[v]});
				vis[v]=true;
            }
        }
    }
    return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    while(m--){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(LL i=1;i<=k;i++){
        cin>>vk[i];
        if(vk[i]!=0) isa=1;
        for(LL j=1;j<=n;j++){
            cin>>cost[i][j];
            if(cost[i][j]!=0) isa=1;
            cost[j][i]=cost[i][j];
        }
    }
    if(isa==0) tryA();
    cout<<n<<endl;
    for(LL i=1;i<=n;i++)
		for(LL j=i+1;j<=n;j++){
			LL w=cacl(i,j);
			bool ok=false;
			for(LL k=0;k<LL(g[i].size());i++)
				if(g[i][k].v==j){
					ok=true;
					break;
				}
			if(!ok){
				g[i].push_back({j,w});
				g[j].push_back({i,w});
			}
		}
	for(LL i=1;i<=n;i++)	
		res=max(res,prim(i));
	cout<<res;
    return 0;
}
