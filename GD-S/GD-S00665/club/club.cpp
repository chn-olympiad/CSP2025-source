#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int t,n,chk2,chk3;
ll sum;
int a[N][5];
int dp[210][210][210],dpp[3][N];
void prep(){
	int maxn = -0x3f3f3f3f;
	for (int i = 0;i <= n;i++){
		for (int j = 0;j <= n;j++){
			for (int l = 0;l <= n;l++){
				dp[i][j][l] = 0;
			}
		}
	}
	dp[1][1][0] = a[1][1];
	dp[1][0][1] = a[1][2];
	dp[1][0][0] = a[1][3];
	for (int i = 2;i <= n;i++){
		for (int a1 = 0;a1 <= i;a1++){
			for (int a2 = 0;a2 <= i;a2++){
//				cout << dp[i][a1][a2] << ' ' << dp[i - 1][(a1>=1?a1-1:0)][a2] << ' ' << dp[i - 1][a1][(a2>=1?a2-1:0)] << ' ' << dp[(a1 + a2 <= i - 1?i - 1:0)][a1][a2] << '\n';
				if (a1 <= n / 2 && a2 <= n / 2 && (i - a1 - a2) <= n / 2 && a1 + a2 <= i){
//					cout << dp[i][a1][a2] << ' ' << dp[i - 1][(a1>=1?a1-1:0)][a2] << ' ' << dp[i - 1][a1][(a2>=1?a2-1:0)] << ' ' << dp[(a1 + a2 <= i - 1?i - 1:0)][a1][a2] << '\n';
					dp[i][a1][a2] = max(dp[i][a1][a2],max((a1>=1?dp[i - 1][a1-1][a2] + a[i][1]:0),max((a2>=1?dp[i - 1][a1][a2-1] + a[i][2]:0),(a1 + a2 <= i - 1?dp[i - 1][a1][a2] + a[i][3]:0))));
//					cout << i << ' ' << a1 << ' ' << a2 << "  " << a[i][1] << ' ' << a[i][2] << ' ' << a[i][3] << "  " << dp[i][a1][a2] << ' ' << dp[i - 1][(a1>=1?a1-1:0)][a2] + a[i][1] << ' ' << dp[i - 1][a1][(a2>=1?a2-1:0)] + a[i][2] << ' ' << dp[(a1 + a2 <= i - 1?i - 1:0)][a1][a2] + a[i][3] << '\n';
				}
			}
		}
	}
	for (int a1 = 0;a1 <= n / 2;a1++){
		for (int a2 = 0;a2 <= n / 2;a2++){
			if ((n - a1 - a2) <= n / 2 && a1 + a2 <= n){
				maxn = max(maxn,dp[n][a1][a2]);
			}
		}
	}
	cout << maxn << '\n';
	return;
}
void prep2(){
	int maxn = -0x3f3f3f3f;
	for (int i = 0;i <= n;i++){
		for (int j = 0;j <= n;j++){
			dpp[i][j] = 0;
		}
	}
	dpp[1][1] = a[1][1];
	dpp[1][0] = a[1][2];
	int nPr = 0;
	for (int i = 2;i <= n;i++){
		for (int a1 = 0;a1 <= i;a1++){
			if (a1 <= n / 2 && (i - a1) <= n / 2 && a1 <= i){
				dpp[nPr][a1] = max(dpp[nPr][a1],max(a1>=1?dpp[!nPr][a1-1] + a[i][1]:0,a1 <= i - 1?dpp[!nPr][a1] + a[i][2]:0));
			}
		}
		nPr = !nPr;
	}
	for (int a1 = 0;a1 <= n / 2;a1++){
		if ((n - a1) <= n / 2 && a1 <= n){
			maxn = max(maxn,dpp[!nPr][a1]);
		}
	}
	cout << maxn << '\n';
	return;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		chk2 = chk3 = sum = 0;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= 3;j++){
				cin >> a[i][j];
				if (j == 2 && a[i][j] != 0){
					chk2 = 1;
				}
				if (j == 3 && a[i][j] != 0){
					chk3 = 1;
				}
			}
		}
		if (n <= 200)
			prep();
		else{
			if (chk2 && chk3){
				int p2[int(2e5 + 10)];
				for (int i = 1;i <= n;i++){
					p2[i] = a[i][1];
				}
				stable_sort(p2 + 1,p2 + 1 + n);
				for (int i = 1;i <= n / 2;i++){
					sum += (long long)a[i];
				}
				cout << sum;
			}
			else if (chk2){
				prep2();
			}
		}
	}
	return 0;
}
