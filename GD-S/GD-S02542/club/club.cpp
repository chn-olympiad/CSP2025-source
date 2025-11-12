#include<bits/stdc++.h>
using namespace std;
int n,a[1010][5],t,maxx,vis[5];
void dfs(int x,int sum){
//	cout<<sum<<endl;
	if(x==n+1){
		maxx=max(maxx,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<n/2){
			vis[i]++;
			dfs(x+1,sum+a[x][i]);
			vis[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxx=0;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=3;i++){
			vis[i]++;
			dfs(2,a[1][i]);
			vis[i]--;
		}
		cout<<maxx<<endl;
	}
	return 0;
}
