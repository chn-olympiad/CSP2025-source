#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, t;
int a[N];
int Score;
int x, y;

void calc (int k) {
	y = ceil( 1.0 * k / m );
	
	int tmp = k - ( y - 1 ) * n;
	
	if ( y & 1 )
		x = tmp;
	else
		x = n + 1 - tmp;
	
	return ;
} 

bool comp (int x, int y) {
	return x > y;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	t = n * m;
	
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}
	
	Score = a[1];
	
	sort( a + 1 , a + t + 1 );
	
	int pos = lower_bound( a + 1 , a + t + 1 , Score ) - a;
	pos = t - pos + 1;
	
	calc( pos );
	
	cout << y << ' ' << x;
	return 0;
} 
