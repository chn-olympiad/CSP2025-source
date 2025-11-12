/*
so? CSP-J 红橙黄黄?
666
来luogu找我：1023865
*/
#include <iostream>

using namespace std;

constexpr int N = 110;
int n, m, k, tmp, pm;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> tmp;
	k = n * m;
	for (int i = 2; i <= n * m; i++) {
		int t; cin >> t;
		if (t > tmp) pm++;
	}
	cout << (pm / n + 1) << ' ' << (((pm / n) & 1) ? n - pm % n : pm % n + 1) << endl;
	return 0;
}
