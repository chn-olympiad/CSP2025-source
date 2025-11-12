#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int b[1010],dp[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=b[j]^b[i-1];
			if(x==k) dp[i][j]=1;
		}
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			for(int k=l;k<r;k++){
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}
