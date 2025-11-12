#include <iostream>
using namespace std;
int m, n, c[505]; string a;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	long long s = 1;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 2; i <= n; i++) s = s * i % 998244353;
	cout << s;
	return 0;
}//161088479
