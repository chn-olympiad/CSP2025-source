//T2×ùÎ» 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10*10 + 5;
int n, m, mark, c, r, a[MAXN];
bool cmp(int x, int y){
	return x>y;
}int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; ++i){
		cin >> a[i];
	}mark = a[1];
	sort(a+1, a+n*m+1, cmp);
	for (int i=1; i<=n*m; ++i){
		if (a[i] == mark){
			c = ceil(i*1.0/n);
			if (c % 2 == 1){
				if (i % n == 0) r = n;
				else r = i % n;
			}else r = n - i % n + 1;
		}
	}cout << c << " " << r;
	return 0;
}
