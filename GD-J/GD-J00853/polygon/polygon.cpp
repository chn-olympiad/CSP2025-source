#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5050],sum[5050],ans=0;
int flag1=true;
void dfs(int dep,int tot,int need,int edge) {

	if(dep>n) {
		if(tot>need and edge>=3) {
			ans=(ans+1)%mod;
		}
		return ;
	}
	dfs(dep+1,tot,need,edge);
	dfs(dep+1,tot+a[dep],need,edge+1);
}
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>1)flag1=false;
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(flag1) {
		for(int i=1; i<=n-2; i++) {
			ans=(ans+((1<<(n-i-1))-1)%mod)%mod;
		}
	} else {
		for(int i=1; i<n; i++) {
			dfs(i+1,0,a[i],1);
		}
	}

	cout<<ans;
	return 0;
}
