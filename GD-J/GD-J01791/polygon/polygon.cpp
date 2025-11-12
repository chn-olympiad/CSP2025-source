#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int MOD = 998244353;
vector<int> a;
int n, x, cnt = 0;
void count(int floor, int sum, int id) {
	if (floor == 1) {
		for (int i = id; i < n; i++) {
			if (a[i] < sum) {
				cnt++;
				cnt %= MOD;
			} 
		} 
		return;
	} for (int i = id; i <= n - floor; i++) {
		count(floor - 1, sum + a[i], i + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	} sort(a.begin(), a.end());
	for (int i = 3; i <= n; i++) count(i, 0, 0);
	cout << cnt;
} 
