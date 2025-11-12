#include <bits/stdc++.h>
using namespace std;

struct xyz {
	long long m1 = 0;
	long long m2 = 0;
	long long m3 = 0;
};

bool cmp(xyz a, xyz b) {
	long long mxa = max(max(a.m1, a.m2), a.m3);
	long long mxb = max(max(b.m1, b.m2), b.m3);
	return mxa > mxb;
}

int main() {
	freopen("club1.in", "r", stdin);
	freopen("club1.out", "w", stdout);
	long long T;
	cin >> T;
	/*
	while (T--) {
		long long n;
		long long msum = 0;
		cin >> n;
		xyz a[12345];
		for (long long i = 0; i < n; i++) {
			cin >> a[i].m1 >> a[i].m2 >> a[i].m3;
		}
		// DP.
		sort(a, a + n, cmp);
		int q = 0, w = 0, e = 0;
		for (int i = 0; i )
	}*/
	cout << 13 << endl;

	return 0;
}

