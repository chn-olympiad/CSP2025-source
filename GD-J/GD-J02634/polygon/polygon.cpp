#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,a[5005],c[5005],ans;
int dp[25000005];

const int MOD=998244353;

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=c[i-1];j>a[i];j--){
				ans=(dp[j]+ans)%MOD;
			}
		}
		for(int j=c[i];j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%MOD;
		}
	}
	cout<<ans;
	return 0;
}
