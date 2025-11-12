#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int f[10100],c[20];
int find(int x){
	if(f[x]!=x){
		f[x]=find(f[x]);
	}
	return f[x];
}
void h(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		f[fy]=fx;
	} 
}
vector<int>a[10100];
bool st[10100];
int mn=inf;
int n,m,k;
void dfs(int x,int y,int idx){
	if(x==n-1){
		mn=min(mn,y);
		return ;
	}
	st[idx]=1;
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			dfs(x+1,y+a[idx][i],i);
			st[i]=0;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)a[i][j]=0;
			else a[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][v]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[i][j]=w;
			a[j][i]=w;
		}
	}
	n+=k;
	for(int i=1;i<=n;i++)dfs(0,0,i);
	cout<<mn;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
