#include<bits/stdc++.h>
using namespace std;
int a[50005],cost[15];
struct node{
	int x,y;
};
map<pair<int,int>,int >mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		if(mp[make_pair(u,v)]!=0)mp[make_pair(u,v)]=min(mp[make_pair(u,v)],w);
		else mp[make_pair(u,v)]=w;
		//G[u].push_back(make_pair(v,w));
		//G[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		memset(a,0,sizeof(a));
		cin>>cost[i];
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(mp[make_pair(j,l)]!=0)mp[make_pair(j,l)]=min(mp[make_pair(j,l)],a[l]+a[j]);
				else mp[make_pair(j,l)]=a[l]+a[j];
				//G[j].push_back(make_pair(l,a[l]+a[j]));
				//G[l].push_back(make_pair(j,a[l]+a[j]));
			}
		}
	}
	int now=0,ans=0;
	for(auto i:mp){
		ans+=i.second;
		//cout<<i.second<<endl;
		now++;
		//if(now==n)break;
	}
	cout<<ans;
	return 0;
}
