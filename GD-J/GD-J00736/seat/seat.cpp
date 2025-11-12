#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, rscore, pm = 1;
	cin >> n >> m;
	cin >> rscore;
	for(int i = 2; i <= n * m; i++) {
		int x;
		cin >> x;
		if(x > rscore) pm++;
	}
	int l;
	if(pm % n == 0) l = pm / n;
	else l = pm / n + 1;
	int h;
	if(l % 2 == 1) {
		if(pm % n == 0) h = n;
		else h = pm % n;
	} else {
		if(pm % n == 0) h = 1;
		else h = n - pm % n;		
	}
	cout << l << ' ' << h;
	
	return 0;
}
