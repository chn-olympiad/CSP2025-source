#include<iostream>
using namespace std;
int n, k, zero = 0, one = 0, x = 0, y = 0;
int sum = 0;
int a[201000], b[201000];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 0){
			zero++;
			if(x != 0){
				b[y] = x;
				y++;
			}
			x = 0;
		}else if(a[i] == 1){
			one++;
			x++;
		}
	}
	if(x != 0){
		b[y] = x;
	}
	for(int i = 0; i <= y; i++){
//		cout << b[i] <<" ";
		sum += b[i] / 2;
	}
	if(one == n){
		if(k == 1){
			cout << n;
		}else if(k == 0){
			cout << n / 2;
		}
		return 0;
	}
	if(one + zero == n){
		if(k == 1){
			cout << one;
			return 0;
		}else{
			cout << zero + sum;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
