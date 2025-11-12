#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x;
	cin >> n >> m;
	cin >> x;
	a[1] = x;
	for (int i = 2;i <= n * m;i++){
		cin >> a[i];
	}
	sort (a + 1, a + 1 + m * n);
	for (int i = 1;i <= n * m;i++){
		if (a[i] == x){
			x = m * n - i + 1;
		}
	}
	if (x % m == 0){
		cout << x / m << ' ' << m; 
	}else{
		cout << x / m + 1 << ' ' << x % m; 
	}
	
	return 0;
}