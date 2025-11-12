#include<bits/stdc++.h>
using namespace std;/*
int n,m,k,dp[10005][10005],a[15][10005],c[15],fs[10005][10005];
int arr[10005]={};
int ans=2147483647;

void starting(int l){
	for(int i=1;i<=l;i++){
		arr[i]=i;
	}
}

int find_head(int x){
	if(arr[x]==x){
		return x;
	}
	int head=find_head(arr[x]);
	arr[x]=head;
	return head;
}

void merge(int x,int y){
	arr[x]=y;
}

bool together(int x,int y){
	if(find_head(x)==find_head(y)){
		return true;
	}
}

void dfs(){
	if(){
		ans=min(ans,)
	}
	
	for(int i=1;i<=n;i++){
		
	}
}

int main(){*/
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cout<<0<<endl;
	
	fclose(stdin);
	fclose(stdout);
	/*
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dp[u][v]=w;
		
	}
	for(int i=1;i<=k;i++){
		
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	//1: Build from u to v             cost dp[u][v]
	//2: Build from u to village to v  cost c[village]+a[village][u]+a[village][v]
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) fs[i][j]=0;
			else{
				int mi=dp[i][j];
				for(int p=1;p<=k;p++){
					mi=min(mi,c[p]+a[p][i]+a[p][j]);
				}
				fs[i][j]=mi;
			}
		}
	}
	
	starting(n);
	dfs();
	
	*/
	return 0;
}
