#include <bits/stdc++.h>	//100

using namespace std;

const int N = 1e1 + 10;

int a[N * N];

bool cmp(int num_a, int num_b) {
	return num_a > num_b;
}

int main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	
	int num = a[1];
	
	sort(a + 1, a + 1 + n * m, cmp);
	
	int idx = -1;
	
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == num) {
			idx = i;
			break;
		}
	}
	
	int tot = 0;
	
	while (idx > n) {
		idx -= n;
		tot ++;
	}
	
	cout << tot + 1 << " ";
	
	if (tot % 2 == 0) {
		cout << idx << "\n";
	} else {
		cout << n - idx + 1 << "\n";
	}

	return 0;
}

