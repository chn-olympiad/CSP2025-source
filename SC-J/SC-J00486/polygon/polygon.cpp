#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int n,m,a[5005],maxai,vis[5005],ans;
void dfs(int k,int ws,int h,int maxx,int pre){
	if(k==ws){
		if(h>2*maxx){
			ans++;
		}
		return ;
	}
	for(int i=pre+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,ws,h+a[i],max(a[i],maxx),i);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,i,0,-1,0);
		ans=(ans+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}