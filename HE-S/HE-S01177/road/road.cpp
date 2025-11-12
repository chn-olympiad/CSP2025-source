#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,ans=1e9;
struct node{
	int u;
	int v;
	int w;
	bool f;
}a[N];
int b[N];
int c[N][N];
bool vis[N];
void dfs(int w){
	bool fs=true;
	for(int i=1;i<=n;i++){
		if(b[i]!=1) fs=false;
	}
	if(fs){
		ans=min(ans,w);
		return ;
	}
	for(int i=1;i<=m;i++){
		if(a[i].f){
			b[a[i].u]=1;
			b[a[i].v]=1;
			a[i].f=false;
			dfs(w+a[i].w);
			a[i].f=true;
			b[a[i].u]=0;
			b[a[i].v]=0;
		}
	}
	for(int i=1;i<=k;i++){
		if(vis[i]){
			vis[i]=false;
			for(int j=1;j<=n;j++){
				b[j]=1;
				dfs(w+c[i][j]+c[i][0]);
				b[j]=0;
			}vis[i]=true;
		}
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].f=true;
	}
	for(int i=1;i<=k;i++){
		vis[i]=true;
		for(int j=0;j<=m;j++){
			cin>>c[i][j];
		}
	}
	dfs(0);
	cout<<ans;
	return 0;
}
