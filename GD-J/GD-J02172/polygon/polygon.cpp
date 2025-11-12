#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5001];
long long ans;
void dfs(int da,int he,int i){
	if(i>n){
		if(he>da*2) ans=(ans+1)%mod;
		return;
	}
	dfs(max(da,a[i]),he+a[i],i+1);
	dfs(da,he,i+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
