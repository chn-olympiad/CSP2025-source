#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], b[105][105], p, q, s = 1;
int cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
		if(i == 1){
			p = a[i];
		}
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == p){
			q = i;
		}
	}
	for(int i = 1;i <= m;i++){
		if(i % 2 == 0){
			s += n - 1;
		}
		for(int j = 1;j <= n;j++){
			if(j == 1 && i % 2 != 0) s = b[j][i - 1] + 1;
			b[j][i] = s;
			if(i % 2 == 0) s--;
			else s++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(q == b[i][j]){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
