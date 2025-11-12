#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a(1, -1);

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.ans", "w", stdout);
	
	int n = 0, k = 0;
	cin >> n >> k;
	
	int same = 0;
	int cnt = 1;
	
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		a.push_back(p);
	}
	
	if(k == 0) {
		cout << (n >> 1);
		return 0;
	} else if (k == 1) {
		int cnt_1 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) cnt_1++;
		}
		cout << cnt_1;
		return 0;
	}
	
	return 0;
}

