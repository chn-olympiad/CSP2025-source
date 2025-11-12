#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+11;
int n,m,k,vis[N];
ll dis[N],ans,c[11][N],a[N],anss=1e18;
vector<pair<int,ll> >e[N],g[N];
void f(){
	int cnt=0;
	while(cnt<n){
		ll minn=1e17+1,u;
		for(int i=1;i<=n;i++){
			if(vis[i])	continue;
			if(dis[i]<minn){
				minn=dis[i];
				u=i;
			}
		}
		ans+=dis[u];
		dis[u]=0;
		vis[u]=1;
		cnt++;
		for(pair<int,int>x:e[u]){
			int v=x.first;
			ll w=x.second;
			if(dis[v]>w)	dis[v]=w;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(!k){
		while(m--){
			int u,v;
			ll w;
			cin>>u>>v>>w;
			e[u].push_back(pair<int,ll>(v,w));
			e[v].push_back(pair<int,ll>(u,w));
		}
		f();
		cout<<ans;
		return 0;
	}
	while(m--){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e[u].push_back(pair<int,ll>(v,w));
		e[v].push_back(pair<int,ll>(u,w));
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int u=1;u<=n;u++)	cin>>c[i][u];
	}
	for(int i=1;i<=n;i++)	sort(e[i].begin(),e[i].end());
	for(int i=0;i<(1<<k);i++){
		g[1]=e[1];
		vis[1]=0;
		for(int i=2;i<=n;i++){
			dis[i]=1e17;
			g[i]=e[i];
			vis[i]=0;
		}
		ans=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				ans+=a[j];
				for(int u=1;u<=n;u++){
					int len=e[u].size();
					for(int v=1,p=0;v<=n;v++){
						if(p<len&&v==e[u][p].first)	e[u][p].second=min(e[u][p].second,c[j][u]+c[j][v]);
						else{
							e[u].push_back(pair<int,ll>(v,c[j][u]+c[j][v]));
						}
					}
				}
			}
		}
		f();
		anss=min(ans,anss);
		for(int i=1;i<=n;i++)	e[i]=g[i];
	}
	cout<<anss;
	return 0;
}