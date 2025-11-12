#include <bits/stdc++.h>
using namespace std;
#define ott(i,l,r) for (int i = (l); i <= (r); i ++)
#define tto(i,l,r) for (int i = (r); i >= (l); i --)
const int N = 1e6 + 110;
mt19937 rd(random_device {}());
int n;
int main () {
	// freopen ("a.in", "r", stdin);
	freopen ("in.txt", "w", stdout);
	auto rint = [&](int l, int r) {
		return l + rd () % (r - l + 1);
	};
	cout << rint (1, 2) << '\n';
	// cin >> n;
	// cout << n << '\n';
	return 0;
}//HN-S01394