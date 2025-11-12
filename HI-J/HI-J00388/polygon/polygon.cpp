#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5005];
long long mod=998244353;
long long jc[5005],inv_jc[5005];
long long qpow(int x,int y){
	if(y==0) return 1;
	long long res=qpow(x,y/2);
	if(y%2==0) return res*res%mod;
	else return res*res%mod*x%mod;
}
long long inv(int x){
	return qpow(x,mod-2)%mod;
}
void dfs(int sum,int x,int maxx){
	if(x>n) return ;
	if(a[x]<sum) ans++;
	dfs(sum+a[x],x+1,a[x]);
	dfs(sum,x+1,maxx);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	jc[0]=1;
	inv_jc[0]=1;
	for(int i=1;i<=5000;i++){
		jc[i]=jc[i-1]*i%mod;
		inv_jc[i]=inv(jc[i]);
	}
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>30){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=jc[n]*inv_jc[n-i]%mod*inv_jc[i]%mod;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,1,0);
	cout<<ans;
	return 0;
}

