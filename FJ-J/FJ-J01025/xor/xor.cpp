#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010],s[1010],dp[1010][1010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		if(a[i]==k)dp[i][i]=1;
	}
	if(k) {
		for(int len=1; len<=n; len++) {
			for(int i=1; i+len-1<=n; i++) {
				int j=i+len-1;
				if((s[j]^s[i-1])==k)
					for(int l=i; l<j; l++) {
						if((dp[i][l]&&(s[l]^s[j])==k)||((s[i-1]^s[l])==k&&dp[l+1][j]))
							dp[i][j]=max(dp[i][j],dp[i][l]+dp[l+1][j]);
						else {
							dp[i][j]=max(dp[i][j],dp[i][l]+dp[l+1][j]+1);
						}
					}
				else
					for(int l=i; l<j; l++)
						dp[i][j]=max(dp[i][j],dp[i][l]+dp[l+1][j]);
			}
		}
	}
	else {
		for(int len=1; len<=n; len++) {
			for(int i=1; i+len-1<=n; i++) {
				int j=i+len-1;
				for(int l=i; l<j; l++)
					dp[i][j]=max(dp[i][j],dp[i][l]+dp[l+1][j]);
			}
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}
