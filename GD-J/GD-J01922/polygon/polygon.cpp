#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5001];
long long ans;
long long quick_pow(long long a,int b){
	long long res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res%mod;
}
void dfs(int i,int cnt,int sum,int k){
	if(cnt>=3&&sum>k){
		int t=n-i+1;
		ans=(ans+quick_pow(2,t))%mod;
		return;
	}
	if(i>n)return;
	if(n-i+1+cnt>3)dfs(i+1,cnt,sum,k);
	dfs(i+1,cnt+1,sum+a[i],k);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(a[1]==1){
		for(int i=1;i<=n-3;i++){
			for(int j=i+2;j<=n-1;j++){
				ans=(ans+quick_pow(2,n-j-1)*(j-i-1)%mod)%mod;
			}
		}
	}else for(int i=1;i<=n-2;i++){
		dfs(i+1,1,a[i],a[i]*2);
	}
	cout<<ans%mod;
	return 0;
}
