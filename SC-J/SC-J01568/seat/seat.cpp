#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200];
int c, k;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	c = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == c){
			k = i;
		}
	}
	if(k % n == 0){
		if((k / n) % 2 != 0){
			cout << k / n << " " << n;
		}else{
			cout << k / n << " " << 1;
		}
	}else{
		if((k / n) % 2 != 0){
			cout << k / n + 1 << " " << n - (k % n) + 1;
		}else{
			cout << k / n + 1 << " " << k % n;
		}
	}
	return 0;
}