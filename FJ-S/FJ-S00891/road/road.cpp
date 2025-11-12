#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long

priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
int vis[10020];
vector<pair<int,ll> >g[10020];
ll a[200010];

ll prim(int n,int k,int x){
	for(int i=1;i<=n;i++)vis[i]=0;
	ll ans=0;
	while(q.size())q.pop();
	q.push({0,1});
	int cnt=0;
	while(q.size()){
		auto _=q.top();
		ll cst=_.first;
		int u=_.second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		ans+=cst;
//		cout<<"[node] "<<u<<" "<<cst<<" "<<cnt<<"\n";
		if(u<=n)cnt++;
		if(cnt==n)return ans;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			ll w=g[u][i].second;
			if(v>n&&((x>>(v-n-1))&1)==0)continue;
			q.push(make_pair(w,v));
//			cout<<"[edge] "<<u<<" "<<v<<" "<<w<<"\n";
		}
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	while(m--){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	int fl=1;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		fl&=a[i]==0;
		for(int j=1;j<=n;j++){
			ll w;
			cin>>w;
			g[n+i].push_back(make_pair(j,w));
			g[j].push_back(make_pair(n+i,w));
		}
	}
	ll ans=prim(n,k,0);
//	cout<<ans<<"\n";
	if(fl)cout<<prim(n,k,(1<<k)-1),exit(0);
	for(int i=0;i<(1<<k);i++){
		ll sum=0;
		for(int j=1;j<=k;j++)sum+=((i>>j-1)&1)*a[j];
		ll tmp=prim(n,k,i);
		ans=min(ans,tmp+sum);
		cout<<i<<" "<<tmp<<"\n";
	}
	cout<<ans;
}
