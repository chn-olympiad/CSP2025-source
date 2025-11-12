#include <iostream>
#include <fstream>

using namespace std;

int a[110], n, m, ans, xy, x, y;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n * m; i++){
		cin>>a[i];
	}
	ans = a[1];
	for(int i = (n * m - 1); i >= 1; i--){
		for(int j = 1; j <= i; j++){
			if(a[j] < a[j + 1]){
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
//		for(int i = 1; i <= n * m; i++){
//			cout<<a[i]<<' ';
//		}
//		cout<<endl;
	}
//	for(int i = 1; i <= n * m; i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == ans){
			xy = i;
			break;
		}
	}
//	cout<<xy<<endl;
	if(xy % n == 0){
		x = (xy / n);
	}
	else{
		x = (xy / n) + 1;
	}
	if(x % 2 == 0){
		if(xy % n == 0){
			y = 1;
		}
		else{
			y = n - (xy % n) + 1;
		}
	}
	else{
		y = xy % n;
	}
	if(y == 0)y = n;
	cout<<x<<' '<<y;
	return 0;
}
