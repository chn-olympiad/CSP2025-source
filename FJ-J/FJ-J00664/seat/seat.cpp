#include <bits/stdc++.h>
using namespace std;
int n,m,a,cnt,x,y;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cnt = 1;
	for(int i = 1; i <= n * m; i++) {
		int s;
		cin >> s;
		if(i == 1) a = s;
		else if (s > a) cnt++;
	}
	int g = cnt % n;
	if (g) y = cnt / n + 1;
	else y = cnt / n;
	if(y % 2) {
		if (g) x = g;
		else x = n;
	}else {
		if (g) x = n - g + 1;
		else x = 1;
	}
	cout << y << " " << x << endl;
	return 0;
}

