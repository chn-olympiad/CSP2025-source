#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+10,M=1148576;

int n,k, a[N], dp[N], l[M], s[N];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	s[0]=0;
	for(int i=0;i<M;i++) {
		l[i]=0;
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	dp[n+1]=0;
	for(int i=n;i>=1;i--) {
		dp[i]=dp[i+1];
		l[s[i]]=i;
		int j=l[k^s[i-1]];
		if(j>0) {
			dp[i]=max(dp[i+1], 1+dp[j+1]);
		}
	}
	cout<<dp[1];
	return 0;
} 
