#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0,a[5001],dp[5002]={1};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++){
			ans=(ans+dp[j])%998244353;
		}
		for(int j=0;j<=a[i];j++){
			dp[5001]=(dp[5001]+dp[5001-j])%998244353;
		}
		for(int j=5000;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%998244353;
		}
	}
	cout<<ans;
	return 0;
}
