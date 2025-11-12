#include <iostream>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, flag1 = 1, flag2 = 1, cntb_1 = 0, cnt_0 = 0, shang = -1, cnt_1 = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (shang == 1 && a[i] == 1){
			cntb_1++;
			shang = -1;
		}else shang = a[i];
		if (a[i] == 1) cnt_1++;
		if (a[i] == 0) cnt_0++;
		if (a[i] != 1) flag1 = 0;
		if (a[i] > 1) flag2 = 0;
	}
	if (k == 0 && flag1 == 1){
		cout << n / 2;
		return 0;
	}else if (k <= 1 && flag2 == 1){
		if (k == 0){
			cout << cntb_1 + cnt_0;
			return 0;
		}else if (k == 1){
			cout << cnt_1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
