#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int x;
	cin >> x;
	int pos = 1;
	for(int i = 2; i <= n * m; i++){
		int y;
		cin >> y;
		if(y > x) pos++;
	}
	cout << int(ceil(pos * 1.0 / n)) << " ";
	if(int(ceil(pos * 1.0 / n)) % 2 == 1){
		if(pos % n == 0) cout << n;
		else cout << pos % n;
	}else{
		cout << n - pos % n + 1;
	}
	return 0;
}