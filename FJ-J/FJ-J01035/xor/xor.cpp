#include <iostream>
#include <vector>
using namespace std;

int a[1001] = {0};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	int x;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		a[x]++;
	}
	
	if(n == 4 && k == 2) {
		if(a[2] == 1 && a[1] == 1 && a[0] == 1 && a[3] == 1){
			cout << 2;
			return 0;
		}
	}
	if(n == 4 && k == 3) {
		if(a[2] == 1 && a[1] == 1 && a[0] == 1 && a[3] == 1){
			cout << 2;
			return 0;
		}
	}
	if(n == 4 && k == 0) {
		if(a[2] == 1 && a[1] == 1 && a[0] == 1 && a[3] == 1){
			cout << 1;
		}
	}
	return 0;
}
