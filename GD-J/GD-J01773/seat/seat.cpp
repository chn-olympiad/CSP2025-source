#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a(1, 0);

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int flag = 0;
	
	for (int i = 1; i <= n * m; i++) {
		int p;
		cin >> p;
		if (i == 1) flag = p;
		a.push_back(p);
	}

	sort(a.rbegin(), a.rend());
	
	int id = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == flag) {
			id = i;
			break;
		}
		
	}
	int ans_1 = (id / n) + 1;
	int ans_2 = 0;
	if (ans_1 % 2 == 0) {
		ans_2 = n - (id % n);
	} else {
		ans_2 = id % n + 1;
	}
	
	
	cout << ans_1 << ' ' << ans_2;
	
	return 0;
} 
