#include<bits/stdc++.h>
using namespace std;
long long n,ans,mod=998244353,a[5005];
void dfs(long long x,long long maxn,long long sum,long long tot){
	if(x==n+1){
		if(tot>=3&&maxn*2<sum) ans++;
		return ;
	}
	dfs(x+1,maxn,sum,tot);
	dfs(x+1,max(maxn,a[x]),sum+a[x],tot+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(n>20){
		ans=1;
		for(long long i=1;i<=n;i++) ans=ans*2%mod;
		ans=(ans-1)%mod;
		ans=(ans+mod-n)%mod;
		ans=(ans+mod-n*(n-1)%mod/2%mod)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
