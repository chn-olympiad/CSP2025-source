#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n = 1e6 + 5;

int n, k, ans = 0;
int a[max_n], s[max_n];

int dp[max_n];

struct Node {
	int l, r;
}x[max_n];

int atot = 0;

int cmp(Node a, Node b) {
	return a.r < b.r;
}

signed main() {	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld%lld", &n, &k);
	
	int a = 1;
	
	while ((1 << a) <= n)
		ans += n - (1 << a) + 1, a++;
	
	
	printf("%lld", ans);
	
	return 0;
}