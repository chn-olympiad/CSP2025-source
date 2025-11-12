#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int a, cnt = 0;
	scanf("%d", &a);
	for(int i = 2; i <= n * m; i ++) {
		int b;
		scanf("%d", &b);
		if(b > a) cnt ++;
	}
	int l = cnt / n + 1;
	if(l & 1) {
		cout << l << " " << cnt % n + 1 << endl;
	}
	else {
		cout << l << " " << n - (cnt % n) << endl; 
	}
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92

*/