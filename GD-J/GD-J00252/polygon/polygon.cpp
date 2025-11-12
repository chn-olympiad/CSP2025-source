#include <iostream>
#include <algorithm>
using namespace std;
int a[10005], q[10005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n <= 3){
		if (n <= 2){
			cout << 0;
			return 0;
		}else if (n == 3){
			int maxn;
			maxn = max({a[1], a[2], a[3]});
			if (a[1] + a[2] + a[3] > maxn * 2){
				cout << 1;
				return 0;
			}else{
				cout << 0;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
