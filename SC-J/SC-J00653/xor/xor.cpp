#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500005];
int dp[500005];
int solve(int x,int y){
	int ans=a[x];
	for(int i=x+1;i<=y;i++){
		ans=ans^a[i];
	}
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(solve(i-j+1,i)==k)
			dp[i]=max(dp[i],dp[i-j]+1);
		}
	}
	cout << dp[n];
    return 0;
}