#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod = 998244353;
int a[5010],dp[5010];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	ll ans=0;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 3;i <= n;i++){
		for(int j = 0;j <= a[i];j++) dp[j] = 1;
		for(int j = 1;j < i;j++){
			for(int k = a[i];k >= a[j];k--){
				dp[k] = (dp[k]+dp[k-a[j]])%mod;
			}
		}
		//cout<<(qpow(2,i-1)-dp[a[i]]+mod)%mod<<"\n";
		ans = (ans+(qpow(2,i-1)-dp[a[i]]+mod)%mod)%mod;
	}
	cout<<ans;
	return 0;
}