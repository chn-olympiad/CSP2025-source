#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1005
int a[N];
int dp[N][N];
int cnt[N];
int n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=a[i]^cnt[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) dp[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int l=1;l<=n-i+1;l++){
			int r=l+i-1;
			if((cnt[r]^cnt[l-1])==k) dp[l][r]=1;
			for(int j=l;j<r;j++){
				dp[l][r]=max(dp[l][r],dp[l][j]+dp[j+1][r]);
			}
		}
	}
	cout<<dp[1][n];
	fclose(stdout);
	fclose(stdin);
	return 0;
}
