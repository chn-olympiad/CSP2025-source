#include<bits/stdc++.h>
using namespace std;

long long n,a[5005],dp[5010],mod=998244353,ans=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++)
			ans+=dp[j];
		ans%=mod;
		for(long long j=5001;j>=0;j--){
			int x=j+a[i];
			x=min(5001,x);
			dp[x]+=dp[j];
			dp[x]%=mod;
		}		
	}
	cout<<ans;
	return 0;
} 
