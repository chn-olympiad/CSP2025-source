#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll num[5010];
int n;
ll dp[5010][5010];
ll cnt[5010][5010];
ll mod=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int c=0;c<=5001;c++){
			dp[i][c]=dp[i-1][c];
			cnt[i][c]=cnt[i-1][c];
		}
		cnt[i][num[i]]++;
		for(int c=0;c<=5000;c++){

			if(c+num[i]<=5000){
				dp[i][c+num[i]]=dp[i][c+num[i]]+dp[i-1][c];

			}else{
				dp[i][5001]=dp[i][5001]+dp[i-1][c];
				
			}
			
		}
		
	}
	ll ans=0;
	for(int i=n;i>=1;i--){
		ll nans=0;
		for(int j=num[i]+1;j<=5001;j++){
			nans=nans+dp[i-1][j];
			
		}
		//nans-=cnt[i-1][num[i]];
		if(nans<=0)continue;
		ans=(ans+nans)%mod;

	
	}
	cout<<ans;
	return 0;
}