#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
vector<pair<int,int> > a[10004];
vector<pair<int,int> > mp;
int f[10004];
struct node{
	int u,v,w;
};
int find(int x){
	if(x==f[x])
		return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}void dij(int x){
	merge(1,x);
	for(auto i:a[x])
		if(find(x)!=find(i.first))
			mp.push_back({x,i.first});
	node minn;
	minn.w=0x3f3f3f3f;
	for(auto i:mp){
		if(find(i.first)!=find(i.second)&&a[i.first][i.second].second<minn.w){
			minn.w=a[i.first][i.second].second;
			minn.u=i.first;
			minn.v=i.second;
		}
	}
	ans+=minn.w;
	if(find(minn.u)!=find(1))
		dij(minn.u);
	else if(find(minn.v)!=find(1))
		dij(minn.v);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}for(int i=1;i<=k;i++){
		int c,x,y,z;
		cin>>c>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	dij(1);
	cout<<ans;
	return 0;
}
