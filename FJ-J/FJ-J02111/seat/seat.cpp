#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int N = 102;
int a[N];
int n, m;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	// n行m列 
	int l = n * m;
	for (int i = 1; i <= l; i++) {
		cin >> a[i];
	}
	pair<int, int> littleR = {a[1], 0};
	sort(a + 1, a + l + 1, greater<int>());
	for (int i = 1; i <= l; i++) {
		if (a[i] == littleR.first) {
			littleR.second = i;
			break;
		}
	}
//	cout << littleR.first << " " << littleR.second << "\n";
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= m; j++) {
				if ((i - 1) * m + j == littleR.second) {
					cout << i << " " << j << "\n";
					goto FLAG;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				if ((i- 1) * m + m - j + 1 == littleR.second) {
					cout << i << " " << j << "\n";
					goto FLAG;
				}
			}
		}
	}
	FLAG:return 0;
}
// 超 级 大 暴 力 ！ ！ ！  

