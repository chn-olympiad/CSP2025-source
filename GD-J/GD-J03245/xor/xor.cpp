#include<bits/stdc++.h> 
using namespace std;

int n, dp[500005]= {-1}, r[500005];
long long k, d[500005];
int c=0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin>>n>>k;
	for (int i=0;i<n;i++) {
		cin>>d[i];
	}
	for (int i=0;i<n;i++) {
		dp[i] = -1;
	}
	for (int i=0;i<n;i++) {
		long long t=d[i];
		if (t==k) {
			dp[i] = i;
			continue;
		}
		for (int j=i+1;j<n;j++) {
			t=t^d[j];
			if (t==k) {
				dp[i] = j;
				break;
			}
		}
	}
	
	dp[n]=max(dp[n], 0);
	for (int i=n-1;i>=0;i--) {
		if (dp[i] == -1) {
			r[i] = r[i+1];
		} else {
			r[i] = max(r[i+1], r[dp[i]+1] + 1);
		}
	}
	cout<<r[0];
	
	
	return 0;
}
