#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int pos = a[1], cur, num = 2 * n, sum, cnt;
	sort(a + 1, a + n * m + 1, cmp);	
	for (int i = 1; i <= n * m; i++){
		if (a[i] == pos){
			cur = i;
		}
	}
	sum = cur / num;
	cnt = cur % num;
	int nx, ny;
	if (cnt != 0){
		if (cnt <= n){
			cout << sum * 2 + 1 << ' ' << cnt;
		}
		else{
			cout << sum * 2 + 2 << ' ' << n - cnt + n + 1;
		}
	}
	else{
		cout << sum * 2 << ' ' << 1;
	}
	return 0;
} 
