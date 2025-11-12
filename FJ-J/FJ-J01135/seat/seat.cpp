#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m + 10] = {}, r, ans = 1;
	cin >> r;
	for(int i = 1;i < n * m;i++){
		cin >> a[i];
		if(a[i] > r){
			ans++;
		}
	}
	int c, y;
	c = ans / (n  + 1) + 1;
	if(c % 2 == 1){
		y = ans % (n + 1);
	}else{
		y = n - ans % (n + 1);
	}
	cout << c << " " << y;
	return 0;
}

