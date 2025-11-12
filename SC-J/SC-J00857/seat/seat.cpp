//100pts
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int num = 0;
	int a = v[0];
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = (i % 2 == 0 ? n : 1); (i % 2 == 0 ? (j >= 1) : (j <= n)); j += (i % 2 == 0 ? -1 : 1)) {
			if (v[num] == a) {
				cout << i << " " << j << '\n';
				return 0;
			}
			num++;
		}
	}
}
//rp++