#include"bits/stdc++.h"
using namespace std;
int n, m, sum;
struct student {
	int score, id;
	bool operator<(const student &x)const {
		return score > x.score;
	}
} a[105];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	sum = n*m;
	for (int i = 1; i <= sum; i++)
		cin >> a[i].score, a[i].id = i;
	sort(a + 1, a + 1 + sum);
	int id;
	for (int i = 1; i <= sum; i++)
		if (a[i].id == 1) {
			id = i;
			break;
		}
	int line = (id - 1) / n + 1;
	int row = (line & 1 ? id - (line - 1) * n : n - (id - (line - 1) * n) + 1);
	cout << line << ' ' << row;
	return 0;
}