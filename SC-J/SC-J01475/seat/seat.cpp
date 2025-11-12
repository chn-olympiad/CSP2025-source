#include<bits/stdc++.h>
#define N 10100
#define ll long long
using namespace std;
ll n, m, a[N], t = 1, t1, t2;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for ( int i = 1; i <= n * m; i++ ){
		cin >> a[i];
	}
	for ( int i = 1; i <= n * m; i++ ){
		for ( int j = i + 1; j <= n * m; j++ ){
			if ( a[i] < a[j] ){
				swap(a[i], a[j]);
				if ( i == t ){
					t = j;
				}else if ( j == t ){
					t = i;
				}
			}
		}
	}
	t1 = t / n;
	t2 = t % n;
	if ( t2 != 0 ){
		t1++;
	}
	if ( t1 % 2 == 0 ){
		if ( t2 == 0 ){
			cout << t1 << " " << 1;
		}else{
			cout << t1 << " " << n - t2 + 1;
		}
	}else{
		if ( t2 == 0 ){
			cout << t1 << " " << t;
		}else{
			cout << t1 << " " << t2;
		}
	}
	return 0;
}