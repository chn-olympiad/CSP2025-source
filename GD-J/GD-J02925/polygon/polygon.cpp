#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],ans,mod=998244353;
void dfs(long long i,long long x,long long sum,long long mx){
	if(i>n){
		if(x>=3&&sum>2*mx)ans++,ans%=mod;
		return;
	}dfs(i+1,x+1,sum+a[i],a[i]),dfs(i+1,x,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n),dfs(1,0,0,-1e9),cout<<ans%mod;
	return 0;
}

