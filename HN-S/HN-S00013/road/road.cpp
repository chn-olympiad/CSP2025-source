#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}road[1000005];
int n,m,k,ans;
int c[15],a[15][10005];
bool vis[10005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	sort(road+1,road+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int s=0;
	queue<int> use;
	bool had[15];
	for(int i=1;i<=m;i++){
		if(s==n-1)break;
		if(vis[road[i].v]==1&&vis[road[i].u]==1)continue;
		s++;
		ans+=road[i].w;
		vis[road[i].u]=1;
		vis[road[i].v]=1;
		use.push(i);
	}
	cout<<ans<<endl;
	return 0;
}
