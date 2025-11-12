#include<bits/stdc++.h>
using namespace std;
//棍木
const long long mod=998244353;
long long n,a[5010],ans,vis[5010],maxnn;
void dfs(long long sum,int last,long long maxn){
	if(sum>maxn*2) ans=(ans+1)%mod;
	for(int i=last+1;i<=n;i++){
		if(!vis[i]) {
			vis[i]=1;
			dfs(sum+a[i],i,max(maxn,a[i]));
			vis[i]=0;
		}
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxnn=max(maxnn,a[i]);
	}
	if(maxnn==1){
		for(int i=3;i<=n;i++){
			ans=(long long)(ans+n-i+1)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans%mod;
	return 0;
}
