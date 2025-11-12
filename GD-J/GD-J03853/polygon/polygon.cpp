#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n;
int a[5005];
int pow2[5005], dp[5005];
const int P = 998244353;

void init(){
	pow2[0] = 1;
	for(int i = 1; i <= 5000; i++){
		pow2[i] = pow2[i - 1] * 2 % P;
	}	
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	init();
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);	
	dp[0] = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 0; j <= a[i]; j++){
			sum = (sum + dp[j]) % P;
		}
		int x = (pow2[i - 1] - sum + P) % P;
		ans = (ans + x) % P;
		for(int j = 5000; j >= a[i]; j--){
			dp[j] = (dp[j] + dp[j - a[i]]) % P;
		}
	}
	cout << ans << endl;
	return 0;
}
