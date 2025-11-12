#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5050];
long long mod=998244353,ans,maxx=5000;
long long dp[550][50050];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i][a[i]]=1;
		for(int k=0;k<=50000;k++){
			dp[i][k]+=(dp[i-1][k]%mod+dp[i-1][max(0ll,k-a[i])]%mod)%mod;
			dp[i][k]%=mod;
		}if(i>=3){
			for(int j=a[i]+1;j<=50000;j++)ans+=dp[i-1][j],ans%=mod;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
