#include <bits/stdc++.h>
using namespace std;
int a[500005], diff[500005] = {0};
long long ans, n, k, x;
vector<long long> dp(500005);
struct node{
	int l, r;
}q[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		diff[i] = diff[i - 1] ^ a[i];
	}
	for(int r = 1; r <= n; r++){
		for(int l = 1; l <= r; l++){
			if(diff[r] ^ diff[l - 1] == k){//ÓÐÎÊÌâ 
				x++;
				q[x].l = l, q[x].r = r;
			}
		}
	}
//	for(int i = 1; i <= x; i++)
//		cout << q[i].l << ' ' << q[i].r << endl;
	for(int i = 1; i <= x; i++)
		dp[i] = 1;
	for(int i = 1; i <= x; i++){
		for(int j = 1; j < i; j++){
			if(q[j].r > q[i].l)
				break;
			dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << min(ans, n);
	return 0;
} 
//1 1
//1 2
//2 2
//1 3
//2 3
//3 3
//2 4
