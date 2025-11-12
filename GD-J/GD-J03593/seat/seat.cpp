#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 110;
int a[maxn];

bool cmp(int a,int b) {
	return a > b;
}

signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int tmp = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int op;
	for(int i = 1;i <= n * m;i++) {
		if(a[i] == tmp) {
			op = i;
			break;
		}
	}
	int x,y;
	if(op % n == 0) {
		x = op / n;
		if(x % 2 == 1) cout << x << " " << n;
		else cout << x << " " << 1;
		return 0;
	}
	x = op / n + 1;
	if(x % 2 == 1) {
		y = n - (x * n - op);
	} else {
		y = 1 + (x * n - op);
	}
	cout << x << " " << y;
	return 0;
}
/*
2 2
99 100 97 98
*/

