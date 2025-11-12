#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[30];
void dfs(int x,int mx,int ttl){
	if(x==n+1){
		if(ttl>2*mx) ans++;
		ans%=mod;
		return;
	}
	dfs(x+1,mx,ttl);
	dfs(x+1,max(mx,a[x]),ttl+a[x]);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
