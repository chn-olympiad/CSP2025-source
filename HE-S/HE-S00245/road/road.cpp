#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c;
const int N=1e6+47;
struct re{
	int u,v,w;
}a[N];
const int M=1e4+47;
int ca[M][M];
int g[M][M];
int sum;
int f[N];
void dfs(int x,int y,int mo){
	for(int i=1;i+y<=n;i++)
		if(g[x][y+i]!=0){
			f[i]=1;
			dfs(x,y+1,mo+g[x][y+1]);
			f[i]=0;
		}
	sum=max(sum,mo);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		g[a[i].u][a[i].v]=a[i].w;
		g[a[i].u][a[i].v]=a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>ca[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,0);
	}
	cout<<sum;
	return 0;
}
