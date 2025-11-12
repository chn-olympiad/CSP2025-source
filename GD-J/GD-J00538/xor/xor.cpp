#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[100], dp[100][100], n, ans, k;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			dp[i][j] = dp[i][j-1] ^ a[j];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if(dp[i][j] == k){
				ans++;
				i = j + 1;
			}
		}
	}
	cout << ans;		
}
