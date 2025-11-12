#include<bits/stdc++.h>
using namespace std;
int n;
bool f[10005];
int r[2005][2005];
long long minn=1e17;
void dfs(int x,long long sum,int cnt){
	if(cnt==n){minn=min(minn,sum);}
	for(int i=1;i<=n;i++){
		if(r[x][i]!=0&&f[i]==0&&x!=i){
			f[i]=1;
			dfs(i,sum+=r[x][i],cnt+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,p;
	cin>>n>>m>>p;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		r[u][v]=w;
		r[v][u]=w;
	}
	f[1]=1;
	for(int i=1;i<=n;i++){
		dfs(i,0,1);
	}
	cout<<minn-1;
	return 0;
}
