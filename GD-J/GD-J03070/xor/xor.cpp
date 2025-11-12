#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int a[N];
int n, k;
struct xx {
	int l, r;
};
bool cmp (xx A, xx B) {
	if (A.r == B.r) return A.l < B.l;
	return A.r < B.r;
}
vector<xx> b;
void workA () {
	cout << k / 2;
}
void workB () {
	int ans0 = 0, ans1 = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 1) {
			ans1 ++;
			cnt ++;
		}
		else {
			ans0 += cnt / 2 + 1;
			cnt = 0;
		}
	}
	if (k == 0) cout << ans0;
	else cout << ans1;
}
void workC () {
	for (int i = 1; i < n; i ++) {
		int x = a[i];
		if (a[i] == k) {
			xx X;
			X.l = i;
			X.r = i;
			b.emplace_back(X);
			//cout << i <<endl;
		}
		for (int j = i + 1; j <= n; j ++) {
			x = x xor a[j];
			if (x == k) {
				xx X;
				X.l = i;
				X.r = j;
				b.emplace_back(X);
				//cout << i << ' '<< j <<endl;
			}
		}
	}
	sort (b.begin (), b.end (), cmp);
	int f[b[b.size () - 1].r + 1];
	for (int i = 0; i < b[b.size () - 1].r + 1; i ++) f[i] = 0;
	for (int i = 0; i < b.size (); i ++) {
		int L = b[i].l, R = b[i].r;
		//cout << L <<' '<<R<<' ';
		int mx = 0;
		for (int j = 1; j < L; j ++) {
			mx = max (mx, f[j]);
		}
		f[R] = max (f[R], mx + 1);
		//cout << f[R] <<endl;
	}
	int maxn = 0;
	for (int i = 0; i < b[b.size () - 1].r + 1; i ++) {
		maxn = max (maxn, f[i]);
		//cout << f[i] <<endl;
	}
	cout << maxn;
}
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	bool xzA = true, xzB = true;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != 1) xzA = false;
		if (! (0 <= a[i] && a[i] <= 1)) xzB = false;
	}
	if (xzA) workA();
	if (xzB) workB();
	else workC();
	return 0;
} 
