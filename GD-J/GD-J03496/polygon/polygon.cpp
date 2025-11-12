#include<bits/stdc++.h>
using namespace std;
#define FILE "polygon"
constexpr long long mod=998244353; 
int n,a[7001];
long long dp[7001];//组合出i的方案数
long long qpow(long long x,long long y){
	auto res=1ll;
	while(y){
		if(y&1){
			res=res*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	} 
	return res;
}
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+qpow(2,i-1))%mod;
		for(int j=0;j<=a[i];j++){
			ans=(ans-dp[j]+mod)%mod;
		}
		for(int j=a[n];j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	cout << ans;
	return 0;
}
/*
按照ai从小到大排序，钦定i取到最大值
问题变为：加入一个数li；询问当前数列中和大于li的方案数 
*/
/*


dev-c++ using code: GB2312, turn to see chinese content.
哈哈，骗你的。 



I want to shang mi huo xing wei da shang
//freopen("joker.in","r",stdjoker);
//freopen("polygen.in","r",stdgenerals.io) 
//freopen("output.out","w",NeverGonnaGiveYouUp);
Arknights
*/
