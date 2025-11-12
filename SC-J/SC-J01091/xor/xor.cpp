#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,k,a[N],p[N],dp[N][3];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	ll ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		p[i]=(p[i-1]^a[i]);
	}
	if(ma<=1&&k==1){
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(k==0){
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i+1]==1) {
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(a[i]==k){
			dp[i][1]=dp[i][0]+1;
		}
		for(int j=i-1;j>=1;j--){
			if((p[i]^p[j-1])==k) {
				dp[i][1]=max(dp[i][1],dp[j][0]+1);
				break;
			}
		}
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}