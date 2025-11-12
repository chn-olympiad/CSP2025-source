#include <iostream>
using namespace std;
const int M = 998244353;
int a[5005], book[5005], l, n, ans;
void dfs(int e, int pos, int now) {
	if (now == e) {
		int sum = 0, maxn = 0;
		for (int i = 1;i <= e;i++)
			sum += book[i], maxn = max(maxn, book[i]);
		ans = (ans+(sum > 2*maxn))%M;
	}
	for (int i = pos+1;i <= n;i++) {
		book[++l] = a[i];
		dfs(e, i, now+1);
		book[l--] = 0;
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (n < 3)
		cout << 0;
	else {
		for (int i = 3;i <= n;i++)
			dfs(i, 1, 0);
		cout << ans;
	}
	return 0;
}
