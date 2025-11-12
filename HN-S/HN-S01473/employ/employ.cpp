#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],dp[20][1<<18],b[505],ans;
char s[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++) {
		cin >>s[i];
		b[i]=b[i-1]+(s[i]-'0');
	}
	for (int i=0;i<n;i++) {
		cin >>a[i];
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<1<<n;j++) {
			for (int k=0;k<n;k++) {
				if (j&(1<<k)) {
					if (dp[i-1][j-(1<<k)]==-1)continue;
					dp[i][j]=max(dp[i][j],dp[i-1][j-(1<<k)]+(i-b[i]<a[k]));
					if (n==i) {
						ans+=dp[i][j]>=m;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
