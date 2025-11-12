#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n , m;
int a[N];
int c , d;

bool cmp(int x , int y) {
	return x > y;
}

int main() {
	
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	c = a[1];
	
	sort(a + 1 , a + n * m + 1 , cmp);
	
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == c) d = i;
	}
	
	if(d % n == 0) cout << d / n;
	else cout << d / n + 1;
	
	if((d / n) % 2 == 0) cout << " " << 1;
	else cout << " " << n;
	
	return 0;
}

// rp ++
