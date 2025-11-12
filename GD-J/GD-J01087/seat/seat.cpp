#include <bits/stdc++.h>
using namespace std;

int a[101];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r, cnt;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int p = a[1];
	for (int i = 1; i < n * m; i++){
		for (int j = 1; j < n * m; j++){
			if (a[j] < a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for (int i = 1; i <= n * m; i++){
		if (a[i] == p)  cnt = i;
	}
	
	if ((int)ceil((double)cnt / n) % 2 == 1){
		c = ceil((double)cnt / n);
		r = cnt - n * (c-1);
	}
	else{
		c = ceil((double)cnt / n);
		r = n - (cnt - n * (c-1)) + 1;
	}
	cout << c << " " << r;
	
	return 0;
} 
