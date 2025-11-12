#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[5005];
int dp[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int m=a[n];
	dp[0]=1;
	int now=1;
	int sum;
	int res=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=0;j<=a[i];j++){
			sum+=dp[j];
			if(sum>=mod)sum-=mod;
		}
		res=res+now-sum;
		res=(res%mod+mod)%mod;
		for(int j=m-a[i];j>=0;j--){
			dp[j+a[i]]+=dp[j];
			if(dp[j+a[i]]>=mod)dp[j+a[i]]-=mod;
		}
		now=now*2%mod;
	}
	cout<<res<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
