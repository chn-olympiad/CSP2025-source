#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll n,k;
ll a[N];
int dp[N];
int cnt;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	/*for(int i=1; i<=n; i++){
		if(a[i] == k){
			cnt++;
			dp[i] = 0;
			continue;
		}
		dp[i] = a[i] ^ dp[i-1];
		if(dp[i] == k){
			cnt++;
			dp[i] = 0;
		}
	}*/
	for(int i=1; i<=n; i++){
		int sum=0;
		dp[i-1] = 0;
		for(int j=i; j<=n; j++){
			dp[j] = dp[j-1] ^ a[j];
			if(dp[j] == k){
				sum++;
				dp[j] = 0;
			}
		}
		cnt = max(cnt, sum);
	}
	cout << cnt;
	return 0;
}

