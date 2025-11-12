#include <bits/stdc++.h>
using namespace std;
int grade[10005];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cnt = 1;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) {
		cin >> grade[i];
		if(i != 1 && grade[i] > grade[1]) cnt++;
	}
	int x = (cnt-1) / n + 1, y;
	int tmp = cnt % n;
	if(tmp == 0) tmp = n;
	if(x % 2 == 1) {
		y = tmp;
	} else {
		y = n-tmp+1;
	}
	cout << x << ' ' << y;
	return 0;
}

