#include <bits/stdc++.h>
using namespace std;
const int max_space = 5 * 1e5 + 1, max_space2 = (1<<20) + 1;
int n, k, cnt_1, x[max_space], cnt, maxn, dp[max_space2];
struct node{
	int l, r;
}b[max_space];
int t;
bool v[max_space];
bool cmp(node x, node y){
	if (x.l != y.l)return x.l < y.l;
	return x.r < y.r;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		x[i] = x[i - 1] ^ a;
		if (a == 1)cnt_1++;
		maxn = max(maxn, a);
	}
	if (k == 0 && maxn <= 1){
		cout << cnt_1 / 2 << endl;
		return 0;
	}
	if (k == 1 && maxn <= 1){
		cout << cnt_1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		b[i].l = i;
		for (int j = i; j <= n; j++){
			if ((x[j]^x[i - 1]) == k){
				v[i] = 1, b[i].r = j;
				break;
			}
		}
	}
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)if (v[i])cout << i << "=[" <<b[i].l << "," << b[i].r << "]" << endl;
	for (int i = 1; i <= n; i++){
		for (int j = n; j >= 1; j--){
			dp[j] = dp[t];
			if (j == b[i].r)dp[j] += dp[b[i].l];
		}
	}
	cout << dp[n] << endl;
	return 0;
}
