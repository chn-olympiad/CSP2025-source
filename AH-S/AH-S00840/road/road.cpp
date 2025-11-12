#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1005][1005];
int n,m,k,ans=0;
struct node{
	int u,v,w;
}x[1000005];
bool cmp(node p,node q){
	return p.w<q.w;
}
void dfs(int uu,int u,int v,int step){
	if(!a[u][v]){
		return;
	}
	if(step==n){
		cout<<ans;
		exit(0);
	}
	a[uu][v]=1;
	a[v][uu]=1;
	for(int i=1;i<=n;i++){
		if(a[v][i]&&i!=v&&i!=u&&i!=uu){
			dfs(uu,v,i,step+1);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].w;
	}
	for(int i=1;i<=k;i++){
		int s;
		cin>>s;
		for(int j=1;j<=n;j++){
			int ss;
			cin>>ss;
		}
	}
	sort(x+1,x+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(a[x[i].u][x[i].v]&&a[x[i].v][x[i].u]){
			continue;
		}
		ans+=x[i].w;
		a[x[i].u][x[i].v]=1;
		a[x[i].v][x[i].u]=1;
		dfs(x[i].u,x[i].u,x[i].v,2);
		dfs(x[i].v,x[i].v,x[i].u,2);
	}
	return 0;
}
