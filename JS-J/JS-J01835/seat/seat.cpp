#include<bits/stdc++.h>
using namespace std;

int b = 100, n, m;
vector <int> a;

bool s(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		int x = 0;
		cin >> x;
		a.push_back(x);
	}
	b = a[0];
	sort(a.begin(), a.begin() + n * m, s);
	int x = 1, y = 1, cnt = 0;
	while(a[cnt] != b){
		if(y == n && x % 2 == 1 || y == 1 && x % 2 == 0){
			x++;
		}
		else if(x % 2 == 1){
			y++;
		}
		else{
			y--;
		}
		cnt++;
	}
	cout << x << " " << y;
	return 0;
}
