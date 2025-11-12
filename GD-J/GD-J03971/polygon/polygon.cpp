#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans,mod=998244353;
bool p=0;
void dfs(int x,int mx,int len) {
	if(x>n) {
		if(mx*2<len)ans++;
		return;
	}
	dfs(x+1,max(mx,a[x]),len+a[x]);
	dfs(x+1,mx,len);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)p=1;
	}
	if(p)dfs(1,0,0);
	else {
		long long res=1;
		for(int i=1; i<=n; i++) {
			ans+=res;
			ans%=mod;
			res*=2;
		}
		ans-=n;
		for(int i=1; i<n; i++) {
			ans-=i;
		}
	}
	cout<<ans;
}
