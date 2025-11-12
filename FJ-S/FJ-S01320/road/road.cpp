#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005];
vector<pair<int,long long>>mp[10005];
struct ct{
	int c,a[10005];
}c[15];
long long ans=0x3f3f3f3f3f3f3f3f;
int fi(int x){
//	cout<<x<<endl;
	if(fa[x]!=x) fa[x]=fi(fa[x]); 
	
	return fa[x];
}
void mt(){
	long long re=0,w;
	priority_queue<pair<long long,pair<int,int>>>q;
	for(int i=1;i<=n;i++){
		for(int j=0;j<mp[i].size();j++){
			q.push({-mp[i][j].second,{i,mp[i][j].first}});
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	int x=0,u,v;
	while(x<n-1){
		w=q.top().first;
		u=q.top().second.first;
		v=q.top().second.second;
//		cout<<u<<' '<<v<<endl;
		q.pop();
		if(fi(u)==fi(v)) continue;
		fa[fi(u)]=fi(v);
		x++;
		re-=w;
		
	}
	ans=min(ans,re);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[u].push_back({v,w});
//		mp[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].c;
		for(int i=1;i<=n;i++) cin>>c[i].a[i];
	}
	mt();
	cout<<ans;
}
/*

*/
