#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e3+10;
int a[N];
int dp[N][N];
int xo(int l,int r){
	int ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=ans xor a[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==k) dp[i][i]=1;
	}
	for(int l=n;l>=1;l--){
		for(int r=l+1;r<=n;r++){
			int ans=-1;
			int ans1=0,ans2=0;
			for(int i=l;i<r;i++){
				if(xo(l,i)==k) ans1++;
				if(xo(i+1,r)==k) ans1++;
				ans2=dp[l][i]+dp[i+1][r];
				ans=max(ans,max(ans1,ans2));
				ans1=0;
			}
			dp[l][r]=ans;
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
