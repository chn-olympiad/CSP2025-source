#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int n, m, p, q = 1, c;
int a[1000];
int main(){
	freopen("seat.out", "r", stdin);
	freopen("seat.in", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	} 
	p = a[1];
	sort(a + 1, a + n*m + 1, cmp);
	for(int i = 1; i <= n*m; i++){
		c = i / n;
		if(c < 1 && a[i] == p){
			cout << 1 << " " << i;
		}
		if(c >= 1 && c % 2 != 0 && i % n != 0 && a[i] == p){
			cout << c + 1 << " " << n - (i % n) + 1;
		}
		if(c >= 1 && c % 2 == 0 && i % n != 0 && a[i] == p){
			cout << c + 1 << " " << i % n;
		}
		if(c >= 1 && c % 2 != 0 && i % n == 0 && a[i] == p){
			cout << c << " " << n;
		}
		if(c >= 1 && c % 2 == 0 && i % n == 0 && a[i] == p){
			cout << c  << " " << 1;
		}
	}
	return 0;
} 
