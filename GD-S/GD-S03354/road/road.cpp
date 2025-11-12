#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,dis[20105],ans,cnt;
struct node{
	int to,va;
};
vector<node>a[20105];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
bool vis[20105];
void prim(){
	for(int i=1;i<=k+n;i++){
		dis[i]=1e16+7;
	}
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		pair<int,int>o=q.top();
		q.pop();
		int u=o.second;
		if(vis[u])continue;
		//cout<<o.first<<endl;
		if(u<=n){
			ans+=o.first;
		}
		vis[u]=1;
		if(u<=n)cnt++;
		if(cnt==n)return;
		bool flag=0;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].to;
			//cout<<v<<" "<<a[u][i].va<<endl;
			if(dis[v]>a[u][i].va){
				if(u>n&&!flag){
					flag=1;
					ans+=o.first;
				}
				dis[v]=a[u][i].va;
				q.push({dis[v],v});
				
			}
		}//cout<<endl;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	for(int i=1;i<=k;i++){
		int v;
		cin>>v;
		for(int j=1;j<=n;j++){
			int va;
			cin>>va;
			a[n+i].push_back((node){j,va});
			a[j].push_back((node){n+i,va+v});
		}
		
	}
	prim();
	cout<<ans;
	return 0;
}
