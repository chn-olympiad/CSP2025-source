#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 8; 
int n,k,a[MAXN],dp[MAXN],xorsum = 0,ans = 0;
map<int,int> mp; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
		xorsum ^= a[i];
		if(a[i] == k)
			dp[i]++;
		if(mp.count(xorsum ^ k) || xorsum == k)
			dp[i] = max(dp[i],dp[mp[xorsum ^ k]] + 1);
		mp[xorsum] = i;
		ans = max(ans,dp[i]);
	}
	cout << ans << "\n"; 
	return 0;
}

