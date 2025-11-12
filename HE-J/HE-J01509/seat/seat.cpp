#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n,m,a[N],k,idd;

bool cmp (int x,int y) {
	return x > y;
}

int main () {

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n * m;i ++) {
		cin >> a[i];
	}
	
	k = a[1];
	
	sort (a + 1,a + n * m + 1,cmp);
	
	for (int i = 1;i <= n * m;i ++) {
		if (a[i] == k) idd = i;
	}
	
	if ((idd / n) % 2 == 0) {
		if (idd % n == 0) cout << idd / n << ' ' << n << '\n';
		else cout << idd / n + 1 << ' ' << idd % n << '\n';
	} else {
		if (idd % n == 0) cout << idd / n << ' ' << n << '\n';
		else cout << idd / n + 1 << ' ' << n - idd % n + 1 << '\n';
	}
	
	return 0;
}
