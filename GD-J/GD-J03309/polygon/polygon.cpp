#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353; 

int n;
int a[5005];
long long ans;

void dfs(int id, long long sum, int maxx, int cnt) {
	if(id == n + 1) {
		if(sum > maxx * 2 && cnt >= 3) ans++;
		ans %= mod;
		return ;
	}
	dfs(id + 1, sum + a[id], max(maxx, a[id]), cnt + 1);
	dfs(id + 1, sum, maxx, cnt);
}

long long C(int a, int b) {
	b = min(b, a - b);
	long long sum = 1;
	for(int i = a;i > a - b;i--) {
		sum *= i;
		sum %= mod;
	}
	for(int j = 1;j <= b;j++) {
		sum /= j;
	}
	return sum;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	if(n <= 20) {
		dfs(1, 0, 0, 0);
		cout << ans << endl;
	}else {
		for(int i = 3;i <= n;i++) {
			ans += C(n, i);
			ans %= mod;
		}
		cout << ans << endl;
	}
	return 0;
}
