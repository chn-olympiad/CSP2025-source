#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],ans;
void dfs(long long i,long long s,long long mx){
	if(i>n){
		if(s>2*mx)ans=(ans+1)%mod;
		return;
	}
	dfs(i+1,s,mx);
	dfs(i+1,s+a[i],max(mx,a[i]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
