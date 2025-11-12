#include <bits/stdc++.h>

using namespace std;

constexpr int N = 15;

pair<int, int> arr[N * N];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	
	sort(arr + 1, arr + n * m + 1, [&] (pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	});
	
	int pointer = 0;
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= m; j++) {
				pointer++;
				if (arr[pointer].second == 1) {
					cout << i << " " << j << "\n";
					exit(0);
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				pointer++;
				if (arr[pointer].second == 1) {
					cout << i << " " << j << "\n";
					exit(0);
				}
			}
		}
	}
	
	return 0;
}
