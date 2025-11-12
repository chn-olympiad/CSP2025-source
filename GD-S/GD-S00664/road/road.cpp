#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
#define ll long long
const int MAXN=10000,MAXM=1000000,MAXK=10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,f[MAXK+5][MAXN+5],cst[MAXK+5],al;
ll ans=inf,ret[1<<MAXK];
bool vis[MAXN+5];
struct Edge{
	int u,v,w;
	bool usd;
}e[MAXM+5];
basic_string<int> E[MAXN+MAXK+5],G[MAXN+MAXK+5],npe;
int lowbit(int x){
	return x&(-x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	al=(1<<k)-1;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		E[e[i].u].push_back(i);
		E[e[i].v].push_back(i);
	}
	vis[1]=1;
	__gnu_pbds::priority_queue<pair<ll,int>,greater<pair<ll,int> >,__gnu_pbds::pairing_heap_tag> q;
	for(auto x:E[1]) q.push(make_pair(e[x].w,x));
	ll now=0;
	int tot=1;
	while(tot<n){
		int x=q.top().second;q.pop();
		if(vis[e[x].u]&&vis[e[x].v]) continue;
		tot++;
		int h;
		if(vis[e[x].u]) h=e[x].v;
		else h=e[x].u;
		vis[h]=true;
		now+=e[x].w;
		e[x].usd=true;
		for(auto y:E[h]){
			int to=e[y].u+e[y].v-h;
			if(!vis[to]) q.push(make_pair(e[y].w,y));
		}
	}
	q.clear();
	for(int i=1;i<=n;i++){
		for(auto x:E[i]) if(e[x].usd) G[i].push_back(x);
		E[i].clear();
	}
	ans=now;
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++) cin>>f[i][j];
	}
	ret[0]=ans;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+k;j++) vis[j]=0;
		vis[i+n]=1;
		now=cst[i];
		for(int j=1;j<=n;j++) q.push(make_pair(f[i][j],j));
		tot=1;
		while(tot<=n){
			ll w=q.top().first;
			int h=q.top().second;q.pop();
			if(vis[h]) continue;
			now+=w;
			vis[h]=1;
			tot++;
			for(auto x:G[h]){
				int to=e[x].u+e[x].v-h;
				if(!vis[to]) q.push(make_pair(e[x].w,to));
			}
		}
		if(now>=ret[0]){
			npe.push_back((1<<(i-1)));
			al-=(1<<(i-1));
		}
		ans=min(ans,now);
		ret[(1<<(i-1))]=now;
		q.clear();
	}
	for(int i=1;i<(1<<k);i++) ret[i]=inf;
	int mxt=10000;
	if(n*(1<<k)>=10000000) mxt=100;
	for(int i=1;i<(1<<k);i++){
		bool flag=true;
		for(auto nnn:npe) if((i&nnn)==nnn){
			flag=false;
			break;
		}
		if(!flag) continue;
		int g=lowbit(i);
		if(lowbit(g)==i) continue;
		mxt--;
		if(mxt==0) i=al;
		basic_string<int> nd;
		int S=-1,N=n;
		now=0;
		for(int j=1;j<=k;j++) if(i&(1<<(j-1))){
			nd.push_back(j);
			S=j;
			N++;
			now+=cst[j];
		}
		for(int j=1;j<=n+k;j++) vis[j]=0;
		vis[S+n]=1;
		tot=1;
		for(int j=1;j<=n;j++) q.push(make_pair(f[S][j],j));
		while(tot<N){
			ll w=q.top().first;
			int h=q.top().second;q.pop();
			if(vis[h]) continue;
			now+=w;
			vis[h]=true;
			tot++;
			if(h>n){
				for(int i=1;i<=n;i++) if(!vis[i]) q.push(make_pair(f[h-n][i],i));
			}
			else{
				for(auto x:G[h]){
					int to=e[x].u+e[x].v-h;
					if(!vis[to]) q.push(make_pair(e[x].w,to));
				}
				for(auto x:nd) q.push(make_pair(f[x][h],x+n));
			}
		}
		ans=min(ans,now);
		ret[i]=now;
		ll ls=inf;
		for(int j=0;j<i;j++) if((i&j)==j) ls=min(ls,ret[j]);
		if(now>=ls) npe.push_back(i);
		q.clear();
		if(mxt==0) break;
	}
	cout<<ans;
	return 0;
}
