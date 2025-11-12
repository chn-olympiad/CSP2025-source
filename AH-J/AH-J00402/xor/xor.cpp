#include <bits/stdc++.h>
using namespace std;
int dp[500005][2],a[500005],v[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1||a[i]==0){
			sum++;
		}
		v[i]=v[i-1]^a[i];
	}
	int ans=0,tmp=0;
	if(k==0&&sum==n){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==1){
				tmp++;
			}
			if(tmp==2){
				ans++;
				tmp=0;
			}
		}
		cout<<ans;
		return 0;
	}else if(k==1&&sum==n){
		for(int i=1;i<=n;i++){
			if(a[i]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(a[1]==k){
		dp[1][0]=dp[1][1]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((v[i]^v[j-1])==k){
				dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
				dp[i][1]=max(dp[j-1][0]+1,dp[j-1][1]+1);
			}
		}
	}
	cout<<max(dp[n][1],dp[n][0]);
	return 0;
}
