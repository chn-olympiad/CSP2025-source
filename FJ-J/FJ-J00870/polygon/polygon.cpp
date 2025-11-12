#include<bits/stdc++.h>
using namespace std;
int a[5005],dp[5005],mi=5005,df[5005];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=max(a[i],dp[i-1]);
		mi=min(mi,a[i]);
		df[i]=df[i-1]+a[i];	
	}if(n==3){
		if(df[n]>df[n]*2){
			cout<<1;
			return 0;
		}else cout<<0;
		return 0;
	}long long ans=0;
	if(dp[n]==1||dp[n]==mi){
		for(long long i=3;i<=n;i++){
			long long cnt=1,sum=1;
			for(long long j=1;j<=i;j++){
				sum*=j;
				cnt*=(n-j+1);
			}ans+=cnt/sum;
			ans%=998244353 ;
		}cout<<ans;
		return 0;
	}for(long long i=3;i<=n;i++){
		long long cnt=1,sum=1;
		for(long long j=1;j<=i;j++){
    		sum*=j;
			cnt*=(n-j+1);
		}ans+=cnt/sum;
		ans%=998244353 ;
	}cout<<ans;
	return 0;
}
