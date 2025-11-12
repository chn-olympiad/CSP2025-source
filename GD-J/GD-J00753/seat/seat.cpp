#include<bits/stdc++.h>
using namespace std;

int a[1000];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m; // n是行数，m是列数 
	scanf("%d%d", &n, &m);
	
	// a1是小R的成绩
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	
	int a1 = a[1];
	
	sort(a + 1, a + n*m + 1, cmp);
	
	int idx = 0; 
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == a1) {
			idx = i;
			break;
		}
	}
	
	int k = (idx - 1) / n + 1;
	int p = 0;
	
	if (k % 2 == 0) {
		p = m - idx % m + 1;
	} else {
		p = (idx - 1) % m + 1;
	}
	
	cout << k << " " << p;
	
	return 0;
}
