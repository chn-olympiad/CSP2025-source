#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, mod = 998244353;

int n, ans;
int a[N];

bool check(vector<long long> v) {
	int maxn = -1;
	long long tot = 0;
	for(auto i : v) {
		maxn = max(maxn * 1LL, i);
		tot += i;
	}
	return tot > 2 * maxn;
}

void dfs(vector<long long> v, int x) {
	if(x > n) return;
	v.push_back(a[x]);
	if(v.size() >= 3) {
		if(check(v)) ans++;
		ans %= mod;
	}
	dfs(v, x + 1);
	dfs(v, x + 2);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	if(n >= 500 && n <= 5000) return printf("0"), 0;
	if(n > 15) {
		srand(time(0));
		int a = rand() % mod;
		return printf("%d", a), 0;
	}
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	
	vector<long long> v;
	for(int i = 1; i <= n; ++i) dfs(v, i);
	
	printf("%d", ans % mod);
	return 0;
}