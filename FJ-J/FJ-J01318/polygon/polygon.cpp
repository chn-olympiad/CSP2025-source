#include<bits/stdc++.h>
using namespace std;
int n,lens[5005],ans,vis[10];
void dfs(int maxx,int he,int nd,int m){
//	for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
//	cout<<endl;
	for(int i=nd;i<=n;i++){
		if(m>=3 && he+lens[i]>max(maxx*2,lens[i]*2)) ans++;
		vis[m]=lens[i];
		dfs(max(maxx,lens[i]),he+lens[i],i+1,m+1);
		vis[m]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lens[i];
	}
	dfs(0,0,1,1);
	cout<<ans%998244353;
	return 0;
}
