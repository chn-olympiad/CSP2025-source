//40pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 998244353;
int n, ans = 0;
int num = 0;
vector<int> v;
bool cmp(int a, int b) {
	return a > b;
}
void f(int zc, int x, int num) {
	if (num > zc) {
		ans++;
	}
	for (int i = x; i < n; i++) {
		f(zc, i + 1, num + v[i]);
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		ans = 0;
		f(v[i], i + 1, 0);
		num += ans;
		num %= mod;
	}
	cout << num << '\n';
}
//rp++
//总分:200