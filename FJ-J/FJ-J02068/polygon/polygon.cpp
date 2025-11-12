#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[40];
int f(int m) {
	for(int i=1,ii=1; i<=m; i++,ii*=2) {
		ii%=998244353;
		ans=ii;
	}
	ans-=n*(n+1)/2;
	if(ans<0)ans+=998244353;
	return ans;
}
void dfs(int step,int maxx,int num) {
	if(step>n) {
		if(num>2*maxx)ans++;
		return ;
	}
	if(a[step]>maxx) {
		dfs(step+1,a[step],num+a[step]);
	} else dfs(step+1,maxx,num+a[step]);
	dfs(step+1,maxx,num);
	return ;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>20) {
		cout<<f(n);
	} else {
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}

