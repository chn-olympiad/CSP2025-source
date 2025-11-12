#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500005];
int s[500005];
int dp[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		dp[i]=maxx;
		for(int j=i;j>=1;j--){
			if(dp[i]>=dp[j-1]+1) break;
			s[j]^=a[i];
			if(s[j]==k) dp[i]=max(dp[i],dp[j-1]+1);
		}
		maxx=max(dp[i],maxx);
	}
	cout<<dp[n];
	return 0;
}
