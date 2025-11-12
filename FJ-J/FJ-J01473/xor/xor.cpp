#include <bits/stdc++.h>
#define N 500005
using namespace std;
inline int read(){
	int res = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (f > 0 ? res : -res);
}
int a[N];
int main(){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n = read(), k = read();
	int ans = 0;
	for (int i = 1; i <= n; i++){
		a[i] = read();
	}
	bool f1=1;
	for (int i = 1; i <= n; i++){
		if (a[i] != 1) f1 = 0;
	}
	if (f1){
		int num = 1;
		for (int i = 2; i <= n; i++){
			num = (a[i] ^ num);
			if (num == 0){
				num = 1;
				ans++;
				i++;
			}
		}
		cout << ans << "\n";
		return 0;
	}
	
	
	bool f0 = 1;
	for (int i = 1; i <= n; i++){
		if (a[i] != 1 && a[i] != 0) {
			f0 = 0;
		}
	}
	if (f0) {
		int num = 1;
		if (k == 1) {
			int cnt1 = 0;
			for (int i = 1; i <= n; i++){
				if (a[i] == 1) cnt1++;
			}
			cout << cnt1 << "\n";
			return 0;
		}
		else {
			int cnt0 = 0;
			int x = 0;
			for (int i = 1; i <= n; i++){
				if (a[i] == 0) {
					cnt0++;
					x = 0;
				}
				else {
					if (x == 1) {
						cnt0++;
						x = 0;
					}
					else x++;
				}
			}
			cout << cnt0 << "\n";
			return 0;
		}
	}
	
	
	int num = a[1];
	int last = 1;
	for (int i = 1; i <= n; i++){
		if (a[i] == k) {
			ans++;
//			cout << i <<"\n";
			num = a[i+1];
			last = 1;
			continue;
		}
		if (!last) num = (num ^ a[i]);
		if (last) last = false;
		if (num == k) {
			ans++;
//			cout << i << "\n";
			last = 1;
			num = a[i+1];
		}
	}
	cout << ans << "\n";
	
	return 0;
}
