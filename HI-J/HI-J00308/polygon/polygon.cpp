#include <bits/stdc++.h>

using namespace std;

const int N = 5010, fff=998244353;

int n, a[N], dp[N][N][3];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=0;i<=n;i++) {
		for(int j=-1;j<=5000;j++) {
			for(int k=0;k<=2;k++) {
				if(i==0) {
					if(j<0&&k==0)dp[i][j+1][k]=1;
					else dp[i][j+1][k]=0;
				} else {
					dp[i][j+1][k]=(dp[i-1][max(-1, j-a[i])+1][max(0,k-1)]+dp[i-1][j+1][k])%fff;
				}
			} 
		}
		if(i>0) {
			ans+=dp[i-1][a[i]+1][2], ans%=fff;
		}
	}
	cout<<ans;
	return 0;
}
