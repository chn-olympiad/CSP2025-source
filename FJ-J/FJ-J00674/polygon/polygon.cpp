#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
int n, a[MAXN], s, maxn, ans;

void func(int pos, int k){
	if (k >= 3){
		if (s > maxn * 2){
			ans++;
			ans %= 998244353;
		}
	}
	for (int i = pos; i <= n; i++){
		s += a[i];
		int m = maxn;
		maxn = max(maxn, a[i]);
		func(i + 1, k + 1);
		s -= a[i];
		maxn = m;
	}
	return;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n - 2; i++){
		maxn = a[i];
		s = a[i];
		func(i + 1, 1);
	}
	cout << ans << "\n";
	
	return 0;
}
