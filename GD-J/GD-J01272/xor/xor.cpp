#include <bits/stdc++.h>
using namespace std;

int n,k,a[510000],s[510000],dp[510000],la[1200000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for (int i=1; i<=n; i++)  cin >> a[i], s[i]=s[i-1]^a[i];
	
	for (int i=1; i<1<<20; i++)  la[i]=500001;
	
	dp[500001]=-1;
	
	for (int i=1; i<=n; i++)  dp[i]=max(dp[i-1],dp[la[s[i]^k]]+1), la[s[i]]=i;
	
	cout << dp[n];
	
	return 0;
}
