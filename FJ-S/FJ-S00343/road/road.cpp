#include <bits/stdc++.h>
using namespace std;
const int maxn=10020;
int n,m,k,f[maxn];
long long ans;
struct node{
	vector < pair<int,int> > road;
	int country;
}a[maxn];
bool vis[maxn];
int findf(int x){
	if(f[x]==x)return x;
	return f[x]=findf(f[x]);
}
bool lian(){
	for(int i=2;i<=n;i++){
		if(findf(f[i])!=findf(f[1])){
			return 0;
		}
	}
	return 1;
}
void djs(int x,long long k){
	if(lian()){
		if(ans==0)ans=k;
		else ans=min(ans,k);
		return;
	}
	int country=0,fi,fx;
	for(int i=1;i<(int)a[x].road.size();i++){
		if(vis[a[x].road[i].second])continue;
		if(a[a[x].road[i].second].country){
			country=a[a[x].road[i].second].country;
			a[a[x].road[i].second].country=0;
		}
		fi=f[a[x].road[i].second],fx=f[x];
		vis[a[x].road[i].second]=1;
		f[a[x].road[i].second]=findf(f[x]);
		djs(a[x].road[i].second,k+country+a[x].road[i].first);
		vis[a[x].road[i].second]=0;
		f[a[x].road[i].second]=fi,f[x]=fx;
		if(a[a[x].road[i].second].country){
			a[a[x].road[i].second].country=country;
			country=0;
		}
	}
	return;
}
int main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].road.push_back({w,v});
		a[v].road.push_back({w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>a[n+i].country;
		f[i]=i;
		int k;
		for(int j=1;j<=n;j++){
			cin>>k;
			a[i+n].road.push_back({k,j});
			a[j].road.push_back({k,i+n});
			if(i==1)a[j].country=0;
		}
	}
	vis[1];
	djs(1,0);
	cout<<ans;
	return 0;
}
