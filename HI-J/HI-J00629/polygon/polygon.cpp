#include<bits/stdc++.h>
using namespace std;
int a[6000];
long long dp[6000];
int n;
long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=5000;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	dp[0]--;
	for(int i=0;i<n;i++){
		dp[a[i]]+=mod;
		dp[a[i]]--;
		dp[a[i]]%=mod;
	}
	long long cnt=1;
	for(int i=0;i<n;i++){
		cnt*=2;
		cnt%=mod;
	}
	cnt+=mod;
	cnt--;
	cnt-=n;
	cnt-=(n-1)*n/2;
	cnt%=mod;
	for(int i=0;i<n;i++){
		for(int j=a[i];j>=0;j--){
			cnt+=mod;
			cnt-=dp[j];
			cnt%=mod;
		}
	}
	cout<<cnt;
	return 0;
}
