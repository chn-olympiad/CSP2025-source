#include <bits/stdc++.h>

using namespace std;

int n;
const int maxn = 5e5 + 10;
int a[maxn];
vector<int> ans; 
int sum;
int cnt;
const int m1 = 998, m2 = 244, m3 = 353;
void dfs(int cur) {
	if (cur == 0) {
		cnt += lower_bound(a + 1, a + n + 1, sum) - a - ans.back() - 1;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (ans.empty() || ans.back() < i) {
			ans.push_back(i);
			sum += a[i];
			dfs(cur - 1);
			sum -= a[i];
			ans.pop_back();
		}
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		dfs(i - 1);
	}
	cout << cnt % m1 % m2 % m3 << endl;
}
