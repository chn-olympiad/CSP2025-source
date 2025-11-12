#include<iostream>
#include<algorithm>
using namespace std;
int n, m, idx = -1, a[100];

int cmp(int x, int y){
	return x > y;
}

int main(){
	///*
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	//*/
	
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int x = a[1];
	
	sort(a + 1, a + (n * m) + 1, cmp);
	
	for (int i = 1; i <= n*m; i++){
		if (a[i] == x){
			idx = i;
		}
	}
	
	int c = idx / n + (int)(idx % n != 0);
	int r = (idx - 1) % m + 1;
	if (c % 2 == 0) {
		r = n - r;
	}
	
	cout << c << " " << r;
	
	return 0;
}
