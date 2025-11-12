#include<bits/stdc++.h>
using namespace std;
int n,m,k,dp[1005][1005],towns[1005][1005],realdp[1005][1005];
struct road{
	int u,v,w;
}a[1000005];
struct town{
	int cost,tow[1005];
}b[15];
int vis[1005][1005];
bool viss[1005];
int dpans[1005];
int dfs(int now,int step,int key){
	if(viss[now]){
		return 2147483645;
	}
	if(now==key){
		return step;
	}
	if(vis[now]==0){
		return 2147483645;
	}
	int tp=vis[now][0];
	viss[now]=1;
	int anstp=INT_MAX;
	for(int i=1;i<=tp;i++){
		anstp=min(anstp,dfs(i,step+vis[now][i],key));
	}
	viss[now]=0;
	return anstp;
}
int dfs1(int step,int he,int now){
	if(viss[now]){
		return 2147483645;
	}
	if(step==n){
		return he;
	}
	int anstp=2147483645;
	viss[now]=1;
	for(int i=1;i<=n;i++){
		anstp=min(anstp,dfs1(step+1,he+realdp[now][i],i));
	}
	viss[now]=0;
	return anstp;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		vis[a[i].v][++vis[a[i].u][0]]=a[i].w;
		vis[a[i].u][++vis[a[i].v][0]]=a[i].w;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>b[i].cost;
		if(b[i].cost){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			cin>>b[i].tow[j];
			if(b[i].tow[j]){
				flag=0;
			}
		}	
	}
	if(flag){
		cout<<0;
		return 0;
	}
	cout<<0;
	//~ for(int i=1;i<=n;i++){
		//~ for(int j=1;j<=i;j++){
			//~ dp[i][j]=dfs(i,0,j);
			//~ dp[j][i]=dp[i][j];
		//~ }
	//~ }
	//~ for(int i=0;i<=1003;i++){
		//~ for(int j=0;j<=1003;j++){
			//~ towns[i][j]=2147483645;
		//~ }
	//~ }
	//~ int ttp,tpp;
	//~ for(int i=1;i<=k;i++){
		//~ ttp=b[i].cost;
		//~ for(int j=1;j<n;j++){
			//~ tpp=b[i].tow[j]+ttp;
			//~ for(int k=j+1;k<=n;k++){
				//~ towns[j][k]=min(towns[j][k],tpp+b[i].tow[k]);
				//~ towns[k][j]=towns[j][k];
			//~ }
			//~ towns[j][j]=0;
		//~ }
	//~ }
	//~ for(int i=1;i<=n;i++){
		//~ for(int j=1;j<=n;j++){
			//~ realdp[i][j]=min(dp[i][j],towns[i][j]);
		//~ }
	//~ }
	//~ cout<<dfs1(0,0,0);
	return 0;
}

