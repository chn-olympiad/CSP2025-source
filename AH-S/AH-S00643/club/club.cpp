#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005][4];
int vis[5],ans;
void dfs(int t,int v){
	if(t>n){
		ans=max(ans,v);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<n/2){
			vis[i]++;
			dfs(t+1,v+a[t][i]);
			vis[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		ans=-1;
		dfs(1,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
