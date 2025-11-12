#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int an[N][10];
int vis[10],n,ans=INT_MIN;
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum) ;
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]==n/2) continue;
		if(!an[x][i]) continue;
		++vis[i];
		dfs(x+1,sum+an[x][i]);
		--vis[i];
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>an[i][j];
		}
		dfs(1,0);
		cout<<ans<<endl;
		ans=INT_MIN;
	}	
	return 0;
}
