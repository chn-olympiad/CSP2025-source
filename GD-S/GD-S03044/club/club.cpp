#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 505;
ll a[N][5], n;
ll dp[N/2][N/2][N/2]; 
ll dpB[N/2][N/2];

void solve(){
	cin >> n;
	bool spjA = true, spjB = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][2] != 0 || a[i][3] != 0) spjA = false;
		if(a[i][3] != 0) spjB = false;
	}
	for(int i = 0;i <= n/2;i++){
		for(int j = 0;j <= n/2;j++){
			dpB[i][j]=0;
			for(int k = 0;k <= n/2;k++){
				dp[i][j][k]=0;
			} 
		}
	}
	if(spjA){
		vector<int>avc;
		for(int i = 1;i <= n;i++){
			avc.push_back(a[i][1]);
		}
		sort(avc.begin(), avc.end(), greater<int> ());
		int sum = 0;
		for(int i = 0;i < n/2;i++){
			sum += avc[i];
		}
	}
	else if(spjB){
		//printf("[Debug] Entering SPJB\n");
		for(int i = 1;i <= n;i++){
			for(int j = n/2;j >= 0;j--){
				for(int k = n/2;k >= 0;k--){
					ll &bs = dpB[j][k];
					if(j>=1) bs = max(bs, dpB[j-1][k] + a[i][1]);
					if(k>=1) bs = max(bs, dpB[j][k-1] + a[i][2]);
				}
			} 
		}
		cout << dpB[n/2][n/2] << endl;
	}
	else{
		for(int i = 1;i <= n;i++){
			for(int j = n/2;j >= 0;j--){
				for(int k = n/2;k >= 0;k--){
					for(int l = n/2;l >= 0;l--){
						ll &bs = dp[j][k][l];
						if(j>=1) bs = max(bs, dp[j-1][k][l] + a[i][1]);
						if(k>=1) bs = max(bs, dp[j][k-1][l] + a[i][2]);
						if(l>=1) bs = max(bs, dp[j][k][l-1] + a[i][3]);
					}
				}
			} 
		}
		cout << dp[n/2][n/2][n/2] << endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
}
