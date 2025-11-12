#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mod,dp[10025],ans;
int f[3][10025];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	mod=998244353;
	cin>>n;
	int maxn=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		if(i==1) {
			f[1][a[1]]++;
		} else {
			for(int j=a[i]+1; j<=maxn*2+1; j++) {
				if(f[2][j]!=0) {
					ans+=f[2][j];
					ans%=mod;
				}
				if(dp[j]!=0) {
					ans+=dp[j];
					ans%=mod;
				}
			}
			for(int j=maxn*2+1; j>=1; j--) {
				dp[min(maxn*2+1,j+a[i])]+=dp[j];
				dp[min(maxn*2+1,j+a[i])]%=mod;
			}
			for(int j=maxn*2+1; j>=1; j--) {
				dp[min(maxn*2+1,j+a[i])]+=f[2][j];
				dp[min(maxn*2+1,j+a[i])]%=mod;
			}
			for(int j=maxn*2+1; j>=1; j--) {
				f[2][min(maxn*2+1,j+a[i])]+=f[1][j];
				f[2][min(maxn*2+1,j+a[i])]%=mod;
			}
			f[1][a[i]]++;
		}
	}
	ans%=mod;
	cout<<ans;
	return 0;
}
/*
ok dp solution
rp++;rp++;rp++;rp++;rp++;
2025-11-01 10:31
1.5 hour to xor;
Test in SSOI 
ak? in the last 1min;
happy;
*/
