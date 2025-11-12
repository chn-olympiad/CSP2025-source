#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f;
long long x,y,k,ans,t,p[500005];
const int mod=998244353;
void dfs(long long maxn,long long s,long long i,long long sum){
	if(i>n){
		if(maxn*2<s&&s>0&&sum>=3) ans=(ans+1)%mod;	
		return;
	}
	dfs(max(maxn,a[i]),s+a[i],i+1,sum+1);
	dfs(maxn,s,i+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>20){
		ans=n;
		for(int i=1;i<=n;i++){
			ans=(ans+(n-i)*(n-i+1)/2)%mod;
		}
		return cout<<ans,0;
	}
	dfs(-1,0,1,0);
	cout<<ans%mod;
	return 0;
}

