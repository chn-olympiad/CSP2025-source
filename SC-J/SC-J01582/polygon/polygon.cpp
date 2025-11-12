#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 5050, M = 10050, MOD = 998244353;

int n, arr[N], dp[M], oth = 0, ans = 0, mx = 0;

inline void add(int &a, int b){
	a += b;
	if(a >= MOD) a -= MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> arr[i];
		mx = max(mx, arr[i]); 
	}
	mx *= 2;
	sort(arr + 1, arr + n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = arr[i] + 1; j <= mx - arr[i]; j ++)
			add(ans, dp[j]);
		add(ans, oth);
		for(int j = mx; j >= mx - arr[i] + 1; j --)
			add(ans, dp[j]);
		add(oth, oth);
		for(int j = mx; j >= mx - arr[i] + 1; j --)
			add(oth, dp[j]);
		for(int j = mx; j >= arr[i]; j --)
			add(dp[j], dp[j - arr[i]]);
	}
	cout << ans;
	return 0;
}