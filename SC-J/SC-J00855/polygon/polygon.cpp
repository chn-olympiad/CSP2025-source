#include<bits/stdc++.h>
using namespace std;
long long dp[5010][5010];
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[n]+1;j++){
			if(a[i]>=j){
				dp[i][j]=1;
				dp[i][j]=(dp[i][j]+dp[i-1][j])%998244353;
				dp[i][j]=(dp[i][j]+dp[i-1][0])%998244353;
			}else{
				dp[i][j]=(dp[i][j]+dp[i-1][j])%998244353;
				dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%998244353;	
			}
		}
	}
	
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans=(ans+dp[i-1][a[i]+1])%998244353; 
	}
	printf("%lld",ans);
	return 0;
}