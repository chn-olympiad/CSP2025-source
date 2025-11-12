#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500005],dp[500005][2],f[5006][5006];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			if(j==i) f[j][i]=a[i];
			else f[j][i]=f[j][i-1]^a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[i-1][0]>=dp[i-1][1]) dp[i][0]=dp[i-1][0];
		else dp[i][0]=dp[i-1][1];
		for(int j=1;j<=i;j++){
			int kk=0;
			if(f[j][i]==k) kk=1;
			dp[i][1]=max(dp[i][1],max(dp[j-1][1],dp[j-1][0])+kk);
		}
	}
	cout<<max(dp[n][1],dp[n][0]);
	return 0;
}