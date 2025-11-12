#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m ;
	for(int i = 1;i <= n * m;i++) {
		cin >> a[i] ;
	}
	
	int tmp = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	
	
	int t;
	for(int i = 1;i <= n * m;i++) {
		if(a[i] == tmp) {
			t = i;
			break;
		}
	}
	
	int m1 = t / n, n1 = t % n;
	if(n1 != 0) m1++;
	cout << m1 << ' ' ;
	if(n1 == 0) n1 = n;
	if(m1 % 2 == 0) {
		cout << n - n1 + 1 ;
	} else cout << n1 ;
	
	return 0;
}
