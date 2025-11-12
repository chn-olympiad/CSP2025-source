#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[3010],b[3100][3030];
int dp[3100];
bool vis[3050][3030];
int sum1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) sum1++;
	}
	if(n>1000){
		if(k==1){
			cout<<sum1;return 0;
		}else if(k==0){else if(k==0){
			int ans1=0;
			for(int i=1;i<n;i++){
				if(a[i]==0){
					ans1++;
				}if(a[i]==1&&a[i+1]==1){
					ans1++;
					i++;
				}
			}if(a[n]==0)ans1++;
			cout<<ans1;
			return 0;
			}
		}
	}
	else{
		for(int l=1;l<=n;l++){
		int x=a[1];
		for(int i=2;i<l;i++){
			x=x^a[i];
		}
		for(int i=l;i<=n;i++){
			if(l!=1||i!=1){
				x=x^a[i];	
			}
			if(x==k){
				dp[i]=max(dp[i],max(dp[i-l]+1ll,dp[i-1]));
				vis[i][l]=1;
			}
			if(vis[i][l-1]==1){
				dp[i]=max(dp[i],dp[i-l+1]+1);
			}
			dp[i]=max(dp[i],dp[i-1]);
			x=x^a[i-l+1];
		}
	}
	cout<<dp[n];
	}
	return 0;
}

