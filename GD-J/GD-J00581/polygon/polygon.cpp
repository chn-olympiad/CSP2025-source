#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p,cnt,f[11451400],a[11451400],mod=998244353;
void dfs(int j,int ans,int sum){
	if(j==n+1){
		if(ans>sum*2) cnt=(cnt+1)%mod;
		return;
	}
	dfs(j+1,ans+a[j],max(sum,a[j]));
	dfs(j+1,ans,sum);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) p=1;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) return cout<<1,0;
		return cout<<0,0;
	}
	if(p==0){
		for(int i=1;i<=n;++i) f[i]=(f[i-1]*2+1)%mod;
		return cout<<(f[n]-(1+n)*n/2)%mod,0;
	}
	dfs(1,0,0);
	cout<<cnt;
}
