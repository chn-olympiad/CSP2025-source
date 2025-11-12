#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n;
int ans;
int a[5005];
int dp[5005];
int sum[5005];
int pow2[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	pow2[0]=1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		pow2[i]=(pow2[i-1]*2)%mod;
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i = 1;i<=n-1;i++){
		for(int j = a[n];j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		if(i>=2){
			int sum=0;
			for(int j = 0;j<=a[i+1];j++){
				sum+=dp[j];
				sum%=mod;
			}
			int temp=(pow2[i]-sum+mod)%mod;
			ans=(ans+temp)%mod;
		}
	}
	cout<<ans;
	return 0;
}
/*
O(n)求序列中总和小于等于某个值的子序列个数 
01背包
Ohhhh!
O(2^n): 
for(int i = 0;i<=(1<<n)-1;i++){
	int sum=0,maxn=0;
	for(int j = 0;j<n;j++){
		if(i&(1<<j)){
			sum+=a[j+1];
			maxn=a[j+1];
		}
	}
	if(sum>maxn*2){
		ans++;
		ans%=mod;
	}
}
cout<<ans;
O(N^3):
for(int t = 3;t<=n;t++){
	for(int j = 0;j<=a[t];j++){
		dp[j]=0;
	}
	dp[0]=1;
	for(int i = 1;i<=t-1;i++){
		for(int j = a[t];j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	int sum=0;
	for(int j = 0;j<=a[t];j++){
		sum+=dp[j];
		sum%=mod;
	}
	int temp=(pow2[t-1]-sum+mod)%mod;
	ans=(ans+temp)%mod;
} 
sum[i]=dp[i-1][1~a[i]];
*/ 
