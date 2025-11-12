#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 500050, M = 1 << 21;

int n, k;
int arr[N], sum[N], dp[N];
int la[M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> arr[i];
		sum[i] = sum[i - 1] ^ arr[i];
	}
	for(int i = 1; i < M; i ++)
		la[i] = -1;
	for(int i = 1; i <= n; i ++){
		dp[i] = dp[i - 1];
		if(la[sum[i] ^ k] != -1)
			dp[i] = max(dp[i], dp[la[sum[i] ^ k]] + 1);
		la[sum[i]] = i;
	}
	cout << dp[n];
	return 0;
}