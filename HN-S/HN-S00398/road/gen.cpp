#include <bits/stdc++.h>
#define rep(i,x,y) for(int i = x; i <= y;i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define int long long
using namespace std;


signed main() {
	
	freopen(".in", "w", stdout);
	srand(time(0));
	int n = rand() % 1000 + 1;
	int m = n - 1 + rand() % 5000 + 1;
	int k = rand() % 10 + 1;
	cout << n << ' ' << m << ' ' << k << '\n';
	rep(i, 2, n) cout << i << ' ' << rand() % (i - 1) + 1 << ' ' << rand() % 100 << '\n';
	rep(i, n,m) cout << rand() % n + 1 << ' ' << rand() % n + 1 << ' ' << rand() % 100 << '\n';
	rep(i, 1,k){
		cout << rand() % 100 + 1<<' ';
		rep(j, 1,n) cout<<rand() % 100 + 1 << ' ';
		cout << '\n';
	}
	return 0;
}

