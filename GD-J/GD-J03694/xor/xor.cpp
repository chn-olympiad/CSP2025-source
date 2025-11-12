#include <bits/stdc++.h>
using namespace std;

int a[100860], sum[100860], dp[100860];

int exist(int start, int end, int v){
	for (int i=start;i<=end;++i){
		if (i == end) {if (a[i] == v) return 1;}
		else{
			if (i == 0){
				if (sum[end] == v) return 1;
			}else{
				int tmp = sum[end];
				tmp ^= sum[i-1];
				//cout << i - 1 << ' ' << end << endl; 
				if (tmp == v) return 1;
			}
		}
		//cout << i << endl;
	}
	return 0;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;cin >> n >> k;
	for (int i=0;i<n;i++) cin >> a[i];
	sum[0] = a[0];
	for (int i=1;i<n;i++){
		sum[i] = sum[i-1];
		sum[i] ^= a[i];
	}
	
	//cout << exist(1, 3, k) << endl;
	
	for (int i=0;i<n;i++){
		for (int j=0;j<=i;j++){
			dp[i] = max(dp[i], dp[i-j] + exist(i-j, i, k));
		}
	}
	
	cout << dp[n-1] << endl;
	
	
	return 0;
} 
