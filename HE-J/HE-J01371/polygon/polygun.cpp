#include <iostream>
using namespace std;
int n;
int a[114514];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i <= 100; i++) cin >> a[i];
	if(n < 3) cout << 0;
	if(n = 3) {
		if(a[0] + a[1] + a[2] > 2 * max(max(a[0], a[1]), a[2])) cout << 1;
		else cout << 0;
	}
	return 0;
}
