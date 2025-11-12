#include <bits/stdc++.h>
using namespace std;

int n,k,a[500009],area[500009],dp[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++){
		if(a[i] == k){
			area[i] = i;
			continue;
		}
		int x = a[i],begin = 0;
		for(int j=i-1;j>=1;j--){
			x ^= a[j];
			if(x == k){
				begin = j;
				break;
			}
		}
		area[i] = begin;
	}
	
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		if(area[i]) dp[i] = max(dp[i-1],dp[area[i]-1]+1);
	}
	
	cout << dp[n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
