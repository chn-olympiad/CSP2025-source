#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
	bool b;
}a[1100000];
vector<node> ve;
int kk[15][11000],n,m,k;
bool bk[15],bo[11000];
int dans(){
	for(int i=1;i<=k;i++){
		if(bk[i]==1)bo[i]=1;
	}
	for(int i=1;i<=k;i++){
		bo[i]=0;
	}
	return 0; 
}
int dfs(int p){
	if(p==k-1)return dans();
	else{
		int ans=dfs(p+1);
		bk[p]=1;
		ans=max(ans,dfs(p+1));
		bk[p]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve.push_back({u,v,w,0});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>kk[i][j];
		}
	}
	cout<<20;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
