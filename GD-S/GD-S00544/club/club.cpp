#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

struct Student {
	int a, b, c;
} a[N];

bool cmp1(int x, int y) {
	return a[x].a - a[x].b > a[y].a - a[y].b;
}

bool cmp2(int x, int y) {
	return a[x].b - a[x].a > a[y].b - a[y].a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		vector<int> A, B;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].a >= a[i].b) A.push_back(i);
			else B.push_back(i);
		}
		int x = A.size(), y = B.size();
		if (x > n / 2) {
			sort(A.begin(), A.end(), cmp1);
			while (x > n / 2) {
				B.push_back(A[--x]);
				A[x] = 0;
				y++;
			}
		} else {
			sort(B.begin(), B.end(), cmp2);
			while (x < n / 2) {
				A.push_back(B[--y]);
				B[y] = 0;
				x++;
			}
		}
		ll sum = 0;
		for (int i : A) {
			sum += a[i].a;
		}
		for (int i : B) {
			sum += a[i].b;
		}
		cout << sum << endl;
	}
	return 0;
}
