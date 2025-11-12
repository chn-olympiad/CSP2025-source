#include<bits/stdc++.h>
using namespace std;
int t,n,vis[5],a[100005][5];
int dfs(int i){
	int res=0;
	for(int j=1;j<=3;j++){
		if(vis[j]+1>n/2) continue;
			vis[j]=vis[j]+1;
			res=max(res,dfs(i+1)+a[i][j]);
			vis[j]=vis[j]-1;
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a)); 
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		}
		cout<<dfs(1)<<endl;
	}
	return 0;
}
