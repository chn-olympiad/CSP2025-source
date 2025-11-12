#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5005];
long long ans=0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>(2*max(a[1],max(a[2],a[3])))){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	vector<long long> dp(n+1);
	for(int i=n;i>=1;i--){
		for(int j=3;j<=i;j++){
			for(int k=j;k<i;k++){
				dp[j]=max(dp[j-1],dp[j-1]+a[k]);
			}
		}
	}
	for(int i=3;i<=n;i++){
		if(dp[i]>2*a[i]) ans++;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
