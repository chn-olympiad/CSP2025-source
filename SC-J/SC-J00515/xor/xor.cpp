#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k; 
int a[maxn];
int dp[maxn];
int s[maxn];
int t;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]!=1) t=1;
	}
	if(!t&&k==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int sum=s[i]^s[j-1];
			if(sum==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
			else{
				dp[j]=max(dp[j],dp[j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}