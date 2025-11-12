#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int num = 1;
	int a, b;
	cin >> a;
	for(int i = 2; i <= n * m; i++){
		cin >> b;
		if(b > a){
			num++;
		}
	}
	if(num % n == 0){
		cout << num / n << " ";
		if((num / n) % 2 == 0){
			cout << 1;
		}else{
			cout << n;
		}
	}else{
		cout << num / n + 1 << " ";
		if((num / n + 1) % 2 == 0){
			cout << n - num % n + 1;
		}else{
			cout << num % n;
		}
	}
	return 0;
}
