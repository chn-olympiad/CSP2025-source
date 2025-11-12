#include<bits/stdc++.h>
using namespace std;
long long a[1000005],dp[1000005][2],ans,n,u,t,Q=998244353;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	t=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			ans+=(t-i+Q)%Q;
			ans%=Q;
			for(int j=1;j<=a[i];j++){
				ans-=dp[j][1];
				ans=(ans+Q)%Q;
			}
		}
		t*=2;
		t%=Q;
		for(int j=10000-a[i];j>=1;j--){
			dp[a[i]+j][1]+=(dp[j][0]+dp[j][1])%Q;
			dp[a[i]+j][1]%=Q;
		}
		dp[a[i]][0]++;
	}
	cout<<ans;
	return 0;
} 