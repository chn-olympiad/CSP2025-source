#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,cnt[10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	vector<ll> a(n+5,0);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1) cnt[1]++;
		else if(a[i]==0) cnt[0]++;
	}
	if(k==1){
		printf("%lld",max(cnt[0],cnt[1]));
		return 0;
	}else if(k==0){
		printf("%lld",((cnt[0]/2)+(cnt[1]/2)));
		return 0;
	}else{
		ll result=0,last_vol=0;
		vector<vector<ll>> dp(n+5,vector<ll>(n+5,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dp[i][j]=a[j];
				else dp[i][j]=(dp[i][j-1]^a[j]);
				dp[i][j]=dp[i][j];
				if(dp[i][j]==k&&j>last_vol){
					result++;
					last_vol=j;
					break;
				}
			}
		}
		printf("%lld",result);
	}
	return 0;
}
