#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll N=30000,M=20000500;
struct EDGENODE{ll to,w,nxt;}edge[M];ll head[N],cnt;void add(ll u,ll v,ll w){edge[++cnt].to=v;edge[cnt].w=w;edge[cnt].nxt=head[u];head[u]=cnt;edge[++cnt].to=u;edge[cnt].w=w;edge[cnt].nxt=head[v];head[v]=cnt;return;}
ll n,m,k,dis[N],c[N];
bool vis[N],has[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q; 
ll prim(ll s,ll num){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!q.empty())q.pop();
	ll ret=0;
	q.push(make_pair(0,s));
	dis[s]=0;
	while(!q.empty()){
		ll u=q.top().second,w=q.top().first;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		dis[u]=w;
		ret+=w;
		if(ret>num)return inf;
		//cout<<"prim:at "<<u<<" dis:"<<dis[u]<<endl;
		for(ll i=head[u];i;i=edge[i].nxt){
			ll v=edge[i].to;
			if(!has[v]||vis[v])continue;
			//cout<<"prim:"<<u<<"-->"<<v<<endl; 
			if(dis[v]>edge[i].w){
				//dis[v]=edge[i].w+dis[u];
				q.push(make_pair(edge[i].w,v));
			}
		}
	}
	return ret;
}
ll dfs(ll dep,ll num){
	//cout<<"dfs:"<<dep<<endl;
	if(dep>k){
		return prim(1,num);
	}
	ll ret=dfs(dep+1,num);
	if(ret>=c[dep]){
		//cout<<"dfs(not has):"<<dep<<" "<<ret<<endl;
		has[n+dep]=1;
		ret=min(ret,dfs(dep+1,min(num,ret))+c[dep]);
		//cout<<"dfs(has):"<<dep<<" "<<ret<<endl;
		has[n+dep]=0;	
	}
	return ret;
}
int main(){
	//freopen("road3.in","r",stdin);//ÑùÀý
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	
	ll u,v,w;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(ll i=1;i<=n;i++)has[i]=1;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>w;
			add(j,n+i,w);
		}
	}
	cout<<dfs(1,inf)<<endl;
	return 0;
}

