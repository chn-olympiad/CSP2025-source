#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct r{
	int to[10015],w[10015],cnt=0;
}c[10015];
//bool vis[10015][10015];
long long ans=10000000000002;
void dfs(int t,int tmp,int num){
	if(tmp>ans)return;
	if(num>n){
		if(ans>tmp){
			ans=tmp;
		}
		return;
	}
	bool f=1;
	if(t>n)f=0;
	int p=c[t].cnt;
	for(int i=1;i<=p;i++){
		//if(vis[t][c[t].to[i]]||vis[c[t].to[i]][t]){
		//	dfs(c[t].to[i],tmp,num);
		//}
		//else{
			//vis[t][c[t].to[i]]=1;
			//vis[c[t].to[i]][t]=1;
			if(f)
				dfs(c[t].to[i],tmp+c[t].w[i],num+1);
			else
				dfs(c[t].to[i],tmp+c[t].w[i],num);
			//vis[t][c[t].to[i]]=0;
			//vis[c[t].to[i]][t]=0;
		//}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a,b,u;
		cin>>a>>b>>u;
		c[a].to[c[a].cnt++]=b;
		c[a].w[c[a].cnt]=u;
		c[b].to[c[b].cnt++]=a;
		c[b].w[c[b].cnt]=u;
	}
	for(int i=1;i<=k;i++){
		int z;
		cin>>z;
		for(int j=1;j<=n;j++){
			int u;
			cin>>u;
			c[n+i].to[c[n+i].cnt++]=j;
			c[n+i].w[c[n+i].cnt]=z+u;
			c[j].to[c[j].cnt++]=n+i;
			c[j].w[c[j].cnt]=z+u;
		}
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
/*
4 4 2 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
1 1 8 2 4 
100 1 3 2 4 */
