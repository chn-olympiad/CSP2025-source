#include<bits/stdc++.h>
using namespace std;

int a[500005]; 
int cnt;
int ans = -1;
int dp[2][500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	for(int l = 1; l <= n; l++) {
		for(int left = l; left <= n; left++) {
			for(int right = left; right <= n; right++){
				for(int i = left; i <= right; i++) {
					if(ans == -1) {
						ans = a[i];
					}else{
						ans ^= a[i];
					}
				}
				if(ans == k) {
					cnt++;
					left = right;
				}
				ans = -1;
			}
		}
		dp[0][l] = cnt;
		cnt = 0;
		dp[1][l] = max(dp[1][l-1],dp[0][l]);
	}
	cout << dp[1][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

