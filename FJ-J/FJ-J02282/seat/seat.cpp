#include<bits/stdc++.h>
using namespace std;
int n, m, r, a[101], xr, cnt = 1;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int r = n * m;
	for(int i = 1; i <= r; i ++){
		cin >> a[i];
	}
	xr = a[1];
	sort(a + 1, a + 1 + r, cmp);
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			if(a[cnt ++] == xr){
				if(i % 2) cout << i << ' ' << j;
				else cout << i << ' ' << m - j + 1;
				return 0;
			}
		}
	}
	return 0;
}
