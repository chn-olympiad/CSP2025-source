#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5,mod=998244353;
int a[N];ll dp[10*N][4];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(a[n]==1){
		ll sum=1;
		for(int i=1;i<=n;i++)
			sum*=2,sum%=mod;
		sum=(sum+mod-n-1)%mod;
		sum=(sum+1ll*mod*n-n*(n-1)/2)%mod;
		printf("%lld",sum); 
		return 0;
	}else if(n<=500){
		ll ans=0,sum=0;
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			for(int j=sum;j>a[i];j--)
				ans+=dp[j][3]+dp[j][2];
			for(int j=sum;j>=a[i];j--){
				dp[j][3]=(dp[j][3]+dp[j-a[i]][3]+dp[j-a[i]][2])%mod;
				dp[j][2]=(dp[j][2]+dp[j-a[i]][1])%mod;
				dp[j][1]=(dp[j][1]+dp[j-a[i]][0])%mod;
			}
			ans%=mod;
		//	cout<<ans<<'\n';
		}
		printf("%lld",ans);
	}
	return 0;
}
/*
*****   *
    *   *
*********
*   *
*   *****

1 5 10 10 5 1
*/

