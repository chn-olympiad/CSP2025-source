#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y) {
	return x > y;
} 
int n,m,a[10005],qq,e;
signed main() {
	freopen("seat.in","r", stdin);
	freopen("seat.out","w", stdout);
	cin >> n >> m;
	int num = n*m;
	for (int i = 1; i <= num; i ++) cin >> a[i];
	qq = a[1];
	sort (a+1,a + num + 1, cmp);
	for (int i = 1; i <= num; i ++) {
		if (a[i] == qq) {e = i;break;}
	}
	int hh = (e / n) + 1, pp = e%n;
	if (pp == 0) {
		pp = n,hh = hh-1;
	}
	
	if (hh % 2 == 1) {
		cout << hh << " " << pp;
	}
	else {
		cout << hh << " " << n-pp+1;
	}
	return 0;
}

