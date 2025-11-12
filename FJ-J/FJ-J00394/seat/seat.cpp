#include<bits/stdc++.h>
using namespace std;
int cnt = 1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int d;
	cin >> d;
	for (int i = 2; i <= n * m; i++){
		int x;
		cin >> x;
		if (x > d)cnt++;
	}
	int f = cnt / n;
	int p = cnt % n;
	if (f % 2 == 1){
		if (p == 0){
			cout << f << " " << n;
		}
		else{
			cout << f + 1 << " " << n - p + 1;
		}
	}
	else{
		if (p == 0){
			cout << f << " " << 1;
		}
		else{
			cout << f + 1 << " " << p;
		}
	}
	return 0;
}
