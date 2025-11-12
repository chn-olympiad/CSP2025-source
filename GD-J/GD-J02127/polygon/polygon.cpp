#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5000*5000+5;
int a[5005];
long long dp[N][2];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<a[i]<"\n";
		for(int j=a[i];j>2*(a[i]-a[i-1]);j--){
			dp[j][1]=(dp[j][1]+dp[j+a[i-1]-a[i]][0]+dp[j+a[i-1]-a[i]][1])%mod;
//			cout<<"  "<<j<<" "<<dp[j][1]<<"\n";
		}
//		cout<<"  -----\n";
		for(int j=2*(a[i]-a[i-1]);j>=a[i]-a[i-1];j--){
			dp[j][0]=(dp[j][0]+dp[j+a[i-1]-a[i]][0]+dp[j+a[i-1]-a[i]][1]);
//			cout<<"  "<<j<<" "<<dp[j][0]<<"\n";
		}
	}
	long long ans=0;
	for(int i=1;i<=a[n];i++){
		ans=(ans+dp[i][1])%mod;
	}
	cout<<ans;
	return 0;
}
