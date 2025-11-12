#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
using VI=vector<int>;
using PI=pair<ll,int>;
const ll maxn=2e6+5,N=1e4+15,inf=1e15;
vector<PI>g[maxn];bool vis[maxn];
ll n,m,k,ans=inf,ww[N],cnt=0,dis[maxn];
ll solve(int x){
	memset(vis,1,sizeof(vis));ll num=1,sum=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n+k;i++)dis[i]=inf;
	while(x!=0){
		if(x&1)vis[num+n]=0,sum+=ww[num];
		num++;x>>=1;
	}num=0;
	priority_queue<PI,vector<PI>,greater<PI> >q;
	dis[1]=0;q.push({0,1});
	while(!q.empty()){
		ll u=q.top().second,p=q.top().first;q.pop();
		if(vis[u])continue;vis[u]=1;sum+=dis[u];
		for(auto i:g[u]){
			ll y=i.first,w=i.second;
			if(dis[y]>w){dis[y]=w;q.push({dis[y],y});}
		}
	}return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;cnt=m;
	for(int i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>ww[i];
		for(int j=1;j<=n;j++){
			ll x,o=i+n;cin>>x;
			g[o].push_back({j,x});
			g[j].push_back({o,x});
		}
	}
	for(int i=0;i<(1<<k);i++)ans=min(ans,solve(i));
	cout<<ans;return 0;
}
