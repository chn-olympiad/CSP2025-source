#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool vis[5005];
void dfs(int temp,int sum,int maxlen){
	if(temp>2 and sum>2*maxlen and vis[temp])
		ans=(ans+1)%998244353;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		dfs(i,sum+a[temp+1],max(a[temp+1],maxlen));
		vis[i]=false;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,-1);
	cout<<ans%998244353;
	return 0;
}