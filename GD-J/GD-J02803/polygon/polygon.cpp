#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],vis[1000005],ans;
void dfs(int x,int sum,int maxa,int m){
	if(x>n){
		if(m<3)return;
		if(sum>2*maxa){
			ans++;
		}
		return;
	}
	if(vis[x]==0){
		vis[x]=1;
		dfs(x+1,sum+a[x],max(maxa,a[x]),m+1);
		vis[x]=0;
	}
	dfs(x+1,sum,maxa,m);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,-99999,0);
	cout<<ans%998244353;
	return 0;
}
