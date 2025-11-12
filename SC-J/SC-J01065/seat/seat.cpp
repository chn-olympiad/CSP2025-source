#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
int a[N];
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int rsc_ = a[1];
	sort(a + 1, a + (n * m) + 1, greater<int>());
	// 0
//	for (int i = 1; i <= (n * m); i++) {
//		cout << a[i] << ' ';
//	}
//	cout << '\n';
	// 0
	int rank_ = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == rsc_) {
			rank_ = i;
			break;
		}
	}
//	cout << "rank_: " << rank_ << '\n';
	int lie_ = ((rank_ % n) == 0 ? (rank_ / n) : (rank_ / n + 1));
//	cout << "lie: " << lie_ << '\n';
	int hang_;
	if (lie_ % 2 == 1) {
		int sy = rank_ - (lie_ - 1) * n;
		hang_ = sy;
	}
	else {
		int sy = rank_ - (lie_ - 1) * n;
		hang_ = n + 1 - sy;
	}
	cout << lie_ << ' ' << hang_;
	return 0;
}