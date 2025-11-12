#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	vector< pair<int,int > > road;
	int country;
}a[N],q[N];
int n,m,k,f[N];
long long ans;
bool vis[N];
int minn,mi;
int findf(int x){
	if(f[x]==x)return x;
	return f[x]=findf(f[x]);
}
bool lian(){
	for(int i=2;i<=n;i++){
		if(findf(f[i])!=findf(f[1])) return 0;
	}
	return 1;
}
void dfs(int x,long long  k){
	if(lian()){
		if(ans=0) ans=k;
		else ans=min(ans,k);
		return ;
	}
	int country=0,fi,fx;
	if(a[a[x].road[0].second].country)minn+=a[a[x].road[0].second].country;
	for(int i=1;i<=(int)a[x].road.size();i++){
		if(vis[a[x].road[i].second]) continue;
		if(a[a[x].road[0].second].country){
			country=a[a[x].road[i].second].country;
			a[a[x].road[i].second].country=0;
		}
		fi=f[a[x].road[i].second],fx=f[x];
		vis[a[x].road[0].second]=1;
		f[i]=findf(f[x]);
		dfs(a[x].road[i].second,k+country+a[x].road[i].first);
		vis[a[x].road[i].second]=0;
		f[a[a[x].road[i].second].country]=fi,f[x]=fx;
		if(a[a[x].road[i].second].country){
			a[a[x].road[i].second].country=country; 
			country=0;
		} 
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int j=1;j<=n;j++)f[j]=j;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		q[u].road.push_back({w,v});
		q[v].road.push_back({w,u});
		f[u]=findf(f[v]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[n+i].country);
		int k;
		for(int j=1;j<=n;j++){
			cin>>k;
			a[i+n].road.push_back({k,j});
			a[j].road.push_back({k,i+n});
			if(i==j) a[j].country=0;
		}
	}
	vis[1]=1;
	dfs(1,0);
	cout<<ans;
	return 0;
}
