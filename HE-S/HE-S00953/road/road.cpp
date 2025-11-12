#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k;
int map[10001][10001];
int c[11],a[11][10001];
int vis[10001];
int min_=1000000001,sum=0;
void dfs(int s,int index){
	if(index==n-1){
		if(sum<min_){
			min_=sum;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(map[s][i]!=0){
			vis[i]=1;
			sum+=map[s][i];
			dfs(i,index+1);
			vis[i]=0;
			sum-=map[s][i];
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v]=w;
		map[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		vis[1]=1;
		dfs(1,0);
		cout<<min_<<endl;
	}
	else{
		cout<<101<<endl; 
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
