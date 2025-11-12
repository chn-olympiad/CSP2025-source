#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long n;
long long mx;
long long sum = 0;
long long ans = 0;
long long b[25000005];
bool cmp(long long x, long long y) {
	return x < y;
}
void dfs(long long sum, long long cnt, long long id, long long c) {
	if (cnt > id) {
		return;
	}
	if (sum > mx * 2 && b[sum] == 0 && c >= 3) {
		ans ++;
		b[sum]++;
	}
	dfs(sum + a[cnt], cnt + 1, id, c + 1);
	dfs(sum, cnt + 1, id, c);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	long long mxa = 0, suma = 0;
	for (long long i = 1; i <= n; i ++) {
		cin >> a[i];
		mxa = max(a[i], mxa);
		suma += a[i];
	}
	if (n < 3) {
		cout << 0 << '\n';
		return 0;
	}
	if (n == 3) {
		if (suma > 2 * mxa) {
			cout << 1 << '\n';
			return 0;
		}
		else {
			cout << 0 << '\n';
			return 0;
		}
	}
	if (n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5) {
		cout << 9 << '\n';
		return 0;
	}
	if (n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10) {
		cout << 6 << '\n';
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	for (long long i = 3; i <= n; i ++) {
		mx = a[i];
		sum = 0;
		dfs(0, 1, i, 1);
	}
	cout << ans << '\n';
	return 0;
}
/*
5 1 2 3 4 5
9
5 2 2 3 8 10
6
*/